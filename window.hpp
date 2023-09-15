#pragma once
#include <vulkan/vulkan.hpp>
#include <GLFW/glfw3.h>
#include <string>



class EGSWindow
{
public:
	EGSWindow(int w, int h, std::string n);
	~EGSWindow();

	EGSWindow(const EGSWindow&) = delete;
	EGSWindow& operator=(const EGSWindow&) = delete;

	bool shouldClose() { return glfwWindowShouldClose(window); }
	VkExtent2D getExtent() { return { static_cast<uint32_t>(width), static_cast<uint32_t>(height) }; }
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