#include "executor.h"
#include "PoseHandler.hpp"
#include <iostream>

int main()
{
    adas::Pose initPose{0, 0, 'N'};
    auto executor = adas::Executor::NewExecutor(initPose);

    std::string commands = "MLRFMBB";
    executor->Execute(commands);

    auto finalPose = executor->Query();
    std::cout << "Final: (" << finalPose.x << ", "
              << finalPose.y << ") heading=" << finalPose.heading << "\n";

    return 0;
}
