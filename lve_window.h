#pragma once

// 告诉glfw包含vulkan的头文件
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>


namespace lve
{
    class LveWindow
    {
    public:
        LveWindow(int w, int h, const std::string& name);
        ~LveWindow();
        LveWindow(const LveWindow&) = delete;
        LveWindow& operator=(const LveWindow&) = delete;

        bool shouldClose()
        {
            return glfwWindowShouldClose(window);
        }

        void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

    private:
        void initWindow();

        const int width;
        const int height;

        std::string windowName;
        GLFWwindow* window;
    };
}