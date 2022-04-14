#ifndef _CUSTOM_STRINGS_LIB__
#define _CUSTOM_STRINGS_LIB__


class strings
{
private:
    unsigned int _stringLength = 0;

    char * _stringSymbols;

    void _clear();
    void _create(const char charMas[]);

public:
    strings();
    strings(const char[]);

    ~strings();

    unsigned int length();

    void print();

    




    // Операторы

    const strings& operator = (const char charMas[]);


};



#endif