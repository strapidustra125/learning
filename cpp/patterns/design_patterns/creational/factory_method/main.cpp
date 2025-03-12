#include <string>
#include <iostream>

// ---------------------------------------------------------------------------------------------- //

// Интерфейс Продукта объявляет операции, которые должны выполнять все конкретные продукты.
class IFurniture
{

public:

    virtual ~IFurniture() {}
    virtual std::string Operation() const = 0;

};

// Конкретные Продукты предоставляют различные реализации интерфейса Продукта.

class Table : public IFurniture
{

public:

    std::string Operation() const override
    {
        return "{Result of the Table}";
    }
};

class Chair : public IFurniture
{

public:

    std::string Operation() const override
    {
        return "{Result of the Chair}";
    }
};


// ---------------------------------------------------------------------------------------------- //

/**
 * Класс Создатель объявляет фабричный метод, который должен возвращать объект класса Продукт.
 * Подклассы Создателя обычно предоставляют реализацию этого метода.
 */
class Factory
{

    /**
     * Обратите внимание, что Создатель может также обеспечить реализацию
     * фабричного метода по умолчанию.
     */

public:

    virtual ~Factory(){};
    virtual IFurniture * FactoryMethod() const = 0;

    /**
     * Также заметьте, что, несмотря на название, основная обязанность Создателя
     * не заключается в создании продуктов. Обычно он содержит некоторую базовую
     * бизнес-логику, которая основана на объектах Продуктов, возвращаемых
     * фабричным методом. Подклассы могут косвенно изменять эту бизнес-логику,
     * переопределяя фабричный метод и возвращая из него другой тип продукта.
     */

    std::string SomeOperation() const
    {
        // Вызываем фабричный метод, чтобы получить объект-продукт.
        IFurniture * product = this->FactoryMethod();

        // Далее, работаем с этим продуктом.
        std::string result = "Factory: The same Factory's code has just worked with " + product->Operation();

        delete product;

        return result;
    }
};

// ---------------------------------------------------------------------------------------------- //

/**
 * Конкретные Создатели переопределяют фабричный метод для того, чтобы изменить
 * тип результирующего продукта.
 *
 * Обратите внимание, что сигнатура метода по-прежнему использует тип
 * абстрактного продукта, хотя фактически из метода возвращается конкретный
 * продукт. Таким образом, Создатель может оставаться независимым от
 * конкретных классов продуктов.
 */
class TableFactory : public Factory
{

public:

    IFurniture * FactoryMethod() const override
    {
        return new Table();
    }
};

class ChairFactory : public Factory
{

public:

    IFurniture * FactoryMethod() const override
    {
        return new Chair();
    }
};

// ---------------------------------------------------------------------------------------------- //

/**
 * Клиентский код работает с экземпляром конкретного создателя, хотя и через его
 * базовый интерфейс. Пока клиент продолжает работать с создателем через базовый
 * интерфейс, вы можете передать ему любой подкласс создателя.
 */
void ClientCode(const Factory & Factory)
{
// ...
    std::cout << "Client: I'm not aware of the Factory's class, but it still works.\n"
              << Factory.SomeOperation() << std::endl;
// ...
}

// ---------------------------------------------------------------------------------------------- //

// Приложение выбирает тип создателя в зависимости от конфигурации или среды.

int main()
{
    std::cout << "App: Launched with the TableFactory.\n";

    Factory * tableFactory = new TableFactory();
    ClientCode(*tableFactory);

    std::cout << std::endl;

    std::cout << "App: Launched with the ChairFactory.\n";

    Factory * chairFactory = new ChairFactory();
    ClientCode(*chairFactory);

    delete tableFactory;
    delete chairFactory;

    return 0;
}
