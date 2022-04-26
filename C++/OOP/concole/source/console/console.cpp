#include "console.h"
#include "getch.h"
#include <iostream>


Console::Console(/* args */)
{
    while(1) {std::cout << (int)getch() << std::endl << std::endl;}
}

Console::~Console()
{
}

void Console::printMenu1()
{
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < _menu1[i].length(); j++)
        {
            std::cout << _menu1[i][j];
            _printedSymbolsNumber++;
        }
        std::cout << std::endl;
        _printedSymbolsNumber++;
    }
}

void Console::clearConsole()
{
    std::cout << "\033[2J\033[1;1H";
}

void Console::printMenu(std::vector<String> menu)
{
    for(std::vector<String>::iterator it = menu.begin(); it < menu.end(); it++)
    {
        std::cout << *it;

        if(it != menu.end()-1) std::cout << "\n";
    }
            
    std::cout << std::flush;
}

void Console::processMenu(std::vector<String> menu)
{
    this->clearConsole();
    this->printMenu(menu);

}