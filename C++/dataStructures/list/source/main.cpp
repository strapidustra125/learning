#include "customStrings.h"
#include <iostream>
#include "list.h"
#include <vector>

int main()
{
    List<int> list;


    // list.pushBack("1");
    // list.pushBack("2");
    // list.pushBack("3");

    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);

    list.__DEBUG__PRINT__();

    


    list.clear();

    std::cout << list.size() << std::endl;

    list.__DEBUG__PRINT__();



    list.~List();
    

    return 0;
}