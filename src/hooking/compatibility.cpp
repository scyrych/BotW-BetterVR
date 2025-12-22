#include "instance.h"
#include "layer.h"


// Instance overrides
void VRLayer::VkInstanceOverrides::GetPhysicalDeviceMemoryProperties(const vkroots::VkInstanceDispatch* pDispatch, VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties* pMemoryProperties) {
    pDispatch->GetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties);
}

VkResult VRLayer::VkInstanceOverrides::GetPhysicalDeviceSurfaceCapabilitiesKHR(const vkroots::VkInstanceDispatch* pDispatch, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities) {
    return pDispatch->GetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, pSurfaceCapabilities);
}

VkResult VRLayer::VkInstanceOverrides::GetPhysicalDeviceSurfaceFormatsKHR(const vkroots::VkInstanceDispatch* pDispatch, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats) {
    return pDispatch->GetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);
}

VkResult VRLayer::VkInstanceOverrides::GetPhysicalDeviceSurfacePresentModesKHR(const vkroots::VkInstanceDispatch* pDispatch, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes) {
    return pDispatch->GetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, pPresentModeCount, pPresentModes);
}

void VRLayer::VkInstanceOverrides::DestroySurfaceKHR(const vkroots::VkInstanceDispatch* pDispatch, VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator) {
    pDispatch->DestroySurfaceKHR(instance, surface, pAllocator);
}

// Device overrides
VkResult VRLayer::VkDeviceOverrides::AllocateCommandBuffers(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers) {
    return pDispatch->AllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);
}

VkResult VRLayer::VkDeviceOverrides::AllocateDescriptorSets(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets) {
    return pDispatch->AllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets);
}

VkResult VRLayer::VkDeviceOverrides::AllocateMemory(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory) {
    return pDispatch->AllocateMemory(device, pAllocateInfo, pAllocator, pMemory);
}

VkResult VRLayer::VkDeviceOverrides::BeginCommandBuffer(const vkroots::VkDeviceDispatch* pDispatch, VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo) {
    return pDispatch->BeginCommandBuffer(commandBuffer, pBeginInfo);
}

VkResult VRLayer::VkDeviceOverrides::BindBufferMemory(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset) {
    return pDispatch->BindBufferMemory(device, buffer, memory, memoryOffset);
}

VkResult VRLayer::VkDeviceOverrides::BindImageMemory(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset) {
    return pDispatch->BindImageMemory(device, image, memory, memoryOffset);
}

void VRLayer::VkDeviceOverrides::CmdBindDescriptorSets(const vkroots::VkDeviceDispatch* pDispatch, VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets) {
    pDispatch->CmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
}

void VRLayer::VkDeviceOverrides::CmdBindIndexBuffer(const vkroots::VkDeviceDispatch* pDispatch, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType) {
    pDispatch->CmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
}

void VRLayer::VkDeviceOverrides::CmdBindPipeline(const vkroots::VkDeviceDispatch* pDispatch, VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) {
    pDispatch->CmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
}

void VRLayer::VkDeviceOverrides::CmdBindVertexBuffers(const vkroots::VkDeviceDispatch* pDispatch, VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets) {
    pDispatch->CmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
}

void VRLayer::VkDeviceOverrides::CmdCopyBufferToImage(const vkroots::VkDeviceDispatch* pDispatch, VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions) {
    pDispatch->CmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
}

void VRLayer::VkDeviceOverrides::CmdDrawIndexed(const vkroots::VkDeviceDispatch* pDispatch, VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) {
    pDispatch->CmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}

void VRLayer::VkDeviceOverrides::CmdPipelineBarrier(const vkroots::VkDeviceDispatch* pDispatch, VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) {
    pDispatch->CmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}

void VRLayer::VkDeviceOverrides::CmdPushConstants(const vkroots::VkDeviceDispatch* pDispatch, VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues) {
    pDispatch->CmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
}

void VRLayer::VkDeviceOverrides::CmdSetScissor(const vkroots::VkDeviceDispatch* pDispatch, VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors) {
    pDispatch->CmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
}

void VRLayer::VkDeviceOverrides::CmdSetViewport(const vkroots::VkDeviceDispatch* pDispatch, VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports) {
    pDispatch->CmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
}

VkResult VRLayer::VkDeviceOverrides::CreateBuffer(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer) {
    return pDispatch->CreateBuffer(device, pCreateInfo, pAllocator, pBuffer);
}

VkResult VRLayer::VkDeviceOverrides::CreateCommandPool(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool) {
    return pDispatch->CreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);
}

VkResult VRLayer::VkDeviceOverrides::CreateDescriptorPool(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool) {
    return pDispatch->CreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);
}

VkResult VRLayer::VkDeviceOverrides::CreateDescriptorSetLayout(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout) {
    return pDispatch->CreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout);
}

VkResult VRLayer::VkDeviceOverrides::CreateFence(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) {
    return pDispatch->CreateFence(device, pCreateInfo, pAllocator, pFence);
}

VkResult VRLayer::VkDeviceOverrides::CreateFramebuffer(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer) {
    return pDispatch->CreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);
}

VkResult VRLayer::VkDeviceOverrides::CreateGraphicsPipelines(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
    return pDispatch->CreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
}

