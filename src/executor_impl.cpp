#include "executor_impl.h"

namespace adas
{

    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept
        : handler_(pose)
    {
    }

    void ExecutorImpl::Execute(const std::string &commands) noexcept
    {
        for (char c : commands)
        {
            std::unique_ptr<ICommand> cmd;

            switch (c)
            {
            case 'M':
                cmd = std::make_unique<MoveCommand>();
                break;
            case 'L':
                cmd = std::make_unique<TurnLeftCommand>();
                break;
            case 'R':
                cmd = std::make_unique<TurnRightCommand>();
                break;
            case 'F':
                cmd = std::make_unique<FastCommand>();
                break;
            case 'B':
                cmd = std::make_unique<ReverseCommand>();
                break;
            default:
                continue;
            }

            (*cmd)(handler_);
        }
    }

    Pose ExecutorImpl::Query() const noexcept
    {
        return handler_.Query();
    }

} // namespace adas
