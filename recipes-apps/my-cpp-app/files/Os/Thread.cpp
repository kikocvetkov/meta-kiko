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
        Thread::Run();
     }
}
