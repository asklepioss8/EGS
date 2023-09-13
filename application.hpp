#pragma once
#include "window.hpp"
#include "pipeline.hpp"
#include "device.hpp"

class App
{
public:
	// Some predefined variables about application
	static constexpr int WIDTH = 800;
	static constexpr int HEIGHT = 600;
	const char* wName = { "Vulkan Window" };
	void run();

private:
	// Window creation
	VulkanWindow vulkanWindow{ WIDTH, HEIGHT, wName };
	// Logical and Physical device
	Devices devices{ vulkanWindow };
	// Pipeline Layout

	// Pipeline creation
	GraphicsPipeline graphicsPipeline{ "shaders/simple_shader.vert.spv", "shaders/simple_shader.frag.spv" };
};

