#pragma once
#include <algorithm>
#include <chrono>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

enum class AttackType {
    None,
    Swing,
    Stab
};

struct WeaponProfile {
    WeaponType type;
    float minSpeed;
    float cooldown;
    float stabDotThreshold;
    float comboTimeWindow;
    float chargeTimeRequired;
};

class WeaponMotionAnalyser {
public:
    explicit WeaponMotionAnalyser(WeaponType type) : weaponType(type), profile(GetProfile(type)), lastAttackTime(std::chrono::steady_clock::now()) {}

    void Update(const glm::vec3& linearVelocity, const glm::quat& orientation) {
        using namespace std::chrono;

        auto now = high_resolution_clock::now();
        float deltaTime = duration<float>(now - lastUpdate).count();
        lastUpdate = now;

        float speed = glm::length(linearVelocity);
        glm::vec3 forward = orientation * glm::vec3(0, 0, -1);
        float directionalDot = glm::dot(glm::normalize(linearVelocity), glm::normalize(forward));

        // Cooldown check
        float timeSinceLast = duration<float>(now - lastAttackTime).count();
        if (timeSinceLast < profile.cooldown) {
            hitboxActive = false;
            return;
        }

        // Determine attack type
        if (directionalDot > profile.stabDotThreshold && speed > profile.minSpeed) {
            attackType = AttackType::Stab;
        }
        else if (speed > profile.minSpeed) {
            attackType = AttackType::Swing;
        }
        else {
            attackType = AttackType::None;
            hitboxActive = false;
            return;
        }

        // Combo logic for SmallSword
        if (weaponType == WeaponType::SmallSword && timeSinceLast < profile.comboTimeWindow) {
            comboCount++;
            comboDamageMultiplier = std::min(1.0f + comboCount * 0.2f, 2.0f);
        }
        else {
            comboCount = 0;
            comboDamageMultiplier = 1.0f;
        }

        // Charge slam logic for LargeSword
        if (weaponType == WeaponType::LargeSword) {
            if (deltaTime > 0 && speed < 0.5f) {
                accumulatedChargeTime += deltaTime;
            }
            else if (attackType == AttackType::Swing && accumulatedChargeTime > profile.chargeTimeRequired) {
                chargeSlamActive = true;
                accumulatedChargeTime = 0.0f;
            }
            else {
                chargeSlamActive = false;
                accumulatedChargeTime = 0.0f;
            }
        }

        // SPEAR: Directional precision scaling
        if (weaponType == WeaponType::Spear && attackType == AttackType::Stab) {
            float bonus = std::clamp((directionalDot - profile.stabDotThreshold) / (1.0f - profile.stabDotThreshold), 0.0f, 1.0f);
            damage = std::clamp(speed / 3.0f, 0.0f, 1.0f) * (0.8f + bonus * 0.5f);
            impulse = damage * 1.2f;
        }
        else {
            damage = std::clamp(speed / 5.0f, 0.0f, 1.0f);
            impulse = damage;
        }

        // Apply charge slam bonus
        if (chargeSlamActive) {
            damage *= 1.8f;
            impulse *= 2.0f;
        }

        // Apply combo scaling
        damage *= comboDamageMultiplier;

        hitboxActive = true;
        lastAttackTime = now;
    }

    bool IsHitboxActive() const { return hitboxActive; }
    float GetDamage() const { return damage; }
    float GetImpulse() const { return impulse; }
    AttackType GetAttackType() const { return attackType; }
    WeaponType GetWeaponType() const { return weaponType; }

private:
    WeaponType weaponType;
    WeaponProfile profile;

    bool hitboxActive = false;
    AttackType attackType = AttackType::None;
    float damage = 0.0f;
    float impulse = 0.0f;

    int comboCount = 0;
    float comboDamageMultiplier = 1.0f;

    float accumulatedChargeTime = 0.0f;
    bool chargeSlamActive = false;

    std::chrono::high_resolution_clock::time_point lastUpdate = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock::time_point lastAttackTime;

    WeaponProfile GetProfile(WeaponType type) {
        switch (type) {
            case WeaponType::Spear:
                return { type, 1.0f, 0.3f, 0.85f, 0.5f, 0.0f };
            case WeaponType::SmallSword:
                return { type, 1.2f, 0.15f, 0.6f, 0.4f, 0.0f };
            case WeaponType::LargeSword:
                return { type, 1.8f, 0.6f, 0.5f, 0.7f, 0.3f };
            case WeaponType::UnknownWeapon:
            default:
                return { type, 1.5f, 0.3f, 0.7f, 0.5f, 0.0f };
        }
    }
};
