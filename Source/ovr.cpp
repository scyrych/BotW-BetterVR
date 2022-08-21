#include "layer.h"

std::list<VkInstance> oculusInstances;
std::list<VkDevice> oculusDevices;

// Original functions
PFN_vkCreateInstance ovr_CreateInstance = nullptr;
PFN_vkCreateDevice ovr_CreateDevice = nullptr;
PFN_vkDestroyInstance ovr_DestroyInstance = nullptr;
PFN_vkDestroyDevice ovr_DestroyDevice = nullptr;
PFN_vkGetInstanceProcAddr ovr_GetInstanceProcAddr = nullptr;
PFN_vkGetDeviceProcAddr ovr_GetDeviceProcAddr = nullptr;

PFN_vkEnumeratePhysicalDevices ovr_EnumeratePhysicalDevices = nullptr;

// External variables
extern PFN_vkGetInstanceProcAddr saved_GetInstanceProcAddr;
extern PFN_vkGetDeviceProcAddr saved_GetDeviceProcAddr;

// Resolve macros
#define FUNC_LOGGING_LEVEL 2

#if FUNC_LOGGING_LEVEL == 2
//#define LOG_FUNC_RESOLVE(resolveFuncType, resolveFunc, object, name) \
//logPrint(std::format("[GetProcAddr] Using {}: vkGet*ProcAddr(object={}, name={}) returned {}", resolveFuncType, (void*)object, name, (void*)resolveFunc(object, name));\
//resolveFunc(object, name);
//
//#define LOG_ERROR_FUNC_RESOLVE(resolveFuncType, resolveFunc, object, name) \
//if (resolveFunc(object, name) == nullptr) logPrint(std::format("[GetProcAddr] Failed using {}: vkGet*ProcAddr(object={}, name={}) returned {}", resolveFuncType, (void*)object, name, (void*)resolveFunc(object, name));\
//resolveFunc(object, name);

#define logDebugPrintAddr(func) logPrint(func);
#else
#define LOG_FUNC_RESOLVE(func, funcName) resolveFunc(object, name);
#define LOG_ERROR_FUNC_RESOLVE(func, funcName) resolveFunc(object, name);
#define logDebugPrintAddr(func) {}
#endif

#define HOOK_OCULUS_FUNC(func, origFuncPtr) if(!strcmp(pName, "vk" #func)) {\
	logPrint(std::format("[INFO] Hooked {}, original = {}", pName, (void*)origFuncPtr));\
	ovr_##func = (PFN_vk##func)origFuncPtr;\
	return (PFN_vkVoidFunction)&OculusVRHook_##func;\
}

VkInstance topInstance = VK_NULL_HANDLE;


std::vector<VkPhysicalDevice> physicalDevices = {};
void OculusVRHook_initialize(VkInstanceCreateInfo *createInfo) {
	logPrint("Initialized OculusVR workaround!");
	SetEnvironmentVariableA("VK_INSTANCE_LAYERS", NULL);
	//SetEnvironmentVariableA("DISABLE_RTSS_LAYER", "1");
	//SetEnvironmentVariableA("DISABLE_VULKAN_OBS_CAPTURE", "1");

	vulkanModule = LoadLibraryA("vulkan-1.dll");
	PFN_vkGetInstanceProcAddr top_InstanceProcAddr = reinterpret_cast<PFN_vkGetInstanceProcAddr>(GetProcAddress(reinterpret_cast<HMODULE>(vulkanModule), "vkGetInstanceProcAddr"));

	PFN_vkCreateInstance pfn_createInstance = (PFN_vkCreateInstance)top_InstanceProcAddr(NULL, "vkCreateInstance");
	PFN_vkGetInstanceProcAddr pfn_instanceProcAddr = (PFN_vkGetInstanceProcAddr)top_InstanceProcAddr(NULL, "vkGetInstanceProcAddr");

	pfn_createInstance(createInfo, nullptr, &topInstance);
	PFN_vkEnumeratePhysicalDevices enumPhysicalDevices = (PFN_vkEnumeratePhysicalDevices)pfn_instanceProcAddr(topInstance, "vkEnumeratePhysicalDevices");
	
	uint32_t physicalDeviceCount = 0;
	enumPhysicalDevices(topInstance, &physicalDeviceCount, nullptr);
	physicalDevices.resize(physicalDeviceCount);
	enumPhysicalDevices(topInstance, &physicalDeviceCount, physicalDevices.data());
	logPrint(std::format("[DEBUG] INITIALIZE PHYSICAL DEVICES: TopInstance = {}, *count = {}", (void*)topInstance, physicalDeviceCount));
	for (uint32_t i = 0; i < physicalDeviceCount; i++) {
		logPrint(std::format(" - {}", (void*)physicalDevices[i]));
	}
}

