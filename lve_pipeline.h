#pragma once

#include <string>
#include <vector>

namespace lve
{
    class LvePipeline
    {
    public:
        LvePipeline(const std::string& vertexFilePath, const std::string& fragFilePath);
    private:
        static std::vector<char> readFile(const std::string& filepath);
        void createGraphicsPipeline(const std::string& vertexFilePath, const std::string& fragFilePath);
    };
}