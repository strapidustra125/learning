#ifndef _CONSOLE_LIB_
#define _CONSOLE_LIB_

#include <iostream>
#include <string>
#include <vector>
#include "customStrings.h"


class Console
{

public:
    Console(/* args */);
    ~Console();

    void printMenu1();
    void clearConsole();

    void printMenu(std::vector<String> menu);
    void processMenu(std::vector<String> menu);

public:

    std::vector<String> _menu1 = 
    {
        "",
        "     1 - Поиск",
        "     2 - Выход",
        "     3 - Вход",
        "     4 - что-то",
        "",
        "",
        "",
        "ввод: "
    };

    std::vector<String> _menu2 = 
    {
        "",
        "     1 - Поиск",
        "     2 - Выход",
        "     3 - Вход",
        "     4 - что-то",
        "",
        "123",
        "123"
    };

// private:
    unsigned int _printedSymbolsNumber = 0;

};





#endif