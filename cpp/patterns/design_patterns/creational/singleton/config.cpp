#include "config.h"

#include <iostream>
#include <thread>


uint32_t Config::configField_1()
{
    std::lock_guard<std::mutex> lock(__mtx_fieldsLock);

    std::cout << "thread " << std::this_thread::get_id() << ": configField_1 value was Get"
              << ", configField_1 value: " << __configField_1 << std::endl;

    return __configField_1;
}

uint32_t Config::configField_2()
{
    std::lock_guard<std::mutex> lock(__mtx_fieldsLock);

    std::cout << "thread " << std::this_thread::get_id() << ": configField_2 value was Get"
              << ", configField_2 value: " << __configField_2 << std::endl;

    return __configField_2;
}

void Config::set_configField_1(const uint32_t & field)
{
    std::lock_guard<std::mutex> lock(__mtx_fieldsLock);

    std::cout << "thread " << std::this_thread::get_id() << ": configField_1 value was Set"
              << ", configField_1 value: " << __configField_1 << " -> " << field << std::endl;

    __configField_1 = field;
}

void Config::set_configField_2(const uint32_t & field)
{
    std::lock_guard<std::mutex> lock(__mtx_fieldsLock);

    std::cout << "thread " << std::this_thread::get_id()<< ": configField_2 value was Set"
              << ", configField_2 value: " << __configField_2 << " -> " << field << std::endl;

    __configField_2 = field;
}