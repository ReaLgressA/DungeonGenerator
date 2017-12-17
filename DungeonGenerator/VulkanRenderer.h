#pragma once
//#define DEBUG
#include "Renderer.h"
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <set>

class VulkanRenderer : public Renderer {
public:
    struct QueueFamilyIndices {
        int graphicsFamily = -1;
        int presentFamily = -1;
        bool isComplete() {
            return graphicsFamily >= 0 && presentFamily >= 0;
        }
    };
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
   VkPhysicalDeviceFeatures deviceFeatures = { };
   VkDevice device;
   VkQueue graphicsQueue;
   VkQueue presentQueue;
   VkSurfaceKHR surface;
   const std::vector<const char*> validationLayers = {
       "VK_LAYER_LUNARG_standard_validation"
   };
#ifdef DEBUG
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
   QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
   void createSurface();
};

