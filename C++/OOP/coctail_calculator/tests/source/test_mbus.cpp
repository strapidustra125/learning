#include <iostream>

#include "mbus.h"
#include "radioinformer.h"
#include "imbus.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <malloc.h>


using testing::_;
using testing::SetArgReferee;
using testing::SetArrayArgument;
using testing::DoAll;
using testing::NotNull;
using testing::Return;

using testing::AtMost;
using testing::AtLeast;


namespace rim
{
	class MockModbus : public Modbus
	{
	public:
		MockModbus() {}

		MockModbus(RI * ri)
		{
			this->ri = ri;
		}

		MOCK_METHOD1(connect, int(modbus_t *));

		MOCK_METHOD2(set_slave, int(modbus_t *, int));

		MOCK_METHOD2(set_debug, void(modbus_t *, int));

		MOCK_METHOD4(read_registers, int(modbus_t *, int, int, uint16_t *));

		MOCK_METHOD1(strerror, const char *(int));

		MOCK_METHOD4(write_registers, int(modbus_t *, int, int, const uint16_t *));

		MOCK_METHOD5(new_rtu, modbus_t *(const char *, int, char, int, int));
	};



// ================================= isRunning / changeState ================================ //

	/**
	 * Функция: bool RI::isRunning()
	 * Проверка сеттера для переменной moduleState
	 **/
	TEST(test_mbus, isRunning_and_changeState_check)
	{
		RI ri;
		Modbus port = Modbus(&ri);

		port.changeState(Modbus::modBusState::active);
		ASSERT_EQ(port.isRunning(), true) <<
			"\n\tIncorrect modele state: inactive[false], need to be active[true]\n";

		port.changeState(Modbus::modBusState::inactive);
		ASSERT_EQ(port.isRunning(), false) <<
			"\n\tIncorrect modele state: active[true], need to be inactive[false]\n";

		ri.~RI();
		port.~Modbus();
	}








// ========================================== write ========================================= //

	/**
	 * Функция: void Modbus::write(int command)
	 * Положительное возвращаемое значение
	 **/
	TEST(test_mbus, write_CMD_READ_REGISTERS_true)
	{
		RI * ri = new RI();
		MockModbus mockPort(ri);
		Modbus * port = new Modbus(ri);
		int returnValue = 0;
		uint16_t regsToReading[REG_TO_READ_NUMBER] = 
			{ 0, 0, 0, 0, 123, 0b1010111101010010, 0, 556 };
		bool result = true;

		EXPECT_CALL(mockPort, 
					read_registers(_, _, _, NotNull()))
					.WillOnce(DoAll(SetArrayArgument<3>(regsToReading, 
														regsToReading + REG_TO_READ_NUMBER),
									Return(returnValue)));


		ri->curSignalFromUser = 0;


		mockPort.write(CMD_READ_REGISTERS);


		// Проверка
		result = (ri->serialNumber == std::to_string(regsToReading[4]) ? true : false);
		ASSERT_EQ(result, true) << "Incorrect serialNumber";

		result = (ri->version == std::to_string(regsToReading[7]) ? true : false);
		ASSERT_EQ(result, true) << "Incorrect version";

		result = (ri->RIM_status == 0 ? true : false);
		ASSERT_EQ(result, true) << "Incorrect RIM_status";

		result = (ri->curSignalFromUser == 0b1111 ? true : false);
		ASSERT_EQ(result, true) << "Incorrect curSignalFromUser";

		result = ri->statusReceivDann;
		ASSERT_EQ(result, true) << "Incorrect statusReceivDann";

		result = ri->statusSendDann;
		ASSERT_EQ(result, true) << "Incorrect statusSendDann";

		result = ri->statusAnalisDann;
		ASSERT_EQ(result, true) << "Incorrect statusAnalisDann";

		delete ri;
		delete port;
	}


	/**
	 * Функция: void Modbus::write(int command)
	 * Отрицательное возвращаемое значение
	 **/
	TEST(test_mbus, write_CMD_READ_REGISTERS_false)
	{
		RI * ri = new RI();
		MockModbus mockPort(ri);
		Modbus * port = new Modbus(ri);
		int returnValue = -1;
		bool result;

		EXPECT_CALL(mockPort, 
					read_registers(_, _, _, _))
					.WillOnce(Return(returnValue));
		EXPECT_CALL(mockPort, 
					strerror(_)).WillOnce(Return("Test error"));

		mockPort.write(CMD_READ_REGISTERS);


		result = ri->statusReceivDann;
		ASSERT_EQ(result, false) << "Incorrect statusReceivDann";

		result = ri->statusSendDann;
		ASSERT_EQ(result, false) << "Incorrect statusSendDann";


		delete ri;
		delete port;
	}








// ==================================== init_setContext ===================================== //

	/**
	 * Функция: Modbus::init_setContext()
	 * Проверка верного возвращаемого значения из функции new_rtu
	 **/
	TEST(test_mbus, init_setContext_true)
	{
		RI * ri = new RI();
		MockModbus mockPort(ri);
		Modbus * port = new Modbus(ri);
		bool result = false;
		modbus_t * mbus_context = NULL;

		mbus_context = (modbus_t*)malloc(sizeof(mbus_context));

		EXPECT_CALL(mockPort, 
					new_rtu(_, _, _, _, _)).WillOnce(Return(mbus_context));

		result = mockPort.init_setContext();

		ASSERT_EQ(result, true) << "";

		delete ri;
		delete port;

		free(mbus_context);
	}


	/**
	 * Функция: Modbus::init_setContext()
	 * Проверка отрицательного возвращаемого значения из функции new_rtu
	 **/
	TEST(test_mbus, init_setContext_false)
	{
		RI * ri = new RI();
		MockModbus mockPort(ri);
		Modbus * port = new Modbus(ri);
		bool result = false;
		modbus_t * mbus_context = NULL;

		EXPECT_CALL(mockPort, 
					new_rtu(_, _, _, _, _)).WillOnce(Return(mbus_context));

		EXPECT_CALL(mockPort, 
					strerror(_)).WillOnce(Return("Test error"));

		result = mockPort.init_setContext();

		ASSERT_EQ(result, false) << "";

		delete ri;
		delete port;

		free(mbus_context);
	}







// =================================== init_connectToPort =================================== //

	/**
	 * Функция: Modbus::init_connectToPort()
	 * Проверка верного возвращаемого значения из функции connect
	 **/
	TEST(test_mbus, init_connectToPort_true)
	{
		RI * ri = new RI();
		MockModbus mockPort(ri);
		Modbus * port = new Modbus(ri);
		bool result = false;
		int returnValue = 0;

		EXPECT_CALL(mockPort, 
					connect(_)).WillOnce(Return(returnValue));

		result = mockPort.init_connectToPort();

		ASSERT_EQ(result, true) << "";

		delete ri;
		delete port;
	}


	/**
	 * Функция: Modbus::init_connectToPort()
	 * Проверка отрицательного возвращаемого значения из функции connect
	 **/
	TEST(test_mbus, init_connectToPort_false)
	{
		RI * ri = new RI();
		MockModbus mockPort(ri);
		Modbus * port = new Modbus(ri);
		bool result = false;
		int returnValue = -1;

		EXPECT_CALL(mockPort, 
					connect(_)).WillOnce(Return(returnValue));
		EXPECT_CALL(mockPort, 
					strerror(_)).WillOnce(Return("Test error"));

		result = mockPort.init_connectToPort();

		ASSERT_EQ(result, false) << "";

		delete ri;
		delete port;
	}
}
