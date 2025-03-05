#include "config.h"

#include <thread>
#include <chrono>
#include <iostream>

void iterative(Config & config)
{
    uint8_t iterations = 10;
    while(--iterations)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        config.set_configField_2(22);
        config.configField_1();
        config.set_configField_1(11);
        config.configField_2();
    }
}

int main()
{
    Config & config = Config::instance();

    std::thread thread{iterative, std::ref(config)};

    iterative(config);

    thread.join();

    return 0;
}
