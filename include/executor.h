#ifndef ADAS_EXECUTOR_H
#define ADAS_EXECUTOR_H

#include <memory>
#include <string>

#include "Pose.h"

namespace adas
{

    // 对外暴露的执行器接口
    class Executor
    {
    public:
        virtual ~Executor() = default;

        virtual void Execute(const std::string &commands) noexcept = 0;

        virtual Pose Query() const noexcept = 0;

        // 工厂方法
        static std::unique_ptr<Executor> NewExecutor(const Pose &initial);
    };

} // namespace adas

#endif // ADAS_EXECUTOR_H
