#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <cstdint>
#include <string>

// 位置 + 朝向
struct Pose
{
    int32_t x;
    int32_t y;
    char heading;
};

inline bool operator==(const Pose &a, const Pose &b)
{
    return a.x == b.x && a.y == b.y && a.heading == b.heading;
}

// 抽象执行器接口
class Executor
{
public:
    virtual ~Executor() = default;

    // 执行一串指令，例如 "MLRFM"
    virtual void Execute(const std::string &commands) noexcept = 0;

    // 查询当前位姿
    virtual Pose Query() const noexcept = 0;

    // 工厂函数：创建真正的实现类
    static Executor *NewExecutor(const Pose &initPose);
};

#endif // EXECUTOR_H
