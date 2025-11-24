#include "BleTask.hpp"
#include <iostream>

namespace Tasks
{
    void BleTask::Run()
    {
        while (true)
        {
            std::cout << "Ble Task\n";
            Os::Delay(2000);
        }
    }
}
