#ifndef ADAS_COMMAND_H
#define ADAS_COMMAND_H

#include <string>
#include <memory>
#include "PoseHandler.hpp"

namespace adas
{

    class ICommand
    {
    public:
        virtual ~ICommand() = default;
        virtual void operator()(PoseHandler &handler) const noexcept = 0;
    };

    class MoveCommand final : public ICommand
    {
    public:
        void operator()(PoseHandler &handler) const noexcept override
        {
            handler.Move();
        }
    };

    class TurnLeftCommand final : public ICommand
    {
    public:
        void operator()(PoseHandler &handler) const noexcept override
        {
            handler.TurnLeft();
        }
    };

    class TurnRightCommand final : public ICommand
    {
    public:
        void operator()(PoseHandler &handler) const noexcept override
        {
            handler.TurnRight();
        }
    };

    class FastCommand final : public ICommand
    {
    public:
        void operator()(PoseHandler &handler) const noexcept override
        {
            handler.Fast();
        }
    };

    class ReverseCommand final : public ICommand
    {
    public:
        void operator()(PoseHandler &handler) const noexcept override
        {
            handler.Reverse();
        }
    };

} // namespace adas

#endif
