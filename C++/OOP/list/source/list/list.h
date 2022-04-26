#ifndef _LIST_LIB_
#define _LIST_LIB_

#include <iostream>
#include <vector>
#include "customStrings.h"

template<typename T>
class List
{
private:
    


public:

    // Полезные данные любого типа
    template<typename T>
    class Node
    {
    public:
        Node * _pNext;
        T _data;
        
        Node(T data=T(), Node * pNext=nullptr)
        {
            this->_data = data;
            this->_pNext = pNext;
        }
        ~Node() {}
    };
    
    unsigned int _length;
    Node<T> * _head;
    




    // Функции

    void pushBack(T data);



    List();

    List(Type data)
    {
        
    }

    ~List();


    // Оператор обращения по индексу
    const T& operator [] (String name) {}
};


template<typename T>
void List<T>::pushBack(T data)
{
    if(this->_head == nullptr)
    {

    }
    else
    {
        
    }
}











#endif