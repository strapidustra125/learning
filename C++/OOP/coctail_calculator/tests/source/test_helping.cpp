#include <gtest/gtest.h>

#include "helping.h"

#include <string>
#include <iostream>
#include <typeinfo>







namespace rim
{
	
// ==================================== hexStringFromInt ==================================== //

	/**
	 * Функция: std::string hexStringFromInt(int intNumber)
	 * Проверка HEX чисел: перевод [0;15] в [0x0;0xF]
	 **/
	TEST(test_helping, hexStringFromInt_int_allHEXDigitsCheck)
	{
		int input_intMas[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
		std::string output_stringsMas[] = 
			{ "0x0", "0x1", "0x2", "0x3", "0x4", "0x5", "0x6", "0x7", "0x8", "0x9", "0xA", 
				"0xB", "0xC", "0xD", "0xE", "0xF" };
		std::string resultString = "";

		for(unsigned int i = 0; i < 16; i++)
		{
			resultString = help::hexStringFromInt(input_intMas[i]);
			ASSERT_EQ(resultString, output_stringsMas[i]) << 
				"\n\tIncorrect translation from " << input_intMas[i] << " to HEX string: \""
				<< resultString << "\"[false], need to be \"" << output_stringsMas[i]
				<< "\"[true]\n";
		}
	}


	/**
	 * Функция: std::string hexStringFromInt(int intNumber)
	 * Проверка отрицательных чисел
	 **/
	TEST(test_helping, hexStringFromInt_int_negativeNumber)
	{
		int input_int = -8;
		std::string resultString = "";

		resultString = help::hexStringFromInt(input_int);

		ASSERT_EQ(resultString, "incorrect_input") <<
			"\n\tIncorrect translation from " << input_int << " to HEX string: \""
			<< resultString << "\"[false], need to be \"" << "incorrect_input"
			<< "\"[true]\n";
	}


	/**
	 * Функция: std::string hexStringFromInt(short unsigned int intNumber)
	 * Проверка HEX чисел: перевод [0;15] в [0x0;0xF]
	 **/
	TEST(test_helping, hexStringFromInt_uint16t_allHEXDigitsCheck)
	{
		short unsigned int input_intMas[] = 
			{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
		std::string output_stringsMas[] = 
			{ "0x0", "0x1", "0x2", "0x3", "0x4", "0x5", "0x6", "0x7", "0x8", "0x9", "0xA", 
				"0xB", "0xC", "0xD", "0xE", "0xF" };
		std::string resultString = "";

		for(unsigned int i = 0; i < 16; i++)
		{
			resultString = help::hexStringFromInt(input_intMas[i]);
			ASSERT_EQ(resultString, output_stringsMas[i]) <<
				"\n\tIncorrect translation from " << input_intMas[i] << " to HEX string: \""
				<< resultString << "\"[false], need to be \"" << output_stringsMas[i]
				<< "\"[true]\n";
		}
	}



// ======================================= isRusLetter ====================================== //

	/**
	 * Функция: bool isRusLetter(wchar_t symbol)
	 * Проверка русских букв
	 **/
	TEST(test_helping, isRusLetter_rusSymbols)
	{
		std::wstring input_rusSymbString 
			= L"абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
		bool result;

		for(unsigned int i = 0; i < input_rusSymbString.length(); i++)
		{
			result = help::isRusLetter(input_rusSymbString[i]);
			ASSERT_EQ(result, true) <<
				"\n\tIncorrect value for letter \'" << input_rusSymbString[i] << "\', code " 
				<< (int)input_rusSymbString[i] << ": [false], need to be [true]\n";
		}
	}

	/**
	 * Функция: bool isRusLetter(wchar_t symbol)
	 * Проверка нерусских букв
	 **/
	TEST(test_helping, isRusLetter_notRusSymbols)
	{
		std::wstring input_notRusSymbString 
			= L"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789`~!@#$%^&*()_+-=[]{};:\'\"\\|<>,.?/";
		bool result;

		for(unsigned int i = 0; i < input_notRusSymbString.length(); i++)
		{
			result = help::isRusLetter(input_notRusSymbString[i]);
			ASSERT_EQ(result, false) <<
				"\n\tIncorrect value for letter \'" << input_notRusSymbString[i] 
				<< "\', code " << (int)input_notRusSymbString[i] 
				<< ": [true], need to be [false]\n";
		}
	}

// ========================================= isDigit ======================================== //

	/**
	 * Функция: bool isDigit(wchar_t symbol)
	 * Проверка символов цифр [0;9]
	 **/
	TEST(test_helping, isDigit_wchar_digits)
	{
		wchar_t input_digits[] = { '0', '1', '2', '3', '4', '5', '8', '7', '8', '9' };
		bool result;

		for(unsigned int i = 0; i < 10; i++)
		{
			result = help::isDigit(input_digits[i]);
			ASSERT_EQ(result, true) <<
				"\n\tIncorrect check for \'" << (char)input_digits[i] 
				<< "\': [false], need to be [true], it's a digit\n";
		}
	}


	/**
	 * Функция: bool isDigit(wchar_t symbol)
	 * Проверка символов не цифр
	 **/
	TEST(test_helping, isDigit_wchar_symbols)
	{
		wchar_t input_symbols[] = 
		{
			'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 
			'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 
			'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 
			'W', 'X', 'Y', 'Z',
			'`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '-', '+', '=', 
			'[', ']', '{', '}', ':', ';', '\'', '\"', '|', '\\', ',', '.', '<', '>', '/', 
			'?', '\n', '\t'
		};

		bool result;

		for(unsigned int i = 0; i < 86; i++)
		{
			result = help::isDigit(input_symbols[i]);
			ASSERT_EQ(result, false) <<
				"\n\tIncorrect check for \'" << (char)input_symbols[i] 
				<< "\': [true], need to be [false], it's not a digit\n";
		}
	}


	/**
	 * Функция: bool isDigit(char symbol)
	 * Проверка символов цифр [0;9]
	 **/
	TEST(test_helping, isDigit_char_digits)
	{
		char input_digits[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
		bool result;

		for(unsigned int i = 0; i < 10; i++)
		{
			result = help::isDigit(input_digits[i]);
			ASSERT_EQ(result, true) <<
				"\n\tIncorrect check for \'" << (char)input_digits[i] 
				<< "\': [false], need to be [true], it's a digit\n";
		}
	}


	/**
	 * Функция: bool isDigit(char symbol)
	 * Проверка символов не цифр
	 **/
	TEST(test_helping, isDigit_char_symbols)
	{
		char input_symbols[] = 
		{
			'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 
			'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 
			'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 
			'W', 'X', 'Y', 'Z',
			'`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '-', '+', '=', 
			'[', ']', '{', '}', ':', ';', '\'', '\"', '|', '\\', ',', '.', '<', '>', '/', 
			'?', '\n', '\t'
		};

		bool result;

		for(unsigned int i = 0; i < 86; i++)
		{
			result = help::isDigit(input_symbols[i]);
			ASSERT_EQ(result, false) <<
				"\n\tIncorrect check for \'" << (char)input_symbols[i] 
				<< "\': [true], need to be [false], it's not a digit\n";
		}
	}


// ================================= digitsVectorFromString ================================= //

	/**
	 * Функция: std::vector<int> digitsVectorFromString(std::string inputString)
	 * Проверка каждой найденной цифры
	 **/
	TEST(test_helping, digitsVectorFromString_everyDigitCheck)
	{
		std::string input_string = "ay65__!s9";
		std::vector<int> result;
		int expectedNumber = 3;

		result = help::digitsVectorFromString(input_string);

		ASSERT_EQ(result.size(), expectedNumber) <<
			"\n\tIncorrect number of found digits: " << result.size() 
			<< "[false], need to be " << expectedNumber << "[true]\n";

		ASSERT_EQ(result[0], 6) <<
			"\n\tIncorrect digit: " << result[0]
			<< "[false], need to be " << 6 << "[true]\n";
		ASSERT_EQ(result[1], 5) <<
			"\n\tIncorrect digit: " << result[1]
			<< "[false], need to be " << 5 << "[true]\n";
		ASSERT_EQ(result[2], 9) <<
			"\n\tIncorrect digit: " << result[2]
			<< "[false], need to be " << 9 << "[true]\n";
	}


	/**
	 * Функция: std::vector<int> digitsVectorFromString(std::string inputString)
	 * Пустая входная строка
	 **/
	TEST(test_helping, digitsVectorFromString_emptyString)
	{
		std::string input_string = "";
		std::vector<int> result;

		result = help::digitsVectorFromString(input_string);

		ASSERT_EQ(result.size(), 0) <<
			"\n\tIncorrect number of found digits: " << result.size() 
			<< "[false], need to be " << 0 << "[true]\n";
	}


	/**
	 * Функция: std::vector<int> digitsVectorFromString(std::string inputString)
	 * Входная строка без символов
	 **/
	TEST(test_helping, digitsVectorFromString_stringWithoutDigits)
	{
		std::string input_string = 
			"abcdefghijklmnopqrstuvwxyz\
			 ABCDEFGHIJKLMNOPQRSTUVWXYZ\
			 .,/?*-+=_)(&^%$#@!`~;:\"\'<>[]{}|/\\";
		std::vector<int> result;

		result = help::digitsVectorFromString(input_string);

		ASSERT_EQ(result.size(), 0) <<
			"\n\tIncorrect number of found digits: " << result.size() 
			<< "[false], need to be " << 0 << "[true]\n";
	}


	/**
	 * Функция: std::vector<int> digitsVectorFromString(std::string inputString)
	 * Входная, содержащая все возможные цифры
	 **/
	TEST(test_helping, digitsVectorFromString_allDigitsString)
	{
		std::string input_string = "0123456789";
		std::vector<int> result;

		result = help::digitsVectorFromString(input_string);

		ASSERT_EQ(result.size(), 10) <<
			"\n\tIncorrect number of found digits: " << result.size() 
			<< "[false], need to be " << 10 << "[true]\n";
	}


// ================================ getFirstRusLetterPointer ================================ //

	/**
	 * Функция: int getFirstRusLetterPointer(std::wstring inputString)
	 * Проверка всех возможных позиций первой буквы
	 **/
	TEST(test_helping, getFirstRusLetterPointer_allCases)
	{
		std::wstring input_stringMas[] = 
		{
			L"фa__aЫВd", L"a_Д_asфы", L"a__asыd", L"a__asdЫ", L"a_н2_as3пd", L"a__as12Зd",
			L"123a__asdж", L"123a__a2Цsd", L"1a_123_asdю"
		};
		int output_positionMas[] =
		{
			0, 2, 5, 6, 2, 7, 9, 8, 10
		};
		int result;

		for(unsigned int i = 0; i < 9; i++)
		{
			result = help::getFirstRusLetterPointer(input_stringMas[i]);

			ASSERT_EQ(result, output_positionMas[i]) <<
				"\n\tIncorrect firast rus letter position in \"" 
				<< help::wstringToString(input_stringMas[i]) << "\":" << result 
				<< "[false], need to be " << output_positionMas[i] << "[true]\n";
		}
	}


	/**
	 * Функция: int getFirstRusLetterPointer(std::wstring inputString)
	 * Проверка входящей строки без русских букв
	 **/
	TEST(test_helping, getFirstRusLetterPointer_noLettersString)
	{
		std::wstring input_stringMas[] = { L"", L"dks--_!aHY."};
		int result;

		for(unsigned int i = 0; i < 2; i++)
		{
			result = help::getFirstRusLetterPointer(input_stringMas[i]);
			ASSERT_EQ(result, -1) <<
				"\n\tIncorrect first rus letter position in \"" 
				<< help::wstringToString(input_stringMas[i]) << "\":" << result 
				<< "[false], need to be " << -1 << "[true]\n";
		}
	}


// =================================== getLastDigitPionter ================================== //

	/**
	 * Функция: int getLastDigitPointer(std::wstring inputString)
	 * Проверка всех возможных позиций последней цифры
	 **/
	TEST(test_helping, getLastDigitPointer_allCases)
	{
		std::wstring input_stringMas[] = 
		{
			L"1a__asd", L"a_1_asd", L"a__as1d", L"a__asd1", L"a_12_as34d", L"a__as123d",
			L"123a__asd3", L"123a__a21sd", L"1a_123_asd1"
		};
		int output_positionMas[] =
		{
			0, 2, 5, 6, 8, 7, 9, 8, 10
		};
		int result;

		for(unsigned int i = 0; i < 9; i++)
		{
			result = help::getLastDigitPointer(input_stringMas[i]);

			ASSERT_EQ(result, output_positionMas[i]) <<
				"\n\tIncorrect last digit position in \"" 
				<< help::wstringToString(input_stringMas[i]) << "\":" << result 
				<< "[false], need to be " << output_positionMas[i] << "[true]\n";
		}
	}

	/**
	 * Функция: int getLastDigitPointer(std::wstring inputString)
	 * Проверка входящей строки без цифр
	 **/
	TEST(test_helping, getLastDigitPointer_noDigitsString)
	{
		std::wstring input_stringMas[] = { L"", L"dks--_!aHY."};
		int result;

		for(unsigned int i = 0; i < 2; i++)
		{
			result = help::getLastDigitPointer(input_stringMas[i]);
			ASSERT_EQ(result, -1) <<
				"\n\tIncorrect last digit position in \"" 
				<< help::wstringToString(input_stringMas[i]) << "\":" << result 
				<< "[false], need to be " << -1 << "[true]\n";
		}
	}


// ================================== getFirstDigitPointer ================================== //

	/**
	 * Функция: int getFirstDigitPointer(std::wstring inputString)
	 * Проверка всех возможных позиций первой цифры
	 **/
	TEST(test_helping, getFirstDigitPointer_allCases)
	{
		std::wstring input_stringMas[] = 
		{
			L"1a__asd", L"a_1_asd", L"a__as1d", L"a_3_asd1", L"a_12_as34d", L"a__as123d",
			L"123a__asd3", L"_123a__a21sd", L"1a_123_asd1"
		};
		int output_positionMas[] =
		{
			0, 2, 5, 2, 2, 5, 0, 1, 0
		};
		int result;

		for(unsigned int i = 0; i < 9; i++)
		{
			result = help::getFirstDigitPointer(input_stringMas[i]);

			ASSERT_EQ(result, output_positionMas[i]) <<
				"\n\tIncorrect first digit position in \"" 
				<< help::wstringToString(input_stringMas[i]) << "\":" << result 
				<< "[false], need to be " << output_positionMas[i] << "[true]\n";
		}
	}

	/**
	 * Функция: int getFirstDigitPointer(std::wstring inputString)
	 * Проверка входящей строки без цифр
	 **/
	TEST(test_helping, getFirstDigitPointer_noDigitsString)
	{
		std::wstring input_stringMas[] = { L"", L"dks--_!aHY."};
		int result;

		for(unsigned int i = 0; i < 2; i++)
		{
			result = help::getFirstDigitPointer(input_stringMas[i]);
			ASSERT_EQ(result, -1) <<
				"\n\tIncorrect first digit position in \"" 
				<< help::wstringToString(input_stringMas[i]) << "\":" << result 
				<< "[false], need to be " << -1 << "[true]\n";
		}
	}


// ===================================== stringToWstring ==================================== //

	// Нет теста, потому что проверяется компилятором


// ===================================== wstringToString ==================================== //

	// Нет теста, потому что проверяется компилятором



// ======================================= wchartToInt ====================================== //

	/**
	 * Функция: int wchartToInt(wchar_t inputSymbol)
	 * Проверка всех чисел
	 **/
	TEST(test_helping, wchartToInt_allDigits)
	{
		wchar_t inputSymbolsMas[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

		int outputIntMas[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		for(unsigned int i = 0; i < 10; i++)
		{
			ASSERT_TRUE(outputIntMas[i] == help::wchartToInt(inputSymbolsMas[i])) <<
				"\n\tIncorrect result:" << help::wchartToInt(inputSymbolsMas[i])
				<< "[false], need to be " << outputIntMas[i] << "\n";
		}
	}


	/**
	 * Функция: int wchartToInt(wchar_t inputSymbol)
	 * Проверка букв
	 **/
	TEST(test_helping, wchartToInt_noDigits)
	{
		std::wstring inputWstring 
			= L"абвгдежзийклмнопрстуфхцчшщъыьэюя\
			    АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ\
				abcdefghijklmnopqrstuvwxyz\
				ABCDEFGHIJKLMNOPQRSTUVWXYZ\
				`~!@#$%^&*()_+-=[]{};:\'\"\\|<>,.?/";

		for(unsigned int i = 0; i < inputWstring.length(); i++)
		{
			ASSERT_TRUE(-1 == help::wchartToInt(inputWstring[i])) <<
				"\n\tIncorrect result:" << help::wchartToInt(inputWstring[i])
				<< "[false], need to be " << -1 << "\n";
		}
	}


// ======================================== sleep_ms ======================================== //

	/**
	 * Функция: void sleep_ms(unsigned int time_ms)
	 * Проверка задержки
	 **/
	TEST(test_helping, sleep_ms_checkDelay)
	{
		std::chrono::_V2::system_clock::time_point finishTime, startTime = 
			std::chrono::system_clock::now();

		help::sleep_ms(100);

		finishTime = std::chrono::system_clock::now();

		std::chrono::duration<double> delay = finishTime - startTime;

		ASSERT_TRUE(abs(delay.count() * 1000 - 100) < 0.5) <<
			"\n\tIncorrect delay time:" << delay.count() * 1000
			<< "[false], need to be " << 100 << " +/-0.5 [true]\n";
	}


// ======================================== timeIsUp ======================================== //

// Нет теста


// ================================= isIPv4Address ================================== //

	/**
	 * bool isIPv4Address(std::string IPAddress)
	 * 
	 **/
	TEST(test_helping, isIPv4Address_falseCases)
	{
		std::string input_stringMas[] =
		{
			"....", "", "1.1", "300.300.300.300", "100.100..", "asd.2.3.a", "100.100.100.", 
			"1.1.2.", "1.1.3.2a", "1a.2a.2a.2", "_...", "1.1.1.300"
		};
		bool result;

		for(unsigned int i = 0; i < 12; i++)
		{
			result = help::isIPv4Address(input_stringMas[i]);
			ASSERT_EQ(result, false) <<
				"\n\tIncorrect check for \"" << input_stringMas[i] << "\":" 
				<< "[true], need to be [false], it's not an IPv4 address";
		}
	}


	/**
	 * bool isIPv4Address(std::string IPAddress)
	 * 
	 **/
	TEST(test_helping, isIPv4Address_trueCases)
	{
		std::string input_stringMas[] =
		{
			"0.0.0.0", "255.255.255.255", "1.0.0.0", "0.0.0.100", "192.168.100.2"
		};
		bool result;

		for(unsigned int i = 0; i < 5; i++)
		{
			result = help::isIPv4Address(input_stringMas[i]);
			ASSERT_EQ(result, true) <<
				"\n\tIncorrect check for \"" << input_stringMas[i] << "\":" 
				<< "[false], need to be [true], it's an IPv4 address";
		}
	}

}