#pragma once
#include "../Os/Thread.hpp"

namespace Tasks
{
    class BleTask : public Os::Thread
    {
    public:
        BleTask() = default;
        ~BleTask() = default;

        BleTask(const BleTask&) = delete;
        BleTask(BleTask&&) = delete;
        BleTask& operator=(const BleTask&) noexcept = delete;
        BleTask& operator=(BleTask&&) noexcept = delete;

        void Run(std::stop_token stopToken) override;
    };
}
