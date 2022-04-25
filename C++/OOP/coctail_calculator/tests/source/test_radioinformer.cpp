#include <gtest/gtest.h>

#include "radioinformer.h"

#include <iostream>

#include "helping.h"
namespace rim
{

// =========================================== RI =========================================== //

	/**
	 * Функция: RI::RI()
	 * Проверка конструктора
	 **/
	TEST(test_radioinformer, RI_constructorCheck)
	{
		RI ri;

		ASSERT_EQ(ri.doorsState, false) <<
			"\n\tIncorrect value of \"ri.doorsState\": [true], need to be [false]\n";

		ASSERT_EQ(ri.RoadID, 0x0EEEE) <<
			"\n\tIncorrect value of \"ri.RoadID\": " << ri.RoadID 
			<< "[false], need to be 61166[true]\n";

		ASSERT_EQ(ri.statusReceivDann, false) <<
			"\n\tIncorrect value of \"ri.statusReceivDann\": [true], need to be [false]\n";

		ASSERT_EQ(ri.statusAnalisDann, false) <<
			"\n\tIncorrect value of \"ri.statusAnalisDann\": [true], need to be [false]\n";

		ASSERT_EQ(ri.statusSendDann, false) <<
			"\n\tIncorrect value of \"ri.statusSendDann\": [true], need to be [false]\n";

		ASSERT_EQ(ri.RIM_status, 2) <<
			"\n\tIncorrect value of \"ri.RIM_status\": " << ri.RIM_status 
			<< "[false], need to be 2[true]\n";


		for(unsigned char i = 0; i < SAVED_FLAGS_STATES_SIZE; i++)
		{
			ASSERT_EQ(ri.savedFlagsStates[i], false) <<
				"\n\tIncorrect value of \"ri.savedFlagsStates[i]\": [true], " 
				<< "need to be [false]\n";
		}

		ASSERT_EQ(ri.isRunning(), false) <<
			"Incorrect value of \"ri.isRunning()\": [true], need to be [false]";

		ri.~RI();
	}


// ================================= isRunning / changeState ================================ //

	/**
	 * Функция: bool RI::isRunning()
	 * Проверка сеттера для переменной moduleState
	 **/
	TEST(test_radioinformer, isRunning_and_changeState_check)
	{
		RI ri;

		ri.changeState(RI::riState::active);
		ASSERT_EQ(ri.isRunning(), true) <<
			"\n\tIncorrect modele state: inactive[false], need to be active[true]\n";

		ri.changeState(RI::riState::inactive);
		ASSERT_EQ(ri.isRunning(), false) <<
			"\n\tIncorrect modele state: active[true], need to be inactive[false]\n";

		ri.~RI();
	}


// ======================================= printInfo ======================================== //

// Нет теста


// =============================== getRoadIDFromNumberString ================================ //

	/**
	 * Функция: void RI::getRoadIDFromNumberString(std::string inputString)
	 * 
	 **/
	TEST(test_radioinformer, getRoadIDFromNumberString_allCases)
	{
		RI ri;
		std::string input_routeStringMas[] =
		{
			"a", "aa", "aaa", "1", "12", "123", "a1", "a12", "a123", "a1a", "a12a", "a123a", 
			"a1aa", "a12aa", "a123aa", "a1a1", "a123a1", "1aa", "12aa", "123aa"
		};

		int output_routeNumberMas[] = 
		{
			0x0EEEE, 0x0EEEE, 0x0EEEE, 1, 12, 123, 1, 12, 123, 1, 12, 123, 1, 12, 123, 11, 
			1231, 1, 12, 123
		};

		ASSERT_EQ(ri.RoadID, 0x0EEEE) <<
			"\n\tCounstructor error: ri.RoadID must be 0x0EEEE(61166), but it's " 
			<< ri.RoadID << "\n";

		for(unsigned int i = 0; i < 20; i++)
		{
			ri.getRoadIDFromNumberString(input_routeStringMas[i]);

			ASSERT_EQ(ri.RoadID, output_routeNumberMas[i]) <<
				"\n\tIncorrect road IDfrom string \"" << input_routeStringMas[i] << "\": "
				<< ri.RoadID << "[false], need to be " << output_routeNumberMas[i] 
				<< "[true]\n";
		}

		ri.~RI();
	}


// ============================= getRoadNumberLettersFromString ============================= //

