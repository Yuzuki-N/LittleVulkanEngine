#pragma once

#include "lve_window.h"
#include "lve_pipeline.h"
#include "lve_device.h"
namespace lve
{
    class FirstApp
    {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();
    private:
        LveWindow lveWindow{WIDTH, HEIGHT, "HELLO VULKAN!"};
        LveDevice lveDevice{lveWindow};
        // 路径是为了让clion正确找到文件，不用clion就不用这样写
        LvePipeline lvePipeline{
            lveDevice,
            "../shaders/simple_shader.vert.spv",
            "../shaders/simple_shader.frag.spv",
            LvePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};
    };
}

