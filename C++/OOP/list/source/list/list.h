#ifndef _TREE_LIB__
#define _TREE_LIB__

#include <iostream>
#include <vector>
#include "customStrings.h"

template<typename T>
class Tree
{
private:
    


public:

    Tree();

    Tree(Type data)
    {
        
    }

    ~Tree();

    void print();






    // Индекс вершины
    static unsigned int _index = 0;

    // Имя, по которому искать элемент
    String _itemName;

    // Полезные данные любого типа
    T _data;

    // Указатель на родителя
    Tree * _pParent;

    // Массив адресов детей
    std::vector<Tree> * _children;




    // Функции

    // Добавить ребенка

    // Удалить поддерево

    // Обход дерева





    // Перегрузить оператор обращения по индексу

    // Оператор обращения по индексу
    const T& operator [] (String name)
    {

    }

};







template<typename T>
void Tree<T>::print()
{

}









#endif