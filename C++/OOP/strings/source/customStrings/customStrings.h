#ifndef _CUSTOM_STRINGS_LIB__
#define _CUSTOM_STRINGS_LIB__

#include <iostream>


class String
{
// Приватные поля
private:
    // Текущая длина строки
    unsigned int _stringLength = 0;

    // Массив символов текущей строки
    char * _stringSymbols;

// Приватные методы
private:
    // Очистка значений полей: обнуление длины и удаление указателя на массив символов
    void _clear();

    // Инициализация новой строки из массива символов
    void _create(const char charMas[]);

    // Инициализация новой строки из другой строки такого же типа
    void _create(const String& string);

// Публичные методы
public:
    // Конструктор по-умолчанию
    String();

    // Конструктор создания строки из массива символов
    String(const char[]);

    // Конструктор копирования
    String(const String& string);

    // Деструктор
    ~String();


    // Получение значения поля _stringLength
    unsigned int length();

    // Получение значения массива символов _stringSymbols по индексу i
    char symbol(unsigned int i);


    // Перегрузка операторов

    // Присваивание значения массива символов текущей строке
    const String& operator = (const char charMas[]);

    // Присваивание значения строки такого же типа текущей строке
    const String& operator = (const String& string);

    // Конкатенация текущей строки и массива символов
    const String& operator + (const char charMas[]);

    // Конкатенация текущей строки и строки такого же типа
    const String& operator + (const String& string);

    // Конкатенация текущей строки и одиночного символа
    const String& operator + (char symbol);

    // Оператор обращения по индексу
    const char& operator [] (int i);

    // Оператор посимвольного равенства
    bool operator == (const String& string);

    // Оператор посимвольного неравенства
    bool operator != (const String& string);


    // Дружественная функция перегрузки оператора записи в поток вывода
    friend std::ostream& operator << (std::ostream &out, const String& string);
};


#endif