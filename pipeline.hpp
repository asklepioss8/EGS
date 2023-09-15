#pragma once
#include <string>
#include <vector>

#include "device.hpp"

struct PipelineConfigInfo
{
	PipelineConfigInfo() = default;
	PipelineConfigInfo(const PipelineConfigInfo&) = delete;
	// May void operator overload
	PipelineConfigInfo& operator=(const PipelineConfigInfo&) = delete;

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


class EGSGraphicsPipeline
{
public:

	EGSGraphicsPipeline(EGSDevice& device, const std::string& vertFilePath, const std::string& fragFilePath, const PipelineConfigInfo& configInfo);
	~EGSGraphicsPipeline();

	// Non construction-copyable
	EGSGraphicsPipeline(const EGSGraphicsPipeline&) = delete;
	// non copyable (EGSGraphicsPipeline& -> void maybe)
	EGSGraphicsPipeline& operator=(const EGSGraphicsPipeline&) = delete;

	static void defaultPipelineConfigInfo(PipelineConfigInfo &configInfo, uint32_t width, uint32_t heigth);

private:
	EGSDevice& egsDevice;
	VkPipeline egsGraphicsPipeline;
	VkShaderModule vertShaderModule;
	VkShaderModule fragShaderModule;


	static std::vector<char> readFile(const std::string filePath);
	void createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath, const PipelineConfigInfo& configInfo);
	void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);
};