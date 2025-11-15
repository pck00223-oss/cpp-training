#include "executor_impl.h"

namespace adas
{

    ExecutorImpl::ExecutorImpl(const Pose &initial) noexcept
        : handler_(initial), factory_() {}

    void ExecutorImpl::Execute(const std::string &commands) noexcept
    {
        auto list = factory_.Parse(commands);
        for (auto &cmd : list)
        {
            ActionGroup g = (*cmd)(handler_);
            for (auto act : g.Actions())
            {
                handler_.Apply(act);
            }
        }
    }

    Pose ExecutorImpl::Query() const noexcept
    {
        return handler_.Query();
    }

} // namespace adas
