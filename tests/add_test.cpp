#include "gtest/gtest.h"
#include <add.h>

// Simple test, does not use gmock
TEST(AddTest, check)
{
	EXPECT_EQ(myproject::add(2, 7), 9);
}

