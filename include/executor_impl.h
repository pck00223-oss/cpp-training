#ifndef ADAS_EXECUTOR_IMPL_H
#define ADAS_EXECUTOR_IMPL_H

#include "executor.h"
#include "CmderFactory.hpp"
#include "PoseHandler.hpp"

namespace adas
{

    // 具体实现
    class ExecutorImpl final : public Executor
    {
    public:
        explicit ExecutorImpl(const Pose &initial) noexcept;

        void Execute(const std::string &commands) noexcept override;

        Pose Query() const noexcept override;

    private:
        PoseHandler handler_;
        CmderFactory factory_;
    };

} // namespace adas

#endif // ADAS_EXECUTOR_IMPL_H
