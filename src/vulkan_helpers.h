#pragma once

#include <vulkan/vulkan.hpp>

#include <vector>

namespace vuh
{

      inline auto div_up(uint32_t x, uint32_t y) { return (x + y - 1u) / y; }
      inline auto div_up(uint64_t x, uint64_t y) { return (x + y - 1u) / y; }

      VKAPI_ATTR VkBool32 VKAPI_CALL debugReporter(
          VkDebugReportFlagsEXT, VkDebugReportObjectTypeEXT, uint64_t, size_t, int32_t, const char *pLayerPrefix, const char *pMessage, void * /*pUserData*/
      );

      auto readShaderSrc(const char *filename) -> std::vector<char>;

      auto loadShader(const vk::Device &device, const char *filename, vk::ShaderModuleCreateFlags flags = vk::ShaderModuleCreateFlags()) -> vk::ShaderModule;

      auto enabledInstanceExtensions(const std::vector<const char *> &extensions) -> std::vector<const char *>;

      auto enabledLayers(const std::vector<const char *> &layers) -> std::vector<const char *>;

      auto registerValidationReporter(const vk::Instance &instance, PFN_vkDebugReportCallbackEXT reporter) -> VkDebugReportCallbackEXT;

      auto getComputeQueueFamilyId(const vk::PhysicalDevice &physicalDevice) -> uint32_t;

      auto createDevice(const vk::PhysicalDevice &physicalDevice, const std::vector<const char *> &layers, const std::vector<const char *> &extensions, uint32_t queueFamilyID) -> vk::Device;

      auto createBuffer(const vk::Device &device, vk::DeviceSize bufSize, vk::BufferUsageFlags usage = vk::BufferUsageFlagBits::eStorageBuffer) -> vk::Buffer;

      auto selectMemory(const vk::PhysicalDevice &physDev, const vk::Device &device, const vk::Buffer &buf, const vk::MemoryPropertyFlags properties ///< desired memory properties
                        ) -> uint32_t;

      auto allocMemory(const vk::PhysicalDevice &physDev, const vk::Device &device, const vk::Buffer &buf, uint32_t memory_id) -> vk::DeviceMemory;

      auto copyBuf(const vk::Buffer &src, vk::Buffer &dst, const vk::DeviceSize size, const vk::Device &device, const vk::PhysicalDevice &physDev) -> void;

} // namespace vuh
