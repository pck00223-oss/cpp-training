#ifndef ADAS_EXECUTOR_H
#define ADAS_EXECUTOR_H

#include <memory>
#include <string>
#include "PoseHandler.hpp"

namespace adas
{

    class Executor
    {
    public:
        virtual ~Executor() = default;
        virtual void Execute(const std::string &commands) noexcept = 0;
        virtual Pose Query() const noexcept = 0;

        static std::unique_ptr<Executor> NewExecutor(const Pose &pose);
    };

} // namespace adas

#endif
