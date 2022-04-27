#ifndef _MENU_LIB_
#define _MENU_LIB_

#include <iostream>
#include <string>
#include <vector>
#include "customStrings.h"


class Menu
{

public:
    Menu();
    ~Menu();

    void printMenu1();
    void clearConsole();

    void printMenu(std::vector<String> menu);
    void processMenu(std::vector<String> menu);

public:


    // Список пунктов меню
    std::vector<String> _items;

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