#ifndef _CUSTOM_STRINGS_LIB__
#define _CUSTOM_STRINGS_LIB__


class strings
{
private:
    unsigned int stringLength = 0;

    char * stringSymbols;

public:
    strings();
    strings(const char[]);

    ~strings();

    unsigned int length();


};



#endif