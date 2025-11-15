#ifndef ADAS_POSEHANDLER_HPP
#define ADAS_POSEHANDLER_HPP

#include "Pose.h"
#include "ActionTypes.hpp"

namespace adas
{

    class PoseHandler
    {
    public:
        explicit PoseHandler(Pose pose) noexcept
            : pose_(pose) {}

        // 基础位姿操作
        void StepForward() noexcept;
        void StepBackward() noexcept;
        void StepLeft() noexcept;  // 改变朝向（左转）
        void StepRight() noexcept; // 改变朝向（右转）

        // 将 ActionType 映射为具体动作
        void Apply(ActionType act) noexcept;

        Pose Query() const noexcept { return pose_; }

    private:
        Pose pose_;
    };

} // namespace adas

#endif // ADAS_POSEHANDLER_HPP