VkResult VRLayer::VkDeviceOverrides::CreateImageView(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView) {
    return pDispatch->CreateImageView(device, pCreateInfo, pAllocator, pView);
}

VkResult VRLayer::VkDeviceOverrides::CreatePipelineLayout(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout) {
    return pDispatch->CreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout);
}

VkResult VRLayer::VkDeviceOverrides::CreateRenderPass(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) {
    return pDispatch->CreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);
}

VkResult VRLayer::VkDeviceOverrides::CreateSampler(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler) {
    return pDispatch->CreateSampler(device, pCreateInfo, pAllocator, pSampler);
}

VkResult VRLayer::VkDeviceOverrides::CreateShaderModule(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule) {
    return pDispatch->CreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule);
}

void VRLayer::VkDeviceOverrides::DestroyBuffer(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator) {
    pDispatch->DestroyBuffer(device, buffer, pAllocator);
}

void VRLayer::VkDeviceOverrides::DestroyCommandPool(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator) {
    pDispatch->DestroyCommandPool(device, commandPool, pAllocator);
}

void VRLayer::VkDeviceOverrides::DestroyDescriptorPool(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator) {
    pDispatch->DestroyDescriptorPool(device, descriptorPool, pAllocator);
}

void VRLayer::VkDeviceOverrides::DestroyDescriptorSetLayout(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator) {
    pDispatch->DestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);
}

void VRLayer::VkDeviceOverrides::DestroyFence(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator) {
    pDispatch->DestroyFence(device, fence, pAllocator);
}

void VRLayer::VkDeviceOverrides::DestroyFramebuffer(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator) {
    pDispatch->DestroyFramebuffer(device, framebuffer, pAllocator);
}

void VRLayer::VkDeviceOverrides::DestroyImageView(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator) {
    pDispatch->DestroyImageView(device, imageView, pAllocator);
}

void VRLayer::VkDeviceOverrides::DestroyPipeline(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator) {
    pDispatch->DestroyPipeline(device, pipeline, pAllocator);
}

void VRLayer::VkDeviceOverrides::DestroyPipelineLayout(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator) {
    pDispatch->DestroyPipelineLayout(device, pipelineLayout, pAllocator);
}

void VRLayer::VkDeviceOverrides::DestroyRenderPass(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator) {
    pDispatch->DestroyRenderPass(device, renderPass, pAllocator);
}

void VRLayer::VkDeviceOverrides::DestroySampler(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator) {
    pDispatch->DestroySampler(device, sampler, pAllocator);
}

void VRLayer::VkDeviceOverrides::DestroyShaderModule(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator) {
    pDispatch->DestroyShaderModule(device, shaderModule, pAllocator);
}

void VRLayer::VkDeviceOverrides::DestroySwapchainKHR(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator) {
    pDispatch->DestroySwapchainKHR(device, swapchain, pAllocator);
}

VkResult VRLayer::VkDeviceOverrides::DeviceWaitIdle(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device) {
    return pDispatch->DeviceWaitIdle(device);
}

VkResult VRLayer::VkDeviceOverrides::EndCommandBuffer(const vkroots::VkDeviceDispatch* pDispatch, VkCommandBuffer commandBuffer) {
    return pDispatch->EndCommandBuffer(commandBuffer);
}

VkResult VRLayer::VkDeviceOverrides::FlushMappedMemoryRanges(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges) {
    return pDispatch->FlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
}

void VRLayer::VkDeviceOverrides::FreeCommandBuffers(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) {
    pDispatch->FreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);
}

VkResult VRLayer::VkDeviceOverrides::FreeDescriptorSets(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets) {
    return pDispatch->FreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets);
}

void VRLayer::VkDeviceOverrides::FreeMemory(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator) {
    pDispatch->FreeMemory(device, memory, pAllocator);
}

void VRLayer::VkDeviceOverrides::GetBufferMemoryRequirements(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements) {
    pDispatch->GetBufferMemoryRequirements(device, buffer, pMemoryRequirements);
}

void VRLayer::VkDeviceOverrides::GetImageMemoryRequirements(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements) {
    pDispatch->GetImageMemoryRequirements(device, image, pMemoryRequirements);
}

VkResult VRLayer::VkDeviceOverrides::GetSwapchainImagesKHR(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages) {
    return pDispatch->GetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages);
}

VkResult VRLayer::VkDeviceOverrides::MapMemory(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData) {
    return pDispatch->MapMemory(device, memory, offset, size, flags, ppData);
}

VkResult VRLayer::VkDeviceOverrides::QueueWaitIdle(const vkroots::VkDeviceDispatch* pDispatch, VkQueue queue) {
    return pDispatch->QueueWaitIdle(queue);
}

VkResult VRLayer::VkDeviceOverrides::ResetCommandPool(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags) {
    return pDispatch->ResetCommandPool(device, commandPool, flags);
}

void VRLayer::VkDeviceOverrides::UnmapMemory(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, VkDeviceMemory memory) {
    pDispatch->UnmapMemory(device, memory);
}

void VRLayer::VkDeviceOverrides::UpdateDescriptorSets(const vkroots::VkDeviceDispatch* pDispatch, VkDevice device, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies) {
    pDispatch->UpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
}
