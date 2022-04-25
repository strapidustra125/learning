#ifndef _COCLAIL_LIB__
#define _COCLAIL_LIB__

#include "customStrings.h"
#include "ingredient.h"
#include <vector>


class Coctail
{
// публичные поля
public:
    // Типы напитка
    enum drinkType
    {
        coctail,    // Коктейль
        tincture,   // Настойка
        syrup,      // Сироп
        liquor      // Ликер
    };  

// Публичные методы
public:
    Coctail();
    ~Coctail();

// Приватные поля
private:
    drinkType _type;
    std::vector<Ingredient> _ingredient;
    int _alcohol;
};















#endif