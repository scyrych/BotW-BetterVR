[BetterVR_UpdateSettings_V208]
moduleMatches = 0x6267BFD0

.origin = codecave


data_settingsOffset:
ModeSetting:
.int $mode
EyeSeparationSetting:
.float $eyeSeparation
HeadPositionSensitivitySetting:
.float $headPositionSensitivity
HeightPositionOffsetSetting:
.float $heightPositionOffset
HUDScaleSetting:
.float $hudScale
MenuScaleSetting:
.float $menuScale


vr_updateSettings:
li r4, -1 ; Execute the instruction that got replaced

lis r5, data_settingsOffset@ha
addi r5, r5, data_settingsOffset@l
b import.coreinit.hook_UpdateSettings

0x031FAAF0 = bla vr_updateSettings
