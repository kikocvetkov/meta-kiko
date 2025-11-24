#include <iostream>
#include <chrono>
#include <thread>
#include "Objects.hpp"

int main()
{
    while(true)
    {
        std::cout << "Main\n";
        Os::Delay(2000);
    }
}
