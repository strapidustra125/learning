#include "customStrings.h"
#include <iostream>

int main()
{
    String s2 = "aaaa";
    char s3 = 's';
    String s1;
    
    s1 = s2 + s3;

    s1.print();
    std::cout << std::endl;
    

    return 0;
}