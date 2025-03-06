#include "config.h"

#include <iostream>


Config::Config()
{
    std::cout << "Config constructor was called" << std::endl;
}

Config::~Config()
{
    std::cout << "Config destructor was called" << std::endl;
}

uint32_t Config::configField_1()
{
    std::lock_guard<std::mutex> lock(__mtx_fieldsLock);

    std::cout << "configField_1 value: " << __configField_1 << std::endl;

    return __configField_1;
}

uint32_t Config::configField_2()
{
    std::lock_guard<std::mutex> lock(__mtx_fieldsLock);

    std::cout << "configField_2 value: " << __configField_2 << std::endl;

    return __configField_2;
}

void Config::set_configField_1(const uint32_t & field)
{
    std::lock_guard<std::mutex> lock(__mtx_fieldsLock);

    std::cout << "configField_1 value: " << __configField_1 << " -> " << field << std::endl;

    __configField_1 = field;
}

void Config::set_configField_2(const uint32_t & field)
{
    std::lock_guard<std::mutex> lock(__mtx_fieldsLock);

    std::cout << "configField_2 value: " << __configField_2 << " -> " << field << std::endl;

    __configField_2 = field;
}