	/**
	 * Функция: void RI::getRoadNumberLettersFromString(std::string inputString)
	 * 
	 **/
	TEST(test_radioinformer, getRoadNumberLettersFromString_allCases)
	{
		RI ri;
		std::wstring input_routeStringMas[] =
		{
			L"й", L"п1", L"ж1ъ", L"я12чм", L"98ар", L"5", L"90д", L"апр", L"хэзн90", 
			L"аа34ап", L"56прне", L"р345рор34", L"ф!а", L"д12в!!к12", L"12ф!!кж12", L"!к12", L""
		};
		std::wstring output_routeLettersMas[] = 
		{
			L"й!!", L"п!!", L"жъ!", L"ячм", L"!ар", L"!!!", L"!д!", L"апр", L"х!!", L"аап", 
			L"!пр", L"р!!", L"фа!", L"д!!", L"!!!", L"!!!", L"!!!"
		};
		bool resultA, resultB, resultC, result;
		unsigned char cifA_etalon, cifB_etalon, cifC_etalon;


		for(unsigned int i = 0; i < 17; i++)
		{
			ri.cifA = 255;
			ri.cifB = 255;
			ri.cifC = 255;

			ri.getRoadNumberLettersFromString(help::wstringToString(input_routeStringMas[i]));
			// ri.getRoadIDFromNumberString(input_routeStringMas[i]);

			cifA_etalon = ri.getRIRusLetterCode((int)output_routeLettersMas[i][0]);
			cifB_etalon = ri.getRIRusLetterCode((int)output_routeLettersMas[i][1]);
			cifC_etalon = ri.getRIRusLetterCode((int)output_routeLettersMas[i][2]);

			resultA = (ri.cifA == cifA_etalon) ? true : false;
			resultB = (ri.cifB == cifB_etalon) ? true : false;
			resultC = (ri.cifC == cifC_etalon) ? true : false;

			result = resultA & resultB & resultC;

			ASSERT_EQ(result, true) <<
				"\n\tIncorrect route number string parsing in " << i << " iteration:" 
				<< "\n\t\tri.cifA = " << (int)ri.cifA << " need to be " << (int)cifA_etalon 
					<< (resultA ? " [true]" : " [false]")
				<< "\n\t\tri.cifB = " << (int)ri.cifB << " need to be " << (int)cifB_etalon 
					<< (resultB ? " [true]" : " [false]")
				<< "\n\t\tri.cifC = " << (int)ri.cifC << " need to be " << (int)cifC_etalon 
					<< (resultC ? " [true]" : " [false]\n");
		}

		ri.~RI();
	}


// ========================== getRoadNumberLettersFromTripShortName ========================= //

	/**
	 * Функция: void getRoadNumberLettersFromTripShortName(std::string inputString)
	 * 
	 **/
	TEST(test_radioinformer, getRoadNumberLettersFromTripShortName_allCases)
	{
		RI ri;
		std::wstring input_routeStringMas[] =
		{
			L"йa44dЧ{0", L"", L"00", L"000", L"98ар", L"5", L"90д", L"апр", L"хэзн90", 
			L"аа34ап", L"56Прне", L"р345рор34", L"ф!а", L"д12в!!к12", L"5вdf_0", L"1ввД"
		};
		std::wstring output_routeLettersMas[] = 
		{
			L"й44", L"!!!", L"!00", L"!00", L"а98", L"!5!", L"д90", L"а!!", L"х90", L"а34", 
			L"п56", L"р34", L"ф!!", L"д12", L"в50", L"в1!"
		};
		bool resultA, resultB, resultC, result;
		unsigned char cifA_etalon, cifB_etalon, cifC_etalon;

		for(unsigned int i = 0; i < 16; i++)
		{
			ri.cifA = 255;
			ri.cifB = 255;
			ri.cifC = 255;

			ri.getRoadNumberLettersFromTripShortName(help::wstringToString(input_routeStringMas[i]));

			cifA_etalon = ri.getRIRusLetterCode((int)output_routeLettersMas[i][0]);

			if(help::isDigit(output_routeLettersMas[i][1])) 
				cifB_etalon = help::wchartToInt(output_routeLettersMas[i][1]) + 48;
			else cifB_etalon = NO_ROUTE_NUMBER_LETTER;

			if(help::isDigit(output_routeLettersMas[i][2])) 
				cifC_etalon = help::wchartToInt(output_routeLettersMas[i][2]) + 48;
			else cifC_etalon = NO_ROUTE_NUMBER_LETTER;

			resultA = (ri.cifA == cifA_etalon) ? true : false;
			resultB = (ri.cifB == cifB_etalon) ? true : false;
			resultC = (ri.cifC == cifC_etalon) ? true : false;

			result = resultA & resultB & resultC;

			ASSERT_EQ(result, true) <<
				"\n\tIncorrect route number string parsing in " << i << " iteration:" 
				<< "\n\t\tri.cifA = " << (int)ri.cifA << " need to be " << (int)cifA_etalon 
					<< (resultA ? " [true]" : " [false]")
				<< "\n\t\tri.cifB = " << (int)ri.cifB << " need to be " << (int)cifB_etalon 
					<< (resultB ? " [true]" : " [false]")
				<< "\n\t\tri.cifC = " << (int)ri.cifC << " need to be " << (int)cifC_etalon 
					<< (resultC ? " [true]" : " [false]\n");
		}

		ri.~RI();
	}


// =================================== getRIRusLetterCode =================================== //

