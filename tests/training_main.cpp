#include <cassert>
#include "executor.h"

using namespace adas;

// 基本前进测试：从 (0,0,N) 执行 "M" -> (0,1,N)
int main()
{
    auto e = Executor::NewExecutor(Pose{0, 0, 'N'});
    e->Execute("M");

    Pose expected{0, 1, 'N'};
    Pose actual = e->Query();

    assert(actual == expected);
    return 0;
}
