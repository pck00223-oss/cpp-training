#include <cassert>
#include "executor.h"

using namespace adas;

// 掉头测试：从 (0,0,N) 执行 "T" -> (0,0,S)
int main()
{
    auto e = Executor::NewExecutor(Pose{0, 0, 'N'});
    e->Execute("T");

    Pose p = e->Query();

    assert(p.x == 0);
    assert(p.y == 0);
    assert(p.heading == 'S'); // 失败信息里就是这一条
    return 0;
}
