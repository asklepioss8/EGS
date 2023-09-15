#pragma once

#include "window.hpp"

struct SwapChainSupportDetails
{
	VkSurfaceCapabilitiesKHR capabilities;
	std::vector<VkSurfaceFormatKHR> formats;
	std::vector<VkPresentModeKHR> presentModes;
};

struct QueueFamilyIndices
{
	uint32_t graphicsFamily{};
	uint32_t presentFamily{};
	bool graphicsFamilyHasValue = false;
	bool presentFamilyHasValue = false;

	bool isComplete()
	{
		return graphicsFamilyHasValue && presentFamilyHasValue;
	}
};

class EGSDevice
{
public:
#ifdef NDEBUG
	const bool enableValidationLayers = false;
#else
	const bool enableValidationLayers = true;
#endif // NDEBUG MACRO

	// Class Constructor and destructor
	EGSDevice(EGSWindow& window);
	~EGSDevice();

	// Physcial device properties as Public function
	VkPhysicalDeviceProperties properties;


	// Make Class immutable and non-copyable
	EGSDevice(const EGSDevice&) = delete;
	void operator=(const EGSDevice&) = delete;
	EGSDevice(EGSDevice&&) = delete;
	EGSDevice& operator=(EGSDevice&&) = delete;

	// Getter Functions for private variables
	VkCommandPool getCommandPool() { return commandPool; }
	VkDevice getDevice() { return device_; }
	VkSurfaceKHR getSurface() { return surface_; }
	VkQueue getGraphicsQueue() { return graphicsQueue_; }
	VkQueue getPresentQueue() { return presentQueue_; }

	// Checker Functions for System Support
	SwapChainSupportDetails getSwapChainSupport(){ return querySwapChainSupport(physicalDevice); }
	uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
	QueueFamilyIndices findPhysicalQueueFamilies() { return findQueueFamilies(physicalDevice); }
	VkFormat findSupportedFormat(
		const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features
	);

	// Memory buffer and other memory related functions
	void createBuffer(
		VkDeviceSize size,
		VkBufferUsageFlags usage,
		VkMemoryPropertyFlags properties,
		VkBuffer& buffer,
		VkDeviceMemory& bufferMemory
	);
	VkCommandBuffer beginSingleTimeCommands();
	void endSingleTimeCommands(VkCommandBuffer commandBuffer);
	void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);
	void copyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height, uint32_t layerCount);

	// Image creation discrete function
	void createImageWithInfo(
		const VkImageCreateInfo& imageInfo,
		VkMemoryPropertyFlags properties,
		VkImage& image,
		VkDeviceMemory& imageMemory
	);

private:

	// Device extensions and validation layers as Predefined variables
	const std::vector<const char*> validationLayers = { "VK_LAYER_KHRONOS_validation" };
	const std::vector<const char*> deviceExtensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };

	// #######SOME IMPORTANT VARIABLES#######
	VkInstance instance;
	VkDebugUtilsMessengerEXT debugMessenger;
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	EGSWindow& window;
	VkCommandPool commandPool;

	VkDevice device_;
	VkSurfaceKHR surface_;
	VkQueue graphicsQueue_;
	VkQueue presentQueue_;
	// ######################################

	// ##PIPELINE##
	void createInstance();
	void setupDebugMessenger();
	void createSurface();
	void pickPhysicalDevice();
	void createLogicalDevice();
	void createCommandPool();
	// ############

	// Helper and support functions
	bool isDeviceSuitable(VkPhysicalDevice device);
	std::vector<const char*> getRequiredExtensions();
	bool checkValidationLayerSupport();
	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
	void hasGlfwRequiredInstanceExtensions();
	bool checkDeviceExtensionSupport(VkPhysicalDevice device);
	SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);


};