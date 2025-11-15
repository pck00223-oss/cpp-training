#include <iostream>
#include "executor.h"

using namespace adas;

int main()
{
    auto e = Executor::NewExecutor(Pose{0, 0, 'N'});
    e->Execute("MLRT");

    Pose p = e->Query();
    std::cout << "x=" << p.x << " y=" << p.y << " heading=" << p.heading << "\n";
    return 0;
}
