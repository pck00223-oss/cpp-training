#include "executor_impl.h"

namespace adas
{

    std::unique_ptr<Executor> Executor::NewExecutor(const Pose &initial)
    {
        return std::make_unique<ExecutorImpl>(initial);
    }

} // namespace adas
