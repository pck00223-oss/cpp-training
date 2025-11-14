#include "executor.h"
#include "executor_impl.h"

Executor *Executor::NewExecutor(const Pose &initPose)
{
    return new ExecutorImpl(initPose);
}
