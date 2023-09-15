#pragma once
#include "window.hpp"
#include "pipeline.hpp"
#include "device.hpp"
#include "swapchain.hpp"

#include <memory>
#include <vector>

class App
{
public:
	// Some predefined variables about application
	static constexpr int WIDTH = 800;
	static constexpr int HEIGHT = 600;
	const char* wName = { "Vulkan Window" };

	App();
	~App();

	void run();

	App(const App&) = delete;
	App& operator=(const App&) = delete;

private:
	// ######## SOME IMPORTANT VARIABLES############
	// Window creation
	EGSWindow egsWindow{ WIDTH, HEIGHT, wName };
	// Logical and Physical device
	EGSDevice egsDevice{ egsWindow };
	// Swapchain
	EGSSwapChain egsSwapChain{ egsDevice, egsWindow.getExtent()};
	// Pipeline creation
	std::unique_ptr<EGSGraphicsPipeline> egsGraphicsPipeline;
	// Pipeline Layout
	VkPipelineLayout pipelineLayout{};
	// Command buffer
	std::vector<VkCommandBuffer> commandBuffers;
	// ###########################################

	void createPipelineLayout();
	void createPipeline();
	void createCommandBuffers();
	void drawFrame();

};

