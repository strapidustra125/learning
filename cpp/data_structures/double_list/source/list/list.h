#ifndef _LIST_LIB_
#define _LIST_LIB_

#include <iostream>
#include <vector>
#include "customStrings.h"

template<typename T>
class List
{
public:
    template<typename Type>
    class Node
    {
    public:
        Node * _pNext;
        Type _data;
        
        Node(Type data=Type(), Node * pNext=nullptr)
        {
            this->_data = data;
            this->_pNext = pNext;
        }
        ~Node() {}
    };
    
    unsigned int _length;
    Node<T> * _head;

public:

    List();
    ~List();


    // Функции

    void pushBack(T data);
    unsigned int size();
    bool insert(T data, int index);
    bool remove(int index);
    void clear();

    void __DEBUG__PRINT__();

    unsigned int begin();
    unsigned int end();



    // Оператор обращения по индексу
    T& operator [] (int index);
};



template<typename T>
List<T>::List()
{
    this->_length = 0;
    this->_head = nullptr;
}


template<typename T>
List<T>::~List()
{
    Node<T> * current = this->_head;
    Node<T> * next;


    while(this->_length > 0)
    {
        next = current->_pNext;

        std::cout << "delete [" << current << "]\n";
        std::cout << "length =" << this->_length << "\n";

        delete current;

        current = next;

        this->_length--;
    }
}

template<typename T>
void List<T>::pushBack(T data)
{
    if(this->_head == nullptr)
    {
        this->_head = new Node<T>(data);
    }
    else
    {
        Node<T> * current = this->_head;

        while(current->_pNext != nullptr)
        {
            current = current->_pNext;
        }
        current->_pNext = new Node<T>(data);
    }

    this->_length++;
}


template<typename T>
unsigned int List<T>::size()
{
    return this->_length;
}


template<typename T>
bool List<T>::insert(T data, int index)
{
    Node<T> * current = this->_head;
    Node<T> * next;
    int counter = 0;

    if(index > (int)this->_length) 
    {
        throw std::runtime_error("list.h --> bool List<T>::insert : Index overflow!");
        return false;
    }
    if(index < 0)
    {
        throw std::runtime_error("list.h --> bool List<T>::insert : Negative index value!");
        return false;
    }

    if(index == 0)
    {
        next = this->_head;
        this->_head = new Node<T>(data, next);
    }
    else
    {
        while(counter < index - 1)
        {
            current = current->_pNext;
            counter++;
        }

        next = current->_pNext;
        current->_pNext = new Node<T>(data, next);
    }

    this->_length++;

    return true;
}


template<typename T>
bool List<T>::remove(int index)
{
    Node<T> * previous = this->_head;
    Node<T> * current = previous->_pNext;
    int counter = 0;

    if(index > (int)this->_length) 
    {
        throw std::runtime_error("list.h --> bool List<T>::insert : Index overflow!");
        return false;
    }
    if(index < 0)
    {
        throw std::runtime_error("list.h --> bool List<T>::insert : Negative index value!");
        return false;
    }

    if(index == 0)
    {
        this->_head = previous->_pNext;

        delete previous;
    }
    else
    {
        while(counter < index - 1)
        {
            previous = previous->_pNext;
            current = current->_pNext;
            counter++;
        }

        previous->_pNext = current->_pNext;
        delete current;        
    }

    this->_length--;
    return true;
}


template<typename T>
void List<T>::clear()
{
    Node<T> * current = this->_head;
    Node<T> * next = current->_pNext;


    while(this->_length > 0)
    {
        next = current->_pNext;

        delete current;

        current = next;

        this->_length--;
    }

    this->_head = nullptr;
}








template<typename T>
void List<T>::__DEBUG__PRINT__()
{
    Node<T> * current = this->_head;
    int counter = 0;

    while(current != nullptr)
    {
        std::cout << "List[" << counter << "] = [" << current << "][" 
            << current->_data << "]" << std::endl;

        current = current->_pNext;
        counter++;
    }
}




// Оператор обращения по индексу
template<typename T>
T& List<T>::operator [] (int index)
{
    Node<T> * current = this->_head;
    int counter = 0;

    if(index > (int)this->_length) 
        throw std::runtime_error("list.h --> T& List<T>::operator [] : Index overflow!");
    if(index < 0) 
        throw std::runtime_error("list.h --> T& List<T>::operator [] : Negative index value!");
    
    while(current != nullptr)
    {
        if(counter == index) return current->_data;

        current = current->_pNext;
        counter++;
    }

    // Чтобы не было варнинга
    return current->_data;
}






#endif