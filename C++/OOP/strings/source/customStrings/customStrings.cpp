#include "customStrings.h"
#include <iostream>








strings::strings() 
{
    std::cout << "Default constructor" << std::endl;
}


strings::strings(const char charMas[]) 
{
    
    std::cout << "Reload constructor" << std::endl;

    this->_create(charMas);
}

strings::~strings() 
{
    std::cout << "Destructor" << std::endl;

    this->_clear();
}



unsigned int strings::length()
{
    return _stringLength;
}


void strings::print()
{
    for(unsigned int i = 0; i < _stringLength; i++) std::cout << _stringSymbols[i];

    std::cout << std::endl;
}



void strings::_clear()
{
    if(this->_stringSymbols != nullptr) delete[] this->_stringSymbols;
    this->_stringLength = 0;
}



void strings::_create(const char charMas[])
{
    this->_stringSymbols = new char[sizeof(const char)];

    for(unsigned int i = 0; charMas[i] != '\0'; i++)
    {
        this->_stringSymbols[i] = charMas[i];
        this->_stringLength++;
    }
}







// Операторы


const strings& strings::operator = (const char charMas[])
{
    this->_clear();
    this->_create(charMas);
    

    return *this;
}
