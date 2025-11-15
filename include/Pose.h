#ifndef ADAS_POSE_H
#define ADAS_POSE_H

namespace adas
{

    struct Pose
    {
        int x{};
        int y{};
        char heading{'N'};
    };

    // 方便 assert 比较
    inline bool operator==(const Pose &a, const Pose &b) noexcept
    {
        return a.x == b.x && a.y == b.y && a.heading == b.heading;
    }

    inline bool operator!=(const Pose &a, const Pose &b) noexcept
    {
        return !(a == b);
    }

} // namespace adas

#endif // ADAS_POSE_H
