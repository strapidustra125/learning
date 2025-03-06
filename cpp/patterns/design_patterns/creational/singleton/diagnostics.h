
#ifndef __SINGLETON__DIAGNOSTICS__
#define __SINGLETON__DIAGNOSTICS__


#include "t_singleton.h"


/**
 * Пример класса, не унаследованного от шаблонного класса Singleton
 *
 * Особенности:
 *  - Можно и создать объект класса, и получить ссылку на единственное представление.
 *  - Класс Diagnostics никак не связан с Singleton и может быть отдельной сущностью.
 */
class Diagnostics
{

public:

    Diagnostics();
    ~Diagnostics();

    void someDiagnosticsMethod();

private:

    bool __isDiagRead = false;

};


#endif // __SINGLETON__DIAGNOSTICS__