	/**
	 * Функция: unsigned char RI::getRIRusLetterCode(int rusSymbolCode)
	 * 
	 **/
	TEST(test_radioinformer, getRIRusLetterCode_allRusLetters)
	{
		RI ri;

		std::wstring upperRusLetters = L"АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
		std::wstring lowerRusLetters = L"абвгдежзийклмнопрстуфхцчшщъыьэюя";
		std::wstring specialLetters  = L"ёЁ ";

		int lettersStartCode = 224;
		int specLettersCode = 229;

		unsigned char result = 0;


		for(unsigned char i = 0; i < upperRusLetters.length(); i++)
		{
			result = ri.getRIRusLetterCode(upperRusLetters[i]);

			ASSERT_EQ(result, lettersStartCode + i) <<
				"\n\tIncorrect code translation for " << (int)i << " upper letter: " 
				<< (int)result << "[false], need to be " << lettersStartCode + i 
				<< "[true]\n";
		}

		for(unsigned char i = 0; i < lowerRusLetters.length(); i++)
		{
			result = ri.getRIRusLetterCode(lowerRusLetters[i]);

			ASSERT_EQ(result, lettersStartCode + i) <<
				"\n\tIncorrect code translation for " << (int)i << " upper letter: " 
				<< (int)result << "[false], need to be " << lettersStartCode + i 
				<< "[true]\n";
		}

		result = ri.getRIRusLetterCode(specialLetters[0]);
		ASSERT_EQ(result, specLettersCode) <<
			"\n\tIncorrect code translation for scecial letter: " << (int)result 
			<< "[false], need to be " << specLettersCode << "[true]\n";

		result = ri.getRIRusLetterCode(specialLetters[1]);
		ASSERT_EQ(result, specLettersCode) <<
			"\n\tIncorrect code translation for scecial letter: " << (int)result 
			<< "[false], need to be " << specLettersCode << "[true]\n";

		result = ri.getRIRusLetterCode(specialLetters[2]);
		ASSERT_EQ(result, NO_ROUTE_NUMBER_LETTER) <<
			"\n\tIncorrect code translation for scecial letter: " << (int)result 
			<< "[false], need to be " << NO_ROUTE_NUMBER_LETTER << "[true]\n";

		ri.~RI();
	}



// ============================== flagStateWasChanged =============================== //

	/**
	 * Функция: bool RI::flagStateWasChanged()
	 * 
	 **/
	TEST(test_radioinformer, flagStateWasChanged_checkEveryFlag)
	{
		RI ri;
		
		bool result;

		ri.updateFlagsStates();
		result = ri.flagStateWasChanged();
		ASSERT_EQ(result, false) <<
			"\n\tIncorrect flags value: [true], need to be [false]\n";
		
		ri.statusReceivDann = !ri.statusReceivDann;
		result = ri.flagStateWasChanged();
		ASSERT_EQ(result, true) <<
			"\n\tIncorrect change flag check: [false], need to be [true]," 
			<< " \"statusReceivDann\" was inversed\n";
		ri.updateFlagsStates();

		ri.statusAnalisDann = !ri.statusAnalisDann;
		result = ri.flagStateWasChanged();
		ASSERT_EQ(result, true) <<
			"\n\tIncorrect change flag check: [false], need to be [true]," 
			<< " \"statusAnalisDann\" was inversed\n";
		ri.updateFlagsStates();

		ri.changeState(RI::riState::active);
		result = ri.flagStateWasChanged();
		ASSERT_EQ(result, true) <<
			"\n\tIncorrect change flag check: [false], need to be [true]," 
			<< " \"ri runnung state\" was inversed\n";
		ri.updateFlagsStates();

		ri.statusConfigResived = !ri.statusConfigResived;
		result = ri.flagStateWasChanged();
		ASSERT_EQ(result, true) <<
			"\n\tIncorrect change flag check: [false], need to be [true]," 
			<< " \"statusConfigResived\" was inversed\n";
		ri.updateFlagsStates();

		ri.statusSendDann = !ri.statusSendDann;
		result = ri.flagStateWasChanged();
		ASSERT_EQ(result, true) <<
			"\n\tIncorrect change flag check: [false], need to be [true]," 
			<< " \"statusSendDann\" was inversed\n";

		ri.~RI();
	}


// ================================ updateFlagsStates =============================== //

