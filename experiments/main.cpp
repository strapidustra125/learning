#include <string>
#include <iostream>


class Foo
{
    uint64_t i;
    uint8_t a;

    virtual void method()
    {
        i++;
    }

    virtual void method2()
    {
        i++;
    }
};







int main()
{
    std::cout << sizeof(Foo) << " bytes" << std::endl;

    return 0;
}
