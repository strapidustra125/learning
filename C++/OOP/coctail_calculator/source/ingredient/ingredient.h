#ifndef _INGREDIENT_LIB_
#define _INGREDIENT_LIB_

#include "customStrings.h"

class Ingredient
{


// Публичные поля
public:
    // Размерность
    enum dimension
    {
        ml,
        l,
        g,
        kg
    };


public:
    Ingredient(/* args */);
    ~Ingredient();

// Приватные поля
private:
    String _name;
    int _value;

};
















#endif