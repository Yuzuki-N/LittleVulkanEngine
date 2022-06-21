#pragma once

#include "lve_window.h"
#include "lve_pipeline.h"

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
        // 路径是为了让clion正确找到文件，不用clion就不用这样写
        LvePipeline lvePipeline{"../shaders/simple_shader.vert.spv",
                                "../shaders/simple_shader.frag.spv"};
    };
}

