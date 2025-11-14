#include "command.h"
#include "executor_impl.h"

// F 状态下前进 2 格，其它状态前进 1 格
void MoveCommand::DoOperate(ExecutorImpl &executor) const noexcept
{
    if (executor.IsFast())
    {
        executor.Move(); // 先多走一步
    }
    executor.Move(); // 正常的一步
}

// F 状态下：先 M 再 L
void TurnLeftCommand::DoOperate(ExecutorImpl &executor) const noexcept
{
    if (executor.IsFast())
    {
        executor.Move(); // 快速状态先前进一步
    }
    executor.TurnLeft();
}

// F 状态下：先 M 再 R
void TurnRightCommand::DoOperate(ExecutorImpl &executor) const noexcept
{
    if (executor.IsFast())
    {
        executor.Move();
    }
    executor.TurnRight();
}

// F 指令：切换 fast 状态
void FastCommand::DoOperate(ExecutorImpl &executor) const noexcept
{
    executor.Fast();
}
