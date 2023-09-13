#pragma once
#include <vulkan/vulkan.hpp>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include <cstdlib>


class VulkanWindow
{
public:
	VulkanWindow(int w, int h, std::string n);
	~VulkanWindow();

	VulkanWindow(const VulkanWindow&) = delete;
	VulkanWindow& operator=(const VulkanWindow&) = delete;

	bool shouldClose() { return glfwWindowShouldClose(window); }
	void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

	int getWidth() { return width; }
	int getHeight() { return height; }

private:
	GLFWwindow* window;
	const int width;
	const int height;
	std::string wName;

	void initWindow();


};