VkResult VKAPI_CALL OculusVRHook_CreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance) {
	VkResult result = ovr_CreateInstance(pCreateInfo, pAllocator, pInstance);
	oculusInstances.emplace_back(*pInstance);
	logPrint(std::format("Created new OculusVR instance {} with these extensions:", (void*)*pInstance));
	for (uint32_t i = 0; i < pCreateInfo->enabledExtensionCount; i++) {
		logPrint(std::format(" - {}", pCreateInfo->ppEnabledExtensionNames[i]));
	}
	return VK_SUCCESS;
}

VkResult VKAPI_CALL OculusVRHook_CreateDevice(VkPhysicalDevice gpu, const VkDeviceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDevice* pDevice) {
	VkResult result = ovr_CreateDevice(physicalDevices[0], pCreateInfo, pAllocator, pDevice);
	oculusDevices.emplace_back(*pDevice);
	logPrint(std::format("Created new OculusVR device {} with these extensions:", (void*)*pDevice));
	for (uint32_t i = 0; i < pCreateInfo->enabledExtensionCount; i++) {
		logPrint(std::format(" - {}", pCreateInfo->ppEnabledExtensionNames[i]));
	}
	return result;
}

void VKAPI_CALL OculusVRHook_DestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator) {
	logPrint(std::format("Destroyed SteamVR instance {}", (void*)instance));
	ovr_DestroyInstance(instance, pAllocator);
	oculusInstances.remove(instance);
}

void VKAPI_CALL OculusVRHook_DestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator) {
	ovr_DestroyDevice(device, pAllocator);
	oculusDevices.remove(device);
	logPrint(std::format("Destroyed SteamVR device {}", (void*)device));
}

VkResult VKAPI_CALL OculusVRHook_EnumeratePhysicalDevices(VkInstance instance, uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices) {
	VkResult result = ovr_EnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices);
	logPrint(std::format("Enumerated {} physical devices in SteamVR with this instance {}", (uint32_t)*pPhysicalDeviceCount, (void*)instance));
	if (pPhysicalDevices != nullptr) {
		for (uint32_t i = 0; i < *pPhysicalDeviceCount; i++) {
			logPrint(std::format(" - {}", (void*)pPhysicalDevices[i]));
		}
	}
	return result;
}

PFN_vkVoidFunction VKAPI_CALL OculusVRHook_GetInstanceProcAddr(VkInstance instance, const char* pName) {
	PFN_vkGetInstanceProcAddr top_InstanceProcAddr = reinterpret_cast<PFN_vkGetInstanceProcAddr>(GetProcAddress(reinterpret_cast<HMODULE>(vulkanModule), "vkGetInstanceProcAddr"));

	// Capture TopInstance by waiting till the hooked CreateInstance gets used, which it'll try to use next time!
	if (instance != nullptr && !oculusInstances.empty() && topVkInstance == nullptr) {
		topVkInstance = instance;
		logDebugPrintAddr(std::format("[DEBUG] Found top level instance {} from created SteamVR instance {}!", (void*)topVkInstance, (void*)oculusInstances.front()));
	}

	HOOK_OCULUS_FUNC(CreateInstance, saved_GetInstanceProcAddr(instance, pName));
	HOOK_OCULUS_FUNC(CreateDevice, top_InstanceProcAddr(instance, pName));
	HOOK_OCULUS_FUNC(DestroyInstance, saved_GetInstanceProcAddr(instance, pName));
	HOOK_OCULUS_FUNC(DestroyDevice, saved_GetInstanceProcAddr(instance, pName));

	return saved_GetInstanceProcAddr(instance, pName);
}

// todo: don't think this is used
PFN_vkVoidFunction VKAPI_CALL OculusVRHook_GetDeviceProcAddr(VkDevice device, const char* pName) {
	PFN_vkGetDeviceProcAddr top_DeviceProcAddr = reinterpret_cast<PFN_vkGetDeviceProcAddr>(GetProcAddress(reinterpret_cast<HMODULE>(vulkanModule), "vkGetDeviceProcAddr"));

	return top_DeviceProcAddr(device, pName);
}
