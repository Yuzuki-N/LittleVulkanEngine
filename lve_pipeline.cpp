#include "lve_pipeline.h"

#include <iostream>
#include <fstream>
namespace lve
{
    LvePipeline::LvePipeline(const std::string &vertexFilePath, const std::string &fragFilePath)
    {
        createGraphicsPipeline(vertexFilePath, fragFilePath);
    }
    void LvePipeline::createGraphicsPipeline(const std::string &vertexFilePath, const std::string &fragFilePath)
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
}