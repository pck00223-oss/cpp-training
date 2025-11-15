#include "PoseHandler.hpp"

namespace adas
{

    namespace
    {
        // 单步前进
        inline void StepForward(Pose &p) noexcept
        {
            switch (p.heading)
            {
            case 'N':
                ++p.y;
                break;
            case 'S':
                --p.y;
                break;
            case 'E':
                ++p.x;
                break;
            case 'W':
                --p.x;
                break;
            }
        }

        // 单步后退
        inline void StepBackward(Pose &p) noexcept
        {
            switch (p.heading)
            {
            case 'N':
                --p.y;
                break;
            case 'S':
                ++p.y;
                break;
            case 'E':
                --p.x;
                break;
            case 'W':
                ++p.x;
                break;
            }
        }
    } // anonymous namespace

    void PoseHandler::Move() noexcept
    {
        if (isFast_)
        {
            // 加速模式：前进两格
            StepForward(pose_);
            StepForward(pose_);
        }
        else
        {
            StepForward(pose_);
        }
    }

    void PoseHandler::TurnLeft() noexcept
    {
        // 加速模式：先前进一步再左转
        if (isFast_)
        {
            StepForward(pose_);
        }

        switch (pose_.heading)
        {
        case 'N':
            pose_.heading = 'W';
            break;
        case 'W':
            pose_.heading = 'S';
            break;
        case 'S':
            pose_.heading = 'E';
            break;
        case 'E':
            pose_.heading = 'N';
            break;
        }
    }

    void PoseHandler::TurnRight() noexcept
    {
        // 加速模式：先前进一步再右转
        if (isFast_)
        {
            StepForward(pose_);
        }

        switch (pose_.heading)
        {
        case 'N':
            pose_.heading = 'E';
            break;
        case 'E':
            pose_.heading = 'S';
            break;
        case 'S':
            pose_.heading = 'W';
            break;
        case 'W':
            pose_.heading = 'N';
            break;
        }
    }

    void PoseHandler::Fast() noexcept
    {
        // F：切换加速模式
        isFast_ = !isFast_;
    }

    void PoseHandler::Reverse() noexcept
    {
        // B：简单定义为后退一步（实验三用）
        StepBackward(pose_);
    }

} // namespace adas
