#pragma once

#include "lve_window.h"
#include "lve_pipeline.h"
#include "lve_device.h"
#include "lve_swap_chain.h"

// std
#include <memory>
#include <vector>

namespace lve
{
    class FirstApp
    {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        FirstApp();
        ~FirstApp();

        FirstApp(const FirstApp&) = delete;
        FirstApp operator=(const FirstApp&) = delete;

        void run();
    private:

        void createPipelineLayout();
        void createPipeline();
        void createCommandBuffer();
        void drawFrame();

        LveWindow lveWindow{WIDTH, HEIGHT, "HELLO VULKAN!"};
        LveDevice lveDevice{lveWindow};
        LveSwapChain lveSwapChain{lveDevice, lveWindow.getExtent()};
        // 路径是为了让clion正确找到文件，不用clion就不用这样写
//        LvePipeline lvePipeline{
//            lveDevice,
//            "../shaders/simple_shader.vert.spv",
//            "../shaders/simple_shader.frag.spv",
//            LvePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};
        std::unique_ptr<LvePipeline> lvePipeline;

        VkPipelineLayout pipelineLayout;
        std::vector<VkCommandBuffer> commandBuffers;
    };
}

