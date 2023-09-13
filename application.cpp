#include "application.hpp"

void App::run()
{
	while (!vulkanWindow.shouldClose())
	{
		glfwPollEvents();
	}
}
