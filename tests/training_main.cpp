#include <cassert>
#include <iostream>
#include <memory>

#include "executor.h"
#include "PoseHandler.hpp"

// 为了少写一些前缀
using adas::Executor;
using adas::Pose;
using std::unique_ptr;

void test_move_basic()
{
    // facing E
    {
        unique_ptr<Executor> e(Executor::NewExecutor({0, 0, 'E'}));
        e->Execute("M");
        Pose target{1, 0, 'E'};
        assert(e->Query() == target);
    }
    // facing W
    {
        unique_ptr<Executor> e(Executor::NewExecutor({0, 0, 'W'}));
        e->Execute("M");
        Pose target{-1, 0, 'W'};
        assert(e->Query() == target);
    }
    // facing N
    {
        unique_ptr<Executor> e(Executor::NewExecutor({0, 0, 'N'}));
        e->Execute("M");
        Pose target{0, 1, 'N'};
        assert(e->Query() == target);
    }
    // facing S
    {
        unique_ptr<Executor> e(Executor::NewExecutor({0, 0, 'S'}));
        e->Execute("M");
        Pose target{0, -1, 'S'};
        assert(e->Query() == target);
    }
}

void test_turn_left_basic()
{
    // E -> N
    {
        unique_ptr<Executor> e(Executor::NewExecutor({0, 0, 'E'}));
        e->Execute("L");
        Pose target{0, 0, 'N'};
        assert(e->Query() == target);
    }
    // N -> W
    {
        unique_ptr<Executor> e(Executor::NewExecutor({0, 0, 'N'}));
        e->Execute("L");
        Pose target{0, 0, 'W'};
        assert(e->Query() == target);
    }
    // W -> S
    {
        unique_ptr<Executor> e(Executor::NewExecutor({0, 0, 'W'}));
        e->Execute("L");
        Pose target{0, 0, 'S'};
        assert(e->Query() == target);
    }
    // S -> E
    {
        unique_ptr<Executor> e(Executor::NewExecutor({0, 0, 'S'}));
        e->Execute("L");
        Pose target{0, 0, 'E'};
        assert(e->Query() == target);
    }
}

void test_turn_right_basic()
{
    // E -> S
    {
        unique_ptr<Executor> e(Executor::NewExecutor({0, 0, 'E'}));
        e->Execute("R");
        Pose target{0, 0, 'S'};
        assert(e->Query() == target);
    }
    // S -> W
    {
        unique_ptr<Executor> e(Executor::NewExecutor({0, 0, 'S'}));
        e->Execute("R");
        Pose target{0, 0, 'W'};
        assert(e->Query() == target);
    }
    // W -> N
    {
        unique_ptr<Executor> e(Executor::NewExecutor({0, 0, 'W'}));
        e->Execute("R");
        Pose target{0, 0, 'N'};
        assert(e->Query() == target);
    }
    // N -> E
    {
        unique_ptr<Executor> e(Executor::NewExecutor({0, 0, 'N'}));
        e->Execute("R");
        Pose target{0, 0, 'E'};
        assert(e->Query() == target);
    }
}

// ===== 实验2：F 指令用例 =====

// 1) F + M，当前朝向 E：x+2
void test_fast_move_E()
{
    unique_ptr<Executor> e(Executor::NewExecutor({0, 0, 'E'}));
    e->Execute("FM");
    Pose target{2, 0, 'E'};
    assert(e->Query() == target);
}

// 2) F + L，当前朝向 E：执行 FL -> x+1, 方向 N
void test_fast_left_E()
{
    unique_ptr<Executor> e(Executor::NewExecutor({0, 0, 'E'}));
    e->Execute("FL");
    Pose target{1, 0, 'N'};
    assert(e->Query() == target);
}

// 3) F + R，当前朝向 E：执行 FR -> x+1, 方向 S
void test_fast_right_E()
{
    unique_ptr<Executor> e(Executor::NewExecutor({0, 0, 'E'}));
    e->Execute("FR");
    Pose target{1, 0, 'S'};
    assert(e->Query() == target);
}

// 4) F F M，当前朝向 N：第二个 F 取消加速，只前进 1 格
void test_fast_toggle_off()
{
    unique_ptr<Executor> e(Executor::NewExecutor({0, 0, 'N'}));
    e->Execute("FFM");
    Pose target{0, 1, 'N'};
    assert(e->Query() == target);
}

int main()
{
    test_move_basic();
    test_turn_left_basic();
    test_turn_right_basic();

    test_fast_move_E();
    test_fast_left_E();
    test_fast_right_E();
    test_fast_toggle_off();

    std::cout << "All executor tests passed.\n";
    return 0;
}
