#ifndef EXECUTOR_IMPL_H
#define EXECUTOR_IMPL_H

#include "executor.h"

class ICommand;

// 具体实现类，真正保存状态、实现移动/转向
class ExecutorImpl final : public Executor
{
public:
    explicit ExecutorImpl(const Pose &pose) noexcept;

    void Execute(const std::string &commands) noexcept override;
    Pose Query() const noexcept override;

    // 被命令对象调用的基础行为
    void Move() noexcept;
    void TurnLeft() noexcept;
    void TurnRight() noexcept;

    // F 指令：切换加速状态
    void Fast() noexcept;
    bool IsFast() const noexcept { return isFast_; }

private:
    Pose pose_{0, 0, 'N'};
    bool isFast_{false};
};

#endif // EXECUTOR_IMPL_H
