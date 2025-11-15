#include "executor.h"
#include "executor_impl.h"

namespace adas
{

    std::unique_ptr<Executor> Executor::NewExecutor(const Pose &pose)
    {
        return std::make_unique<ExecutorImpl>(pose);
    }

} // namespace adas
