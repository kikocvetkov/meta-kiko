#include <iostream>
#include <chrono>
#include <thread>
#include "Objects.hpp"

int main()
{
    while(true)
    {
        _testOutputPin.SetOutput(Hal::OutputLevel::High);
        std::this_thread::sleep_for(std::chrono::seconds(1));

        _testInputPin.ReadLevel();
        std::this_thread::sleep_for(std::chrono::seconds(1));

        _testOutputPin.SetOutput(Hal::OutputLevel::Low);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        
        _testInputPin.ReadLevel();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
