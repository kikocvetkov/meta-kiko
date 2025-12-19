#include "Thread.hpp"

namespace Os
{
    Thread::Thread() :
     _thread([this](std::stop_token stopToken) { this->Run(stopToken); })
     {
     }

     void Delay(std::size_t milliseconds)
     {
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
     }
}
