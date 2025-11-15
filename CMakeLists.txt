cmake_minimum_required(VERSION 3.10)

project(cpp_training LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 库
add_library(executor
    src/executor.cpp
    src/executor_impl.cpp
    src/CmderFactory.cpp
    src/Command.cpp
    src/ActionGroup.cpp
    src/PoseHandler.cpp
)

target_include_directories(executor PUBLIC include)

# 示例程序
add_executable(main_app src/main.cpp)
target_link_libraries(main_app PRIVATE executor)

# 测试程序
add_executable(training_main tests/training_main.cpp)
target_link_libraries(training_main PRIVATE executor)

add_executable(turn_test tests/ExecutorTurnRoundTest.cpp)
target_link_libraries(turn_test PRIVATE executor)

# CTest 集成
enable_testing()
add_test(NAME executor_basic      COMMAND training_main)
add_test(NAME executor_turn_round COMMAND turn_test)
