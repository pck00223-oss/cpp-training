// tests/executor_fasttest.cpp
// 本文件是“Fast(F) 指令”的自测用例，不依赖 gtest

#include <cassert>
#include "executor.h"
#include "PoseHandler.hpp"

using namespace adas;

// M: 在 F 状态下，朝 E，前进 2 格
void fast_case_move_E()
{
    auto executor = Executor::NewExecutor({0, 0, 'E'});
    executor->Execute("FM"); // 先 F 再 M
    Pose target{2, 0, 'E'};
    assert(executor->Query() == target);
}

// L: 在 F 状态下，朝 E，先前进 1 格，再左转成 N
void fast_case_left_E()
{
    auto executor = Executor::NewExecutor({0, 0, 'E'});
    executor->Execute("FL");
    Pose target{1, 0, 'N'};
    assert(executor->Query() == target);
}

// R: 在 F 状态下，朝 E，先前进 1 格，再右转成 S
void fast_case_right_E()
{
    auto executor = Executor::NewExecutor({0, 0, 'E'});
    executor->Execute("FR");
    Pose target{1, 0, 'S'};
    assert(executor->Query() == target);
}

// 连续两次 F，再 M：FFM。第二个 F 取消加速，只前进 1 格
void fast_case_toggle_off()
{
    auto executor = Executor::NewExecutor({0, 0, 'N'});
    executor->Execute("FFM");
    Pose target{0, 1, 'N'};
    assert(executor->Query() == target);
}

// 如果以后想统一调用，可以在 main 里调用这个函数
void run_all_fast_tests()
{
    fast_case_move_E();
    fast_case_left_E();
    fast_case_right_E();
    fast_case_toggle_off();
}
