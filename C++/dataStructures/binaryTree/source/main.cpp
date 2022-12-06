#include <iostream>
#include "binaryTree.h"
#include <vector>



class Class
{
public:
    Class() 
    {
        _field = 5;
    };
    ~Class() {};

    int get()
    {
        return _field;
    }

    void set(int field)
    {
        _field++;
    }

private:
    int _field;
};


bool foo(const Class & object, int val)
{
    // object.get();
    foo1(object);
}

void foo1(Class & object)
{
    object.get();
}


int main()
{
    BinTree<int> tree;

    tree.pushBack(11);

    
    // std::cout << tree.root() << std::endl;

    return 0;
}