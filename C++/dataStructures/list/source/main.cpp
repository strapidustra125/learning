#include "customStrings.h"
#include <iostream>
#include "list.h"
#include <vector>

int main()
{
    List<String> list;

    list.pushBack("1");
    list.pushBack("2");
    
    list.insert("132", 0);


    std::cout << "List:" << std::endl;

    for(unsigned int i = 0; i < list.size(); i++)
    {
        std::cout << "\t" << list[i] << std::endl;
    }
    

    return 0;
}