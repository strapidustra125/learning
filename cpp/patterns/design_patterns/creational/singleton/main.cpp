#include "config.h"
#include "diagnostics.h"

#include <iostream>


int main()
{
    // ------------------------------------------------------------------------------------------ //
    // Тесты конфигурации
    // Config наследуется от Singleton и не имеет открытых конструкторов

    // Config config;   // Нельзя
    Config & config = Config::instance();
    Config & config_ref1 = Singleton<Config>::instance();
    Config & config_ref2 = Singleton<Config>::instance();

    config_ref1.configField_1();
    config_ref2.set_configField_1(123);
    config_ref1.configField_1();
    config.configField_1();

    // Все ссылки указывают на один объект, произвольное создание объекта запрещено

    // ------------------------------------------------------------------------------------------ //
    // Тесты диагностики
    // Diagnostics не наследуется от Singleton

    Diagnostics diagnostics;
    // Diagnostics & diagnostics = Diagnostics::instance();     // Нельзя
    Diagnostics & diagnostics_ref1 = Singleton<Diagnostics>::instance();
    Diagnostics & diagnostics_ref2 = Singleton<Diagnostics>::instance();

    // Обе ссылки указывают на один объект, но так же можно создавать отдельные экземпляры класса

    diagnostics_ref2.someDiagnosticsMethod();
    diagnostics_ref1.someDiagnosticsMethod();

    return 0;
}
