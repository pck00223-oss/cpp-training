#ifndef ADAS_EXECUTOR_IMPL_H
#define ADAS_EXECUTOR_IMPL_H

#include "executor.h"
#include "command.h"
#include <string>
#include <memory>
#include "PoseHandler.hpp"

namespace adas
{

    class ExecutorImpl final : public Executor
    {
    public:
        explicit ExecutorImpl(const Pose &pose) noexcept;

        void Execute(const std::string &commands) noexcept override;
        Pose Query() const noexcept override;

    private:
        PoseHandler handler_;
    };

} // namespace adas

#endif
