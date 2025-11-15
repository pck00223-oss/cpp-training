#ifndef ADAS_ACTIONGROUP_HPP
#define ADAS_ACTIONGROUP_HPP

#include <vector>
#include "ActionTypes.hpp"

namespace adas
{

    // 一个命令可以对应一组动作（这里最多两个：掉头 = 两次左转）
    class ActionGroup
    {
    public:
        void Add(ActionType act)
        {
            actions_.push_back(act);
        }

        const std::vector<ActionType> &Actions() const noexcept
        {
            return actions_;
        }

    private:
        std::vector<ActionType> actions_;
    };

} // namespace adas

#endif // ADAS_ACTIONGROUP_HPP
