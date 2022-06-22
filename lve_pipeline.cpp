#include "lve_pipeline.h"

#include <iostream>
#include <fstream>
namespace lve
{
    LvePipeline::LvePipeline(LveDevice& device,
                             const std::string& vertexFilePath,
                             const std::string& fragFilePath,
                             const PipelineConfigInfo& ConfigInfo)
                             : lveDevice{device}
    {
        createGraphicsPipeline(vertexFilePath, fragFilePath, ConfigInfo);
    }
    void LvePipeline::createGraphicsPipeline(const std::string &vertexFilePath, const std::string &fragFilePath, const PipelineConfigInfo& configInfo)
    {
        auto vertCode =  readFile(vertexFilePath);
        auto fragCode = readFile(fragFilePath);

        std::cout << "Vert Shader Code Size: " << vertCode.size() << "\n";
        std::cout << "frag Shader Code Size: " << fragCode.size() << "\n";
    }

    std::vector<char> LvePipeline::readFile(const std::string &filepath)
    {
        std::ifstream file(filepath, std::ios::ate | std::ios::binary);
        if (!file.is_open())
        {
            throw std::runtime_error("failed to open file " + filepath);
        }

        size_t fileSize = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(fileSize);

        file.seekg(0);
        file.read(buffer.data(), fileSize);

        file.close();
        return buffer;
    }

    void LvePipeline::createShaderModule(const std::vector<char> &code, VkShaderModule* shaderModule)
    {
        VkShaderModuleCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        createInfo.codeSize = code.size();
        createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

        if (vkCreateShaderModule(lveDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS)
        {
            throw std::runtime_error("fail to create Shader Module");
        }
    }

    PipelineConfigInfo LvePipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height)
    {
        PipelineConfigInfo configInfo{};
        return configInfo;
    }
}