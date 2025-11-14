cmake_minimum_required(VERSION 3.16)

project(cpp_training LANGUAGES CXX)

# C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 方便生成 compile_commands.json（可选）
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ======================
# 1. executor 静态库
# ======================
add_library(executor
    src/executor.cpp
    src/executor_impl.cpp
    src/command.cpp
)

target_include_directories(executor
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# ======================
# 2. 测试程序：training_main
# ======================
add_executable(training_main
    tests/training_main.cpp
)

target_link_libraries(training_main
    PRIVATE executor
)

# ======================
# 3. CTest 集成
# ======================
enable_testing()

add_test(
    NAME executor_tests
    COMMAND training_main
)
