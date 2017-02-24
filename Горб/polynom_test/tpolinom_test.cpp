#include "tpolinom.h"
#include <gtest.h>

TEST(TPolinom, can_create_polinom)
{
	ASSERT_NO_THROW(TPolinom a);
}

TEST(TPolinom, can_create_by_string)
{
	string exp = "10x3y7z0+2x1y1z3";
	ASSERT_NO_THROW(TPolinom a(exp));
}

TEST(TPolinom, can_create_by_string_with_minus)
{
	string exp = "10x3y7z0-2x1y1z3";
	ASSERT_NO_THROW(TPolinom a(exp));
}

TEST(TPolinom, can_add_two_polinoms)
{
	TPolinom a("5x2y2z2 + 3x3y3z3");
	TPolinom b("10x2y2z2 + 1x3y3z3");
	TPolinom c("15x2y2z2+4x3y3z3");
	EXPECT_EQ(a + b, c);
}

