#ifndef ADAS_POSE_HANDLER_HPP
#define ADAS_POSE_HANDLER_HPP

#include <cstdint>

namespace adas
{

    // 位姿：坐标 + 朝向
    struct Pose
    {
        int32_t x;
        int32_t y;
        char heading; // 'N' / 'S' / 'E' / 'W'
    };

    // 用于测试里的：assert(e->Query() == target);
    inline bool operator==(const Pose &a, const Pose &b) noexcept
    {
        return a.x == b.x && a.y == b.y && a.heading == b.heading;
    }

    class PoseHandler
    {
    public:
        explicit PoseHandler(const Pose &pose) noexcept
            : pose_(pose), isFast_(false)
        {
        }

        // 基本动作
        void Move() noexcept;      // 前进（考虑加速模式）
        void TurnLeft() noexcept;  // 左转（考虑加速模式）
        void TurnRight() noexcept; // 右转（考虑加速模式）

        // 状态切换
        void Fast() noexcept;    // F：切换“加速模式” 开/关
        void Reverse() noexcept; // B：后退一步（预留给实验三）

        void Reset(const Pose &p) noexcept { pose_ = p; }

        Pose Query() const noexcept { return pose_; }

        bool IsFast() const noexcept { return isFast_; }

    private:
        Pose pose_;
        bool isFast_;
    };

} // namespace adas

#endif // ADAS_POSE_HANDLER_HPP
