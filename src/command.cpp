#include "Command.hpp"

namespace adas
{

    // M：前进一步
    ActionGroup MoveCommand::operator()(PoseHandler &handler) const noexcept
    {
        ActionGroup g;
        g.Add(ActionType::FORWARD_1_STEP);
        return g;
    }

    std::unique_ptr<ICommand> MoveCommand::clone() const noexcept
    {
        return std::make_unique<MoveCommand>();
    }

    // L：左转 90°
    ActionGroup TurnLeftCommand::operator()(PoseHandler &handler) const noexcept
    {
        ActionGroup g;
        g.Add(ActionType::TURNLEFT_ACTION);
        return g;
    }

    std::unique_ptr<ICommand> TurnLeftCommand::clone() const noexcept
    {
        return std::make_unique<TurnLeftCommand>();
    }

    // R：右转 90°
    ActionGroup TurnRightCommand::operator()(PoseHandler &handler) const noexcept
    {
        ActionGroup g;
        g.Add(ActionType::TURNRIGHT_ACTION);
        return g;
    }

    std::unique_ptr<ICommand> TurnRightCommand::clone() const noexcept
    {
        return std::make_unique<TurnRightCommand>();
    }

    // T：掉头 = 左转两次
    ActionGroup TurnRoundCommand::operator()(PoseHandler &handler) const noexcept
    {
        ActionGroup g;
        g.Add(ActionType::TURNLEFT_ACTION);
        g.Add(ActionType::TURNLEFT_ACTION);
        return g;
    }

    std::unique_ptr<ICommand> TurnRoundCommand::clone() const noexcept
    {
        return std::make_unique<TurnRoundCommand>();
    }

} // namespace adas
