#pragma once

#include <thread>

namespace Os
{
    class Thread
    {
    public:
        Thread();
        ~Thread() = default;

        virtual void Run() = 0;

    private:
        void ThreadBegin();

        std::thread _thread;
        bool run;
    };
}
