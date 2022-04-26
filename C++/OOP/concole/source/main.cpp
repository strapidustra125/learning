#include "console.h"
#include "helping.h"
#include <iostream>

#include <ncurses.h>

int main()
{
    Console console;
    char c;

    // console.printMenu1();

    // std::cout << "_printedSymbolsNumber = " << console._printedSymbolsNumber << std::endl;

    // console.clearConsole();

    // while(1)
    // {
    //     c = std::getchar();
        

    //     std::cout << (int)c << std::endl;
    // }

    // std::cout << "\n\nYEY\n\n";

    // console.clearConsole();
    // console.printMenu(console._menu1);
    // console.clearConsole();
    

    help::sleep_ms(20000);

    console.printMenu(console._menu2);

    std::cout << std::flush;


    help::sleep_ms(10000);

    return 0;
}