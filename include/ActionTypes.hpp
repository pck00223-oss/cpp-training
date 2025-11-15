#ifndef ADAS_ACTIONTYPES_HPP
#define ADAS_ACTIONTYPES_HPP

namespace adas
{

    // 统一的动作类型枚举
    enum class ActionType
    {
        FORWARD_1_STEP,  // 前进一步
        TURNLEFT_ACTION, // 左转 90°
        TURNRIGHT_ACTION // 右转 90°
    };

} // namespace adas

#endif // ADAS_ACTIONTYPES_HPP
