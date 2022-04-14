#include "customStrings.h"
#include <iostream>








strings::strings() {}


strings::strings(const char charMas[]) 
{
    for(unsigned int i = 0; charMas[i] != '\0'; i++)
    {
        std::cout << "charMas[" << i << "] = " << charMas[i] << std::endl;

        
    }

    std::cout << "charMas = [" << charMas << "], size = " << sizeof(charMas) << std::endl;

    // this->stringSymbols = malloc(sizeof(charMas));
}

strings::~strings() {}