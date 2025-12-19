#pragma once

#include <thread>

namespace Os
{
    void Delay(std::size_t milliseconds);

    class Thread
    {
    public:
        Thread();
        ~Thread() = default;


        Thread(const Thread&) = delete;
        Thread(Thread&&) = delete;
        Thread& operator=(const Thread&) noexcept = delete;
        Thread& operator=(Thread&&) noexcept = delete;

        virtual void Run(std::stop_token stopToken) = 0;

    private:

        std::jthread _thread;
        bool run;
    };
}
