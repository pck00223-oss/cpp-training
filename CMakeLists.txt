cmake_minimum_required(VERSION 3.10)
project(cpp-training)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Executor 库
add_library(executor
    src/executor.cpp
)

target_include_directories(executor PUBLIC include)

# 测试程序
add_executable(training_main
    tests/training_main.cpp
)

target_link_libraries(training_main PRIVATE executor)

# 启用测试
enable_testing()
add_test(NAME executor_tests COMMAND training_main)

# 设置输出路径（可选）
set_target_properties(training_main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests
)