	/**
	 * Функция: void RI::updateFlagsStates()
	 * 
	 **/
	TEST(test_radioinformer, updateFlagsStates_allFlagsUpdateCheck)
	{
		RI ri;

		bool resultFlagsStateMas[] = {true, true, true, true, true};
		
		// Флаги, сохраненные значения которых обновляются функцией updateFlagsStates()
		ri.statusReceivDann = true;
		ri.statusAnalisDann = true;
		ri.changeState(RI::riState::active);
		ri.statusConfigResived = true;
		ri.statusSendDann = true;

		// Противоположное значение в массив сохраненных значений флагов
		for(unsigned char i = 0; i < SAVED_FLAGS_STATES_SIZE; i++)
			ri.savedFlagsStates[i] = false;
		
		// Все false должны превраситься в true
		ri.updateFlagsStates();

		for(unsigned char i = 0; i < SAVED_FLAGS_STATES_SIZE; i++)
		{
			ASSERT_EQ(ri.savedFlagsStates[i], resultFlagsStateMas[i]) <<
				"\n\tIncorrect svedFlag[" << (int)i << "] updated value: " 
				<< (ri.savedFlagsStates[i] ? "[true]" : "[flase]") 
				<< ", need to be " << (resultFlagsStateMas[i] ? "[true]" : "[flase]") 
				<< "\n";
		}
		
		ri.~RI();
	}


// =================================== doors_close ================================== //

	/**
	 * Функция: void RI::doors_close(uint16_t & register5)
	 * 
	 **/
	TEST(test_radioinformer, doors_close)
	{
		RI ri;

		uint16_t reg = 0b1111111111111111;
		ri.doors_close(reg);
		ASSERT_EQ(reg, 0xBFFF) <<
			"\n\tIncorrect register value (14 bit): " << reg 
			<< "[false], need to be 0xBFFF(49151)[true]\n";

		reg = 0b0000;
		ri.doors_close(reg);
		ASSERT_EQ(reg, 0x8000) <<
			"\n\tIncorrect register value (15 bit): " << reg 
			<< "[false], need to be 0x8000(32768)[true]\n";
		
		ri.~RI();
	}


// =================================== doors_open =================================== //

	/**
	 * Функция: void RI::doors_open(uint16_t & register5)
	 * 
	 **/
	TEST(test_radioinformer, doors_open)
	{
		RI ri;

		uint16_t reg = 0b1111111111111111;
		ri.doors_open(reg);
		ASSERT_EQ(reg, 0x7FFF) <<
			"\n\tIncorrect register value (15 bit): " << reg 
			<< "[false], need to be 0x7FFF(32767)[true]\n";

		reg = 0b0000;
		ri.doors_open(reg);
		ASSERT_EQ(reg, 0x4000) <<
			"\n\tIncorrect register value (14 bit): " << reg 
			<< "[false], need to be 0x4000(16384)[true]\n";
		
		ri.~RI();
	}

// ============================ doors_setExternalControl ============================ //

	/**
	 * Функция: void RI::doors_setExternalControl(uint16_t & register5)
	 * 
	 **/
	TEST(test_radioinformer, doors_setExternalControl)
	{
		RI ri;

		uint16_t reg = 0b1111111111111111;
		ri.doors_setExternalControl(reg);
		ASSERT_EQ(reg, 0xEFFF) <<
			"\n\tIncorrect register value (12 bit): " << reg 
			<< "[false], need to be 0xDFFF(61439)[true]\n";

		reg = 0b0000;
		ri.doors_setExternalControl(reg);
		ASSERT_EQ(reg, 0x2000) <<
			"\n\tIncorrect register value (13 bit): " << reg 
			<< "[false], need to be 0x2000(8192)[true]\n";
		
		ri.~RI();
	}


// ============================== doors_setSelfControl ============================== //

	/**
	 * Функция: void RI::doors_setSelfControl(uint16_t & register5)
	 * 
	 **/
	TEST(test_radioinformer, doors_setSelfControl)
	{
		RI ri;

		uint16_t reg = 0b1111111111111111;
		ri.doors_setSelfControl(reg);
		ASSERT_EQ(reg, 0xDFFF) <<
			"\n\tIncorrect register value (13 bit): " << reg 
			<< "[false], need to be 0xDFFF(57343)[true]\n";

		reg = 0b0000;
		ri.doors_setSelfControl(reg);
		ASSERT_EQ(reg, 0x1000) <<
			"\n\tIncorrect register value (12 bit): " << reg 
			<< "[false], need to be 0x1000(4096)[true]\n";
		
		ri.~RI();
	}


// ====================================== mute ====================================== //

	/**
	 * Функция: void RI::mute(uint16_t & register5)
	 * 
	 **/
	TEST(test_radioinformer, mute)
	{
		RI ri;

		uint16_t reg = 0b1111111111111111;
		ri.mute(reg);
		ASSERT_EQ(reg, 0xFFE7) <<
			"\n\tIncorrect register value (3 bit): " << reg 
			<< "[false], need to be 0xFFE7(65511)[true]\n";
		
		ri.~RI();
	}
}