#include <cassert>
#include <iostream>

#include "executor.h"

// 简单的断言封装，失败时直接 assert
void CheckEqual(const Pose &actual, std::int32_t x, std::int32_t y, char heading)
{
    assert(actual.x == x);
    assert(actual.y == y);
    assert(actual.heading == heading);
}

int main()
{
    // 用例 1：默认构造，未手动初始化时，位置为 (0,0,N)
    {
        Executor executor;
        Pose pose = executor.GetPose();
        CheckEqual(pose, 0, 0, 'N');
    }

    // 用例 2：四个方向前进 M
    {
        Executor executor;

        executor.Initialize(0, 0, 'N');
        executor.ExecuteCommand('M');
        CheckEqual(executor.GetPose(), 0, 1, 'N');

        executor.Initialize(0, 0, 'S');
        executor.ExecuteCommand('M');
        CheckEqual(executor.GetPose(), 0, -1, 'S');

        executor.Initialize(0, 0, 'E');
        executor.ExecuteCommand('M');
        CheckEqual(executor.GetPose(), 1, 0, 'E');

        executor.Initialize(0, 0, 'W');
        executor.ExecuteCommand('M');
        CheckEqual(executor.GetPose(), -1, 0, 'W');
    }

    // 用例 3：左转 L
    {
        Executor executor;
        executor.Initialize(0, 0, 'N');
        executor.ExecuteCommand('L');
        CheckEqual(executor.GetPose(), 0, 0, 'W');

        executor.Initialize(0, 0, 'E');
        executor.ExecuteCommand('L');
        CheckEqual(executor.GetPose(), 0, 0, 'N');
    }

    // 用例 4：右转 R
    {
        Executor executor;
        executor.Initialize(0, 0, 'N');
        executor.ExecuteCommand('R');
        CheckEqual(executor.GetPose(), 0, 0, 'E');

        executor.Initialize(0, 0, 'W');
        executor.ExecuteCommand('R');
        CheckEqual(executor.GetPose(), 0, 0, 'N');
    }

    // 用例 5：组合指令 MRMLM
    {
        Executor executor;
        executor.Initialize(0, 0, 'N');
        executor.ExecuteCommands("MRMLM");
        // 轨迹：
        // 起点(0,0,N)
        // M -> (0,1,N)
        // R -> (0,1,E)
        // M -> (1,1,E)
        // L -> (1,1,N)
        // M -> (1,2,N)
        CheckEqual(executor.GetPose(), 1, 2, 'N');
    }

    std::cout << "All Executor tests passed.\n";
    return 0;
}
