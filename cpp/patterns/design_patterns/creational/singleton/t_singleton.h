
#ifndef __SINGLETON__T_SINGLETON__
#define __SINGLETON__T_SINGLETON__


#include <iostream>


/**
 * Шаблон паттерна Singleton
 * Можно как наследовать от него и получать полноценный синглтон, так и вызывать
 * При объявлении, наследуемый класс вместо T подставляет свое имя
 * Также наследующий класс должен объявить свои конструкторы защищенными и добавить Singleton
 * в друзья: friend class Singleton<Config>;
 */
template <class T>
class Singleton
{

protected:

    Singleton()                                 = default;
    ~Singleton()                                = default;

public:

    // Ссылка на представление класса
    static T & instance()
    {
        static T instance;
        return instance;
    }

    Singleton(const Singleton &)                = delete;
    Singleton & operator= (const Singleton &)   = delete;

};


#endif // __SINGLETON__T_SINGLETON__
