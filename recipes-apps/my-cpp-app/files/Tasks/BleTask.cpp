#include "BleTask.hpp"
#include <iostream>

namespace Tasks
{
    void BleTask::Run(std::stop_token stopToken)
    {
        while (!stopToken.stop_requested())
        {
            std::cout << "Ble Task\n";
            Os::Delay(2000);
        }
    }
}
