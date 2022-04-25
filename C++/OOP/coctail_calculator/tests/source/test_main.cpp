#include <gtest/gtest.h>

#include "test_helping.cpp"
#include "test_mbus.cpp"
#include "test_radioinformer.cpp"
#include "test_rim.cpp"


int main(int argc, char ** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


/**
 * 
 * https://chromium.googlesource.com/external/github.com/google/googletest/+/refs/heads/
 * 77A9B20B4C1E02FAC90D1D942E1D4C18/googlemock/docs/cheat_sheet.md
 * 
 * 
 * 
 * 
 * 
 **/