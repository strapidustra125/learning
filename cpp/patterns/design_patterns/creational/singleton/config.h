
#ifndef __SINGLETON__CONFIG__
#define __SINGLETON__CONFIG__


#include "t_singleton.h"

#include <cstdint>
#include <mutex>


class Config : public Singleton<Config>
{

protected:

    // Дружимся с базовым синглтоном, чтобы он мог вызывать наш защищенный конструктор при создании
    // ссылки на представление
    friend class Singleton<Config>;

    Config() = default;

private:

    // Мьютекс для блокировки доступа к скрытым полям из разных потоков
    // Вызывается только в сеттерах и геттерах
    std::mutex __mtx_fieldsLock;

    // Какие-то поля с геттерами и сеттерами

    uint32_t __configField_1 = 0;
    uint32_t __configField_2 = 0;

public:

    uint32_t configField_1();
    uint32_t configField_2();

    void set_configField_1(const uint32_t & field);
    void set_configField_2(const uint32_t & field);

};


#endif // __SINGLETON__CONFIG__
