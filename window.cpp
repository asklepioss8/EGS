#include "window.hpp"
#include <stdexcept>

EGSWindow::EGSWindow(int w, int h, std::string n) : width(w), height(h), wName(n)
{
	initWindow();
}

EGSWindow::~EGSWindow()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

void EGSWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface)
{
	if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS)
	{
		throw std::runtime_error("Failed to create window surface");
	}
}

void EGSWindow::initWindow()
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(width, height, wName.c_str(), nullptr, nullptr);
}
