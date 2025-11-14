#include "executor.h"

Executor::Executor() : x_(0), y_(0), heading_('N') {}

void Executor::Initialize(std::int32_t x, std::int32_t y, char heading)
{
    x_ = x;
    y_ = y;
    heading_ = heading;
}

void Executor::ExecuteCommand(char command)
{
    switch (command)
    {
    case 'M':
        MoveForwardOneStep();
        break;
    case 'L':
        TurnLeft();
        break;
    case 'R':
        TurnRight();
        break;
    default:
        // 约束：不考虑非法指令
        break;
    }
}

void Executor::ExecuteCommands(const std::string &commands)
{
    for (char c : commands)
    {
        ExecuteCommand(c);
    }
}

Pose Executor::GetPose() const
{
    return Pose{x_, y_, heading_};
}

// X 轴为 E/W 方向，Y 轴为 N/S 方向
void Executor::MoveForwardOneStep()
{
    switch (heading_)
    {
    case 'E':
        ++x_;
        break;
    case 'W':
        --x_;
        break;
    case 'N':
        ++y_;
        break;
    case 'S':
        --y_;
        break;
    default:
        break;
    }
}

void Executor::TurnLeft()
{
    // 左转：N->W->S->E->N
    switch (heading_)
    {
    case 'N':
        heading_ = 'W';
        break;
    case 'W':
        heading_ = 'S';
        break;
    case 'S':
        heading_ = 'E';
        break;
    case 'E':
        heading_ = 'N';
        break;
    default:
        break;
    }
}

void Executor::TurnRight()
{
    // 右转：N->E->S->W->N
    switch (heading_)
    {
    case 'N':
        heading_ = 'E';
        break;
    case 'E':
        heading_ = 'S';
        break;
    case 'S':
        heading_ = 'W';
        break;
    case 'W':
        heading_ = 'N';
        break;
    default:
        break;
    }
}
