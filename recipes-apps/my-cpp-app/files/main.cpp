#include <iostream>
#include <chrono>
#include <thread>
#include "Objects.hpp"

void WifiCallback(Drivers::Wireless::Wifi::WifiState wifiState)
{
    std::cout << "Main: Wifi callback successfull\n";
}

int main()
{
    Objects::wifi.RegisterWifiCallback(WifiCallback);
    while(true)
    {
        std::cout << "Main\n";
        Os::Delay(2000);
    }
}
