#include "PoseHandler.hpp"

namespace adas
{

    void PoseHandler::StepForward() noexcept
    {
        switch (pose_.heading)
        {
        case 'N':
            ++pose_.y;
            break;
        case 'S':
            --pose_.y;
            break;
        case 'E':
            ++pose_.x;
            break;
        case 'W':
            --pose_.x;
            break;
        default:
            break;
        }
    }

    void PoseHandler::StepBackward() noexcept
    {
        switch (pose_.heading)
        {
        case 'N':
            --pose_.y;
            break;
        case 'S':
            ++pose_.y;
            break;
        case 'E':
            --pose_.x;
            break;
        case 'W':
            ++pose_.x;
            break;
        default:
            break;
        }
    }

    void PoseHandler::StepLeft() noexcept
    {
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
        default:
            break;
        }
    }

    void PoseHandler::StepRight() noexcept
    {
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
        default:
            break;
        }
    }

    // 将 ActionType 映射到具体动作
    void PoseHandler::Apply(ActionType act) noexcept
    {
        switch (act)
        {
        case ActionType::FORWARD_1_STEP:
            StepForward();
            break;
        case ActionType::TURNLEFT_ACTION:
            StepLeft();
            break;
        case ActionType::TURNRIGHT_ACTION:
            StepRight();
            break;
        default:
            break;
        }
    }

} // namespace adas
