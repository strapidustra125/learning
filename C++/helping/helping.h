/***********************************************************************************************
 * 
 * Вспомогательные функции: описание.
 * 
 * hexStringFromInt
 * isRusLetter
 * isDigit
 * digitsVectorFromString
 * getLastDigitPionter
 * getFirstDigitPionter
 * stringToWstring
 * sleep_ms
 * timeIsUp
 * isIPv4Address 
 * 
 **********************************************************************************************/

#ifndef rim_HELPING_H_
#define rim_HELPING_H_


/* ================================== Подключение библиотек ================================= */

// Системные библиотеки
#include <string>
#include <chrono>
#include <ctime> 
#include <vector>


/* ==================================== Описание функций ==================================== */

namespace help
{
    // Перевод числа в HEX-строку для печати с дописыванием '0x' в начало
    std::string hexStringFromInt(int intNumber);
    std::string hexStringFromInt(short unsigned int intNumber);

    // Проверка кода wchar_t символа на попадание в диапазон кодов русских букв 
    bool isRusLetter(wchar_t symbol);

    // Проверка: является ли символ цифрой
    bool isDigit(wchar_t symbol);
    bool isDigit(char symbol);

    // Формирование вектора цифр из строки
    std::vector<int> digitsVectorFromString(std::string inputString);

    // Индекс первой русской буквы в строке wstring
    int getFirstRusLetterPointer(std::wstring inputString);

    // Индекс последней цифры в строке wstring
    int getLastDigitPointer(std::wstring inputString);

    // Индекс первой цифры в строке wstring
    int getFirstDigitPointer(std::wstring inputString);

    // Конвертация string в wstring
    std::wstring stringToWstring(std::string stdString);

    // Конвертация wstring в string
    std::string wstringToString(std::wstring stdWstring);

    // Код числа из входного символа wchar_t
    int wchartToInt(wchar_t inputSymbol);

    // Усыпить текущий поток на time_ms миллисекунд
    void sleep_ms(unsigned int time_ms);

    // Проверка прошло ли timeLaps_ms миллисекунд с момента времени startTime
    bool timeIsUp(unsigned int timeLaps_ms, 
                  std::chrono::_V2::system_clock::time_point startTime);

    // Проверка: является ли строка IPv4 адресом
    bool isIPv4Address(std::string IPAddress);
}

#endif