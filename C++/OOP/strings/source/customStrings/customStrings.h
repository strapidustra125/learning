#ifndef _CUSTOM_STRINGS_LIB__
#define _CUSTOM_STRINGS_LIB__

#include <iostream>


class String
{
private:
    unsigned int _stringLength = 0;

    char * _stringSymbols;

    void _clear();
    void _create(const char charMas[]);
    void _create(const String& string);

public:
    String();
    String(const char[]);
    String(const String& string);

    ~String();

    unsigned int length();
    char symbol(unsigned int i);

    void print();

    




    // Операторы

    const String& operator = (const char charMas[]);
    const String& operator = (const String& string);

    const String& operator + (const char charMas[]);
    const String& operator + (const String& string);
    const String& operator + (char symbol);

    const char& operator [] (int i);

    bool operator == (const String& string);
    bool operator != (const String& string);




    friend std::ostream& operator << (std::ostream &out, const String& string);





    // std::ostream& operator << (std::ostream &out);

};


#endif