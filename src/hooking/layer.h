#pragma once

namespace VRLayer {
    class VkInstanceOverrides {
    public:
        static VkResult CreateInstance(PFN_vkCreateInstance createInstanceFunc, const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance);
        static void DestroyInstance(const vkroots::VkInstanceDispatch* pDispatch, VkInstance instance, const VkAllocationCallbacks* pAllocator);

        static VkResult EnumeratePhysicalDevices(const vkroots::VkInstanceDispatch* pDispatch, VkInstance instance, uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices);
        static void GetPhysicalDeviceProperties(const vkroots::VkInstanceDispatch* pDispatch, VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties);
        static void GetPhysicalDeviceQueueFamilyProperties(const vkroots::VkInstanceDispatch* pDispatch, VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties* pQueueFamilyProperties);

        static void GetPhysicalDeviceMemoryProperties(const vkroots::VkInstanceDispatch* pDispatch, VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties* pMemoryProperties);
        static VkResult GetPhysicalDeviceSurfaceCapabilitiesKHR(const vkroots::VkInstanceDispatch* pDispatch, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities);
        static VkResult GetPhysicalDeviceSurfaceFormatsKHR(const vkroots::VkInstanceDispatch* pDispatch, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats);
        static VkResult GetPhysicalDeviceSurfacePresentModesKHR(const vkroots::VkInstanceDispatch* pDispatch, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes);
        static void DestroySurfaceKHR(const vkroots::VkInstanceDispatch* pDispatch, VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator);

        static VkResult CreateDevice(const vkroots::VkInstanceDispatch* pDispatch, VkPhysicalDevice gpu, const VkDeviceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDevice* pDevice);
    };

    class VkPhysicalDeviceOverrides {
    public:
    };

    class VkDeviceOverrides {
    public:
        static void DestroyDevice(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkAllocationCallbacks* pAllocator);

        // Overrides used for finding framebuffer
        static VkResult CreateImage(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage);
        static void DestroyImage(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator);
        static void CmdClearColorImage(const vkroots::VkDeviceDispatch* pDispatch, VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges);
        static void CmdClearDepthStencilImage(const vkroots::VkDeviceDispatch* pDispatch, VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges);
        static VkResult QueuePresentKHR(const vkroots::VkDeviceDispatch* pDispatch, VkQueue queue, const VkPresentInfoKHR* pPresentInfo);

        // overrides for imgui overlay
        static VkResult AllocateCommandBuffers(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers);
        static VkResult AllocateDescriptorSets(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets);
        static VkResult AllocateMemory(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory);
        static VkResult BeginCommandBuffer(const vkroots::VkDeviceDispatch* pDispatch, VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo);
        static VkResult BindBufferMemory(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset);
        static VkResult BindImageMemory(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset);
        static void CmdBindDescriptorSets(const vkroots::VkDeviceDispatch* pDispatch, VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets);
        static void CmdBindIndexBuffer(const vkroots::VkDeviceDispatch* pDispatch, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType);
        static void CmdBindPipeline(const vkroots::VkDeviceDispatch* pDispatch, VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline);
        static void CmdBindVertexBuffers(const vkroots::VkDeviceDispatch* pDispatch, VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets);
        static void CmdCopyBufferToImage(const vkroots::VkDeviceDispatch* pDispatch, VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions);
        static void CmdDrawIndexed(const vkroots::VkDeviceDispatch* pDispatch, VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance);
        static void CmdPipelineBarrier(const vkroots::VkDeviceDispatch* pDispatch, VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);
        static void CmdPushConstants(const vkroots::VkDeviceDispatch* pDispatch, VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues);
        static void CmdSetScissor(const vkroots::VkDeviceDispatch* pDispatch, VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors);
        static void CmdSetViewport(const vkroots::VkDeviceDispatch* pDispatch, VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports);
        static VkResult CreateBuffer(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer);
        static VkResult CreateCommandPool(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool);
        static VkResult CreateDescriptorPool(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool);
        static VkResult CreateDescriptorSetLayout(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout);
        static VkResult CreateFence(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence);
        static VkResult CreateFramebuffer(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer);
        static VkResult CreateGraphicsPipelines(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
        static VkResult CreateImageView(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView);
        static VkResult CreatePipelineLayout(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout);
        static VkResult CreateRenderPass(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);
        static VkResult CreateSampler(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler);
        static VkResult CreateShaderModule(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule);
        static void DestroyBuffer(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator);
        static void DestroyCommandPool(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator);
        static void DestroyDescriptorPool(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator);
        static void DestroyDescriptorSetLayout(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator);
        static void DestroyFence(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator);
        static void DestroyFramebuffer(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator);
        static void DestroyImageView(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator);
        static void DestroyPipeline(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator);
        static void DestroyPipelineLayout(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator);
        static void DestroyRenderPass(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator);
        static void DestroySampler(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator);
        static void DestroyShaderModule(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator);
        static void DestroySwapchainKHR(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator);
        static VkResult DeviceWaitIdle(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device);
        static VkResult EndCommandBuffer(const vkroots::VkDeviceDispatch* pDispatch, VkCommandBuffer commandBuffer);
        static VkResult FlushMappedMemoryRanges(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges);
        static void FreeCommandBuffers(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers);
        static VkResult FreeDescriptorSets(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets);
        static void FreeMemory(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator);
        static void GetBufferMemoryRequirements(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements);
        static void GetImageMemoryRequirements(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements);
        static VkResult GetSwapchainImagesKHR(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages);
        static VkResult MapMemory(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData);
        static VkResult QueueWaitIdle(const vkroots::VkDeviceDispatch* pDispatch, VkQueue queue);
        static VkResult ResetCommandPool(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags);
        static void UnmapMemory(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkDeviceMemory memory);
        static void UpdateDescriptorSets(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies);

        // frame manager
        static VkResult CreateSwapchainKHR(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain);
        static VkResult CreateSemaphore(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore);
        static void DestroySemaphore(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator);
        static VkResult QueueSubmit(const vkroots::VkDeviceDispatch* pDispatch, VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence);
    };
}