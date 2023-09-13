#pragma once
#include <string>
#include <vector>

#include "device.hpp"

struct PipelineConfigInfo
{
	VkViewport viewport{};
	VkRect2D scissor{};
	
	VkPipelineViewportStateCreateInfo viewportInfo{};
	VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo{};
	VkPipelineRasterizationStateCreateInfo rasterizationýnfo{};
	VkPipelineMultisampleStateCreateInfo multisampleInfo{};
	VkPipelineColorBlendAttachmentState colorBlendAttachment{};
	VkPipelineColorBlendStateCreateInfo colorBlendInfo{};
};


class GraphicsPipeline
{
public:
	GraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath);

private:
	static std::vector<char> readFile(const std::string filePath);

	void createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath);
};