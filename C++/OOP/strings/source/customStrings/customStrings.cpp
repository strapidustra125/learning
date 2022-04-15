#include "customStrings.h"
#include <iostream>




void String::_clear()
{
    if(this->_stringSymbols != nullptr) delete[] this->_stringSymbols;

    this->_stringLength = 0;
}

void String::_create(const char charMas[])
{
    unsigned int strLength = 0;
    for(unsigned int i = 0; charMas[i] != '\0'; i++) strLength++;

    this->_stringSymbols = new char[strLength];

    for(unsigned int i = 0; i < strLength; i++) 
        this->_stringSymbols[i] = charMas[i];

    this->_stringLength = strLength;
}

void String::_create(const String& string)
{
    unsigned int strLength = string._stringLength;

    this->_stringSymbols = new char[strLength];

    for(unsigned int i = 0; i < strLength; i++) 
        this->_stringSymbols[i] = string._stringSymbols[i];
    
    this->_stringLength = strLength;
}





String::String() 
{
    std::cout << "Default constructor" << std::endl;
}

String::String(const char charMas[]) 
{
    std::cout << "Reload constructor" << std::endl;

    this->_create(charMas);
}

String::String(const String& string) 
{
    std::cout << "Copy constructor" << std::endl;

    this->_create(string);
}

String::~String() 
{
    std::cout << "Destructor" << std::endl;

    this->_clear();
}






unsigned int String::length()
{
    return _stringLength;
}

char String::symbol(unsigned int i)
{
    return this->_stringSymbols[i];
}

void String::print()
{
    for(unsigned int i = 0; i < _stringLength; i++) std::cout << _stringSymbols[i];
}




// Операторы

const String& String::operator = (const char charMas[])
{
    this->_create(charMas);
    return *this;
}

const String& String::operator = (const String& string)
{
    this->_create(string);
    return *this;
}

const String& String::operator + (const char charMas[])
{
    String tempString;
    unsigned int inputStrLength = 0;
    for(unsigned int i = 0; charMas[i] != '\0'; i++) inputStrLength++;
    unsigned int newStringLength = this->_stringLength + inputStrLength;

    tempString._stringSymbols = new char[newStringLength];

    unsigned int i = 0, j = 0;
    for(; i < this->_stringLength; i++)
        tempString._stringSymbols[i] = this->_stringSymbols[i];
    
    for(; i < newStringLength; i++, j++)
        tempString._stringSymbols[i] = charMas[j];

    tempString._stringLength = newStringLength;    

    *this = tempString;

    return *this;
}

const String& String::operator + (const String& string)
{
    String tempString;
    unsigned int newStringLength = this->_stringLength + string._stringLength;

    tempString._stringSymbols = new char[newStringLength];

    unsigned int i = 0, j = 0;
    for(; i < this->_stringLength; i++)
        tempString._stringSymbols[i] = this->_stringSymbols[i];
    
    for(; i < newStringLength; i++, j++)
        tempString._stringSymbols[i] = string._stringSymbols[j];

    tempString._stringLength = newStringLength;    

    *this = tempString;

    return *this;
}

const String& String::operator + (char symbol)
{
    String tempString;
    unsigned int newStringLength = this->_stringLength + 1;

    tempString._stringSymbols = new char[newStringLength];

    unsigned int i = 0;
    for(; i < this->_stringLength; i++)
        tempString._stringSymbols[i] = this->_stringSymbols[i];
    
    tempString._stringSymbols[i] = symbol;

    tempString._stringLength = newStringLength;    

    *this = tempString;

    return *this;
}

const char& String::operator [] (int i)
{
    return this->_stringSymbols[i];
}

bool String::operator == (const String& string)
{
    if(this->_stringLength != string._stringLength) return false;
    else
    {
        for(unsigned int i = 0; i < this->_stringLength; i++) 
            if(this->_stringSymbols[i] != string._stringSymbols[i]) return false;
        
        return true;
    }
}

bool String::operator != (const String& string)
{
    if(this->_stringLength != string._stringLength) return true;
    else
    {
        for(unsigned int i = 0; i < this->_stringLength; i++) 
            if(this->_stringSymbols[i] != string._stringSymbols[i]) return true;
        
        return false;
    }
}

std::ostream& operator << (std::ostream &out, const String& string)
{
    for(unsigned int i = 0; i < string._stringLength; i++)
    {
        out << string._stringSymbols[i];
    }
    return out;
}
