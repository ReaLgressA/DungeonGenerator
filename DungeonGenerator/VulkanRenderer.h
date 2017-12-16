#pragma once
#include "Renderer.h"
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>

class VulkanRenderer :
    public Renderer {
public:
    VulkanRenderer();
    ~VulkanRenderer();
    void initialize(int wWidth, int wHeight, char* title) override;
    void renderLoop() override;
    void cleanup() override;
private:
   VkInstance instance;
   VkDebugReportCallbackEXT callback;
   GLFWwindow *window = nullptr;
   VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
   VkDevice device;
   const std::vector<const char*> validationLayers = {
       "VK_LAYER_LUNARG_standard_validation"
   };
#ifdef NDEBUG
   const bool enableValidationLayers = false;
#else
   const bool enableValidationLayers = true;
#endif

   void initWindow(int width, int height, char *title);
   void createVkInstance();
   bool checkValidationLayerSupport();
   void setupDebugCallback();
   VkResult CreateDebugReportCallbackEXT(VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback);
   std::vector<const char*> getRequiredExtensions();
   static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objType, uint64_t obj, size_t location, int32_t code, const char* layerPrefix, const char* msg, void* userData);
   void DestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator);
   void pickPhysicalDevice();
   bool isDeviceSuitable(VkPhysicalDevice device);
   int rateDeviceSuitability(VkPhysicalDevice device);
   void createLogicalDevice();
};

