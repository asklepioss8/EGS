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
	VkPipelineRasterizationStateCreateInfo rasterizationInfo{};
	VkPipelineMultisampleStateCreateInfo multisampleInfo{};
	VkPipelineColorBlendAttachmentState colorBlendAttachment{};
	VkPipelineColorBlendStateCreateInfo colorBlendInfo{};
	VkPipelineDepthStencilStateCreateInfo depthStencilInfo{};
	
	VkPipelineLayout pipelineLayout = nullptr;
	VkRenderPass renderPass = nullptr;
	uint32_t subpass = 0;
};


class GraphicsPipeline
{
public:

	GraphicsPipeline(Devices& device, const std::string& vertFilePath, const std::string& fragFilePath, const PipelineConfigInfo& configInfo);
	~GraphicsPipeline();

	// Non construction-copyable
	GraphicsPipeline(const GraphicsPipeline&) = delete;
	// non copyable (GraphicsPipeline& -> void maybe)
	GraphicsPipeline& operator=(const GraphicsPipeline&) = delete;

	static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t heigth);

private:
	Devices& devices;
	VkPipeline graphicsPipeline;
	VkShaderModule vertShaderModule;
	VkShaderModule fragShaderModule;


	static std::vector<char> readFile(const std::string filePath);
	void createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath, const PipelineConfigInfo& configInfo);
	void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);
};