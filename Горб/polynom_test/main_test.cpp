#include <gtest.h>
#define _CRT_SECURE_NO_WARNINGS

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}