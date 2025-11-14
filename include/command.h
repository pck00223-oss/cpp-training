#ifndef COMMAND_H
#define COMMAND_H

class ExecutorImpl;

// 抽象命令接口
class ICommand
{
public:
    virtual ~ICommand() = default;
    virtual void DoOperate(ExecutorImpl &executor) const noexcept = 0;
};

// M 指令
class MoveCommand final : public ICommand
{
public:
    void DoOperate(ExecutorImpl &executor) const noexcept override;
};

// L 指令
class TurnLeftCommand final : public ICommand
{
public:
    void DoOperate(ExecutorImpl &executor) const noexcept override;
};

// R 指令
class TurnRightCommand final : public ICommand
{
public:
    void DoOperate(ExecutorImpl &executor) const noexcept override;
};

// F 指令（切换加速状态）
class FastCommand final : public ICommand
{
public:
    void DoOperate(ExecutorImpl &executor) const noexcept override;
};

#endif // COMMAND_H
