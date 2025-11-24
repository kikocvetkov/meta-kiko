#include "Thread.hpp"

namespace Os
{
    Thread::Thread() :
     _thread{&Thread::ThreadBegin, this}
     {
        _thread.detach();
     }

     void Thread::ThreadBegin()
     {
        _thread = std::thread([this]() {
            this->Run();
        });
     }

     void Delay(std::size_t milliseconds)
     {
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
     }
}
