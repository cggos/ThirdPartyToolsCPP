#include <iostream>
#include <gtest/gtest.h>

#include "..\..\Algorithms\MathFuncs.h"

TEST(MathFuncs, GCD)
{
	EXPECT_EQ(-2, MathFuncs::GCD(-4, -10));
	EXPECT_EQ(6, MathFuncs::GCD(30, 18));
}

int main(int argc, char* argv[])
{
	//testing::GTEST_FLAG(output) = "xml:";
	testing::InitGoogleTest(&argc, argv);
	int ret = RUN_ALL_TESTS();

	system("pause");
	return 0;
}