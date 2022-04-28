/***********************************************************************************************
 * 
 * Вспомогательные функции: реализация.
 * 
 **********************************************************************************************/


/* ================================== Подключение библиотек ================================= */

#include "helping.h"

// Системные библиотеки
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <locale>         // std::wstring_convert
#include <codecvt>        // std::codecvt_utf8
#include <thread>
#include <chrono>


/* =================================== Реализация функций =================================== */

namespace help
{
    // ---------------------------------------------------------------------------------- //

    // Перевод числа int в HEX-строку для печати
    std::string hexStringFromInt(int intNumber)
    {
        if(intNumber == 0) return "0x0";
        if(intNumber < 0) return "incorrect_input";

        std::string hexString = "";
        std::string hexSymbols = "0123456789ABCDEF";

        while(intNumber > 0)
        {
            hexString += hexSymbols[intNumber%16];
            intNumber /= 16;
        }

        std::reverse(hexString.begin(), hexString.end());
        return "0x" + hexString;
    }

    // Перевод числа short unsigned int (uint16_t) в HEX-строку для печати
    std::string hexStringFromInt(short unsigned int intNumber)
    {
        if(intNumber == 0) return "0x0";

        std::string hexString = "";
        std::string hexSymbols = "0123456789ABCDEF";

        while(intNumber > 0)
        {
            hexString += hexSymbols[intNumber%16];
            intNumber /= 16;
        }

        std::reverse(hexString.begin(), hexString.end());
        return "0x" + hexString;
    }

    // ---------------------------------------------------------------------------------- //

    // Проверка кода wchar_t символа на попадание в диапазон кодов русских букв 
    bool isRusLetter(wchar_t symbol)
    {
        if(((int)symbol >= 1040 && (int)symbol <= 1103) || (int)symbol == 1105 || 
            (int)symbol == 1025)
        {
            return true;
        }
        else return false;
    }

    // ---------------------------------------------------------------------------------- //

    // Проверка: является ли wchar_t символ цифрой
    bool isDigit(wchar_t symbol)
    {
        if((int)symbol >= 48 && (int)symbol <= 57) return true;
        else return false;
    }

    // Проверка: является ли char символ цифрой
    bool isDigit(char symbol)
    {
        if((int)symbol >= 48 && (int)symbol <= 57) return true;
        else return false;
    }

    // ---------------------------------------------------------------------------------- //

    // Формирование вектора цифр из строки
    std::vector<int> digitsVectorFromString(std::string inputString)
    {
        std::vector<int> result;
        for(unsigned int i = 0; i < inputString.length(); i++)
        {
            if(isDigit(inputString[i]))
            {
                result.push_back((int)inputString[i] - 48);
            }
        }
        return result;
    }

    // ---------------------------------------------------------------------------------- //

    // Индекс первой русской буквы в строке wstring
    int getFirstRusLetterPointer(std::wstring inputString)
    {
        for(unsigned int i = 0; i < inputString.length(); i++)
            if(isRusLetter(inputString[i])) return i;

        return -1;
    }

    // ---------------------------------------------------------------------------------- //

    // Индекс последней цифры в строке wstring
    int getLastDigitPointer(std::wstring inputString)
    {
        int lastDigitPionter = -1;
        for(unsigned int i = 0; i < inputString.length(); i++)
            if(isDigit(inputString[i])) lastDigitPionter = i;
        
        return lastDigitPionter;
    }

    // ---------------------------------------------------------------------------------- //

    // Индекс первой цифры в строке wstring
    int getFirstDigitPointer(std::wstring inputString)
    {
        for(unsigned int i = 0; i < inputString.length(); i++)
            if(isDigit(inputString[i])) return i;

        return -1;
    }

    // ---------------------------------------------------------------------------------- //

    // Конвертация string в wstring
    std::wstring stringToWstring(std::string stdString)
    {
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        std::wstring stdWString = converter.from_bytes(stdString);
        return stdWString;
    }

    // ---------------------------------------------------------------------------------- //

    // Конвертация wstring в string
    std::string wstringToString(std::wstring stdWstring)
    {
        using convert_type = std::codecvt_utf8<wchar_t>;
        std::wstring_convert<convert_type, wchar_t> converter;
        return converter.to_bytes(stdWstring);
    }

    // ---------------------------------------------------------------------------------- //

    // Код числа из входного символа wchar_t
    int wchartToInt(wchar_t inputSymbol)
    {
        if(!isDigit(inputSymbol)) return -1;
        std::wstring wstr = L"";
        wstr += inputSymbol;
        return std::stoi(wstr);
    }

    // ---------------------------------------------------------------------------------- //

    // Усыпить текущий поток на time_ms миллисекунд (для краткости вызова функции)
    void sleep_ms(unsigned int time_ms)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(time_ms));
    }

    /// ---------------------------------------------------------------------------------- //

    // Проверка прошло ли timeLaps_ms миллисекунд с момента времени startTime
    bool timeIsUp(unsigned int timeLaps_ms, 
                  std::chrono::_V2::system_clock::time_point startTime)
    {
        auto currentTime = std::chrono::system_clock::now();

        std::chrono::duration<double> elapsed_seconds = currentTime - startTime;

        if(elapsed_seconds.count() * 1000 > timeLaps_ms) return true;
        else return false;
    }

    // ---------------------------------------------------------------------------------- //

    // Проверка: является ли строка IPv4 адресом
    bool isIPv4Address(std::string IPAddress)
    {
        int dotCounter = 0;
        std::string curOctet = "";
        int number = 0;

        // "100.100.100.100" - максимум 15 символов. Если больше - ошибка.
        if(IPAddress.length() > 15) return false;
        
        for(unsigned int i = 0; i < IPAddress.length(); i++)
        {
            // Если точка, то проверяем октет до нее
            if(IPAddress[i] == '.')
            {
                dotCounter++;
                if(dotCounter > 3) return false;

                // Если октет пустой (две точки подряд) - ошибка
                if(curOctet.empty()) return false;
                else
                {
                    // Попытка перевести строку в число
                    try { number = stoi(curOctet); }
                    catch(const std::exception& e) { return false; }
                    
                    // Если в строке были буквы, проигнорированные функцией stoi - ошибка
                    if(std::to_string(number).length() != curOctet.length()) return false;

                    // Полученное число должно быть в диапазоне [0;255]
                    if(number > 255 || number < 0) return false;
                }

                curOctet = "";
            }
            else curOctet += IPAddress[i];  // Формируем символы текущего октета до точки
        }

        // Обработка последнего октета
        if(curOctet.empty()) return false;
        else
        {
            // Попытка перевести строку в число
            try { number = stoi(curOctet); }
            catch(const std::exception& e) { return false; }
            
            // Если в строке были буквы, проигнорированные функцией stoi - ошибка
            if(std::to_string(number).length() != curOctet.length()) return false;

            // Полученное число должно быть в диапазоне [0;255]
            if(number > 255 || number < 0) return false;
        }
        
        // Если октетов больше 4 - ошибка
        if(dotCounter != 3) return false;

        return true;
    }

    // ---------------------------------------------------------------------------------- //

    // Подсчет числа цифр в числе
    unsigned int countDigits(unsigned int number)
    {
        unsigned int counter = 0;
        while(number > 0)
        {
            number /= 10;
            counter++;
        }

        return counter;
    }

    // ---------------------------------------------------------------------------------- //
}
