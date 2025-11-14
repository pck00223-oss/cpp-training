#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <cstdint>
#include <string>

// 车辆位姿（位置 + 朝向）
struct Pose
{
    std::int32_t x;
    std::int32_t y;
    char heading; // 'N', 'S', 'E', 'W'
};

// Executor 组件：负责维护车辆位置和朝向，执行基本控制指令
class Executor
{
public:
    Executor();

    // 初始化车辆位置和朝向，输入 (x, y, heading)
    void Initialize(std::int32_t x, std::int32_t y, char heading);

    // 执行单条指令：M / L / R
    void ExecuteCommand(char command);

    // 批量执行指令串，例如 "MMRML"
    void ExecuteCommands(const std::string &commands);

    // 查询当前车辆位姿
    Pose GetPose() const;

private:
    std::int32_t x_;
    std::int32_t y_;
    char heading_; // 当前朝向

    // 根据当前朝向执行前进 1 格
    void MoveForwardOneStep();

    // 左转 / 右转 90 度
    void TurnLeft();
    void TurnRight();
};

#endif // EXECUTOR_H
