#include "pipeline.hpp"
#include <fstream>
#include <iostream>

GraphicsPipeline::GraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath)
{
	createGraphicsPipeline(vertFilePath, fragFilePath);
}

std::vector<char> GraphicsPipeline::readFile(const std::string filePath)
{
	std::ifstream file(filePath, std::ios::ate | std::ios::binary);

	if (!file.is_open())
	{
		throw std::runtime_error("Failed to open file: " + filePath);
	}

	size_t fileSize = static_cast<size_t>(file.tellg());
	std::vector<char> buffer(fileSize);

	file.seekg(0);
	file.read(buffer.data(), fileSize);

	return buffer;
}

void GraphicsPipeline::createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath)
{
	auto vertCode = readFile(vertFilePath);
	auto fragCode = readFile(fragFilePath);

	std::cout << "The Vertex Shader code size: " << vertCode.size() << '\n';
	std::cout << "The Fragment Shader code size: " << fragCode.size() << '\n';
}
