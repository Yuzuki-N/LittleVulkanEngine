cmake_minimum_required(VERSION 3.22)
project(lve)

set(CMAKE_CXX_STANDARD 17)

add_executable(lve main.cpp
        lve_window.h lve_window.cpp first_app.cpp first_app.h lve_pipeline.cpp lve_pipeline.h
        lve_device.h lve_device.cpp)

# GLFW
set(GLFW_DIRS /opt/homebrew/Cellar/glfw/3.3.7/)
include_directories(${PROJECT_NAME} ${GLFW_DIRS}/include/)
target_link_libraries(${PROJECT_NAME} ${GLFW_DIRS}/lib/libglfw.3.dylib)


# GLM
set(GLM_INCLUDE_DIRS /opt/homebrew/Cellar/glm/0.9.9.8/include/)
include_directories(${GLM_INCLUDE_DIRS})

# vulkan
find_package(Vulkan REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC ${Vulkan_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan)