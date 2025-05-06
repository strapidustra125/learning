#include <string>
#include <iostream>

// ---------------------------------------------------------------------------------------------- //

// Интерфейс объявляет операции, которые должны выполнять все конкретные документы
class IDocument
{

public:

    virtual ~IDocument()    = default;

    virtual void create()   = 0;
    virtual void read()     = 0;
    virtual void update()   = 0;
    virtual void remove()   = 0;

};

// Конкретные документы предоставляют различные реализации интерфейса

class TxtDocument : public IDocument
{

public:

    void create()   override    {   std::cout << ".txt document created"    << std::endl; }
    void read()     override    {   std::cout << ".txt document read"       << std::endl; }
    void update()   override    {   std::cout << ".txt document updater"    << std::endl; }
    void remove()   override    {   std::cout << ".txt document removed"    << std::endl; }
};

class DocxDocument : public IDocument
{

public:

    void create()   override    {   std::cout << ".docx document created"    << std::endl; }
    void read()     override    {   std::cout << ".docx document read"       << std::endl; }
    void update()   override    {   std::cout << ".docx document updater"    << std::endl; }
    void remove()   override    {   std::cout << ".docx document removed"    << std::endl; }
};


// ---------------------------------------------------------------------------------------------- //

// Фабрика объявляет фабричный метод, который должен возвращать объект класса IDocument
class DocumentFactory
{

    // Создатель может также обеспечить реализацию фабричного метода по умолчанию

public:

    virtual ~DocumentFactory()                          = default;

    virtual IDocument * FactoryMethod() const   = 0;

    // Также заметьте, что, несмотря на название, основная обязанность Создателя не заключается в
    // создании продуктов. Обычно он содержит некоторую базовую бизнес-логику, которая основана на
    // объектах Продуктов, возвращаемых фабричным методом. Подклассы могут косвенно изменять эту
    // бизнес-логику, переопределяя фабричный метод и возвращая из него другой тип продукта.

    std::string SomeOperation() const
    {
        // Вызываем фабричный метод, чтобы получить объект-продукт.
        IDocument * document = this->FactoryMethod();

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
