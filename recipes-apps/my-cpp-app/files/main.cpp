#include <iostream>
#include <chrono>
#include <thread>

// Sleep for seconds

int main()
{
    while(true)
    {
        std::cout << "Hello World";
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}