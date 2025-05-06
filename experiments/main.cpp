#include <string>
#include <iostream>

class Base
{

public:

    Base()              {   std::cout << "Base()" << std::endl;                 }
    ~Base()              {   std::cout << "~Base()" << std::endl;                 }

    void f()    {   std::cout << "Base"                 << std::endl;   }
};

class FirstLevelChild_1 :
    public Base
{

public:

    FirstLevelChild_1() {   std::cout << "FirstLevelChild_1()" << std::endl;    }
    ~FirstLevelChild_1() {   std::cout << "~FirstLevelChild_1()" << std::endl;    }

    // void f()    {   std::cout << "FirstLevelChild_1"    << std::endl;   }
};


class FirstLevelChild_2 :
    public Base
{

public:

    FirstLevelChild_2() {   std::cout << "FirstLevelChild_2()" << std::endl;    }
    ~FirstLevelChild_2() {   std::cout << "~FirstLevelChild_2()" << std::endl;    }

    // void f()    {   std::cout << "FirstLevelChild_2"    << std::endl;   }
};

class SecondLevelChild :
    public FirstLevelChild_1,
    public FirstLevelChild_2
{

public:

    SecondLevelChild()  {   std::cout << "SecondLevelChild()" << std::endl; }
    ~SecondLevelChild()  {   std::cout << "~SecondLevelChild()" << std::endl; }

};


class TestCopyClass
{

public:

    int * a = new int {};

};

int main()
{
    // SecondLevelChild s;


    TestCopyClass one;
    TestCopyClass two;

    *(one.a) = 5;
    // *(two.a) = 5000;


    std::cout << "one = " << *(one.a) << std::endl;
    std::cout << "two = " << *(two.a) << std::endl;

    one = two;


    std::cout << "one = " << *(one.a) << std::endl;
    std::cout << "two = " << *(two.a) << std::endl;

    return 0;





    int a {5};
    int b {50};

    int *       pA          = &a;
    int * const pA_const    = &a;

    // pA_const = &b;


    std::cout << "&pA       = "     << &pA          << std::endl;
    std::cout << "&pA_const = "     << &pA_const    << std::endl;
    std::cout << "pA        = "     << pA           << std::endl;
    std::cout << "pA_const  = "     << pA_const     << std::endl;
    std::cout << "*pA_const = "     << *pA_const     << std::endl;

    return 0;
}
