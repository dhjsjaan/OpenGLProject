cmake_minimum_required(VERSION 3.23)
project(openGLProject)

set(CMAKE_CXX_STANDARD 17)

# 查找 src 目录下所有 .h、.c、.cpp 文件
file(GLOB_RECURSE SRC_FILES "${PROJECT_SOURCE_DIR}/src/*.h" "${PROJECT_SOURCE_DIR}/src/*.c" "${PROJECT_SOURCE_DIR}/src/*.cpp")

include_directories("./include")
link_directories("./lib")

add_subdirectory(thirdparty/imgui-docking)

#可执行文件
add_executable(openGLProject ${SRC_FILES})

target_link_libraries(openGLProject glfw3.dll libassimp-5.dll imguilib)