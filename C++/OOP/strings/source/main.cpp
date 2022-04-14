#include "customStrings.h"
#include <iostream>

int main()
{
    strings s = "test";

    std::cout << "s.length() = " << s.length() << std::endl;

    s.print();

    s = "lol";

    s.print();

    return 0;
}