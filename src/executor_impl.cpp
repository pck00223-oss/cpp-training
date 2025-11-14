#include "executor_impl.h"
#include "command.h"
#include <memory>

ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept
    : pose_(pose)
{
}

Pose ExecutorImpl::Query() const noexcept
{
    return pose_;
}

// 基础移动：前进一格
void ExecutorImpl::Move() noexcept
{
    switch (pose_.heading)
    {
    case 'E':
        ++pose_.x;
        break;
    case 'W':
        --pose_.x;
        break;
    case 'N':
        ++pose_.y;
        break;
    case 'S':
        --pose_.y;
        break;
    }
}

// 左转 90°
void ExecutorImpl::TurnLeft() noexcept
{
    switch (pose_.heading)
    {
    case 'E':
        pose_.heading = 'N';
        break;
    case 'N':
        pose_.heading = 'W';
        break;
    case 'W':
        pose_.heading = 'S';
        break;
    case 'S':
        pose_.heading = 'E';
        break;
    }
}

// 右转 90°
void ExecutorImpl::TurnRight() noexcept
{
    switch (pose_.heading)
    {
    case 'E':
        pose_.heading = 'S';
        break;
    case 'S':
        pose_.heading = 'W';
        break;
    case 'W':
        pose_.heading = 'N';
        break;
    case 'N':
        pose_.heading = 'E';
        break;
    }
}

// 切换 F 状态：普通 <-> 加速
void ExecutorImpl::Fast() noexcept
{
    isFast_ = !isFast_;
}

void ExecutorImpl::Execute(const std::string &commands) noexcept
{
    for (char c : commands)
    {
        std::unique_ptr<ICommand> cmd;

        if (c == 'M')
        {
            cmd = std::make_unique<MoveCommand>();
        }
        else if (c == 'L')
        {
            cmd = std::make_unique<TurnLeftCommand>();
        }
        else if (c == 'R')
        {
            cmd = std::make_unique<TurnRightCommand>();
        }
        else if (c == 'F')
        {
            cmd = std::make_unique<FastCommand>();
        }

        if (cmd)
        {
            cmd->DoOperate(*this);
        }
    }
}
