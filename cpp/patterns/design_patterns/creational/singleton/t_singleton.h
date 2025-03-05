
#ifndef __SINGLETON__SINGLETON__
#define __SINGLETON__SINGLETON__


#include <iostream>

// Создается шаблонный класс, от которого будут наследоваться другие синглтоны
// При объявлении, наследуемый класс вместо T подставляет свое имя
// Также наследующий класс должен объявить свои конструкторы защищенными и добавить Singleton
// в друзья: friend class Singleton<Config>;
template <class T>
class Singleton
{

protected:

    // Конструктор по умолчанию защищенный, чтобы он был доступен только в наследниках, но не был
    // доступен пользователю
    Singleton()     = default;
    ~Singleton()    = default;

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


#endif // __SINGLETON__SINGLETON__
