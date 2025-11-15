#ifndef ADAS_COMMAND_HPP
#define ADAS_COMMAND_HPP

#include <memory>
#include "ActionGroup.hpp"
#include "PoseHandler.hpp"

namespace adas
{

    // 抽象命令接口
    class ICommand
    {
    public:
        virtual ~ICommand() = default;

        // 执行命令：根据当前位姿生成动作组
        virtual ActionGroup operator()(PoseHandler &handler) const noexcept = 0;

        // 用于克隆（工厂里每个字母复用同一个原型）
        virtual std::unique_ptr<ICommand> clone() const noexcept = 0;
    };

    // M：前进一步
    class MoveCommand final : public ICommand
    {
    public:
        ActionGroup operator()(PoseHandler &handler) const noexcept override;
        std::unique_ptr<ICommand> clone() const noexcept override;
    };

    // L：左转 90°
    class TurnLeftCommand final : public ICommand
    {
    public:
        ActionGroup operator()(PoseHandler &handler) const noexcept override;
        std::unique_ptr<ICommand> clone() const noexcept override;
    };

    // R：右转 90°
    class TurnRightCommand final : public ICommand
    {
    public:
        ActionGroup operator()(PoseHandler &handler) const noexcept override;
        std::unique_ptr<ICommand> clone() const noexcept override;
    };

    // T：掉头 = 左转两次
    class TurnRoundCommand final : public ICommand
    {
    public:
        ActionGroup operator()(PoseHandler &handler) const noexcept override;
        std::unique_ptr<ICommand> clone() const noexcept override;
    };

} // namespace adas

#endif // ADAS_COMMAND_HPP
