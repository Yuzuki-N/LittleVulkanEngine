cd ..

rm -rf Shaders/*.spv

glslc Shaders/shader_base.vert -o Shaders/shader_base.vert.spv
glslc Shaders/shader_base.frag -o Shaders/shader_base.frag.spv