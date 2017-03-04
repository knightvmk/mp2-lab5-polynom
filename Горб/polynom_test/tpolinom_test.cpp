#include "tpolinom.h"
#include <gtest.h>

TEST(TPolinom, can_create_polinom)
{
	ASSERT_NO_THROW(TPolinom a);
};

TEST(TPolinom, can_create_by_string)
{
	string exp = "10x3y7z0+2x1y1z3";
	ASSERT_NO_THROW(TPolinom a(exp));
};

TEST(TPolinom, can_create_by_string_with_minus)
{
	string exp = "10x3y7z0-2x1y1z3";
	ASSERT_NO_THROW(TPolinom a(exp));
};

TEST(TPolinom, can_create_polinom_by_polinom_no_throws)
{
	TPolinom b("10x2y2z2 + 3x3y2z2");
	ASSERT_NO_THROW(TPolinom a(b));
};

TEST(TPolinom, can_create_polinom_by_polinom_by_compare)
{
	TPolinom b("10x2y2z2 + 3x3y2z2");
	TPolinom a(b);
	EXPECT_EQ(a, b);
};

TEST(TPolinom, can_work_operator_assignment)
{
	TPolinom a("10x2y2z2 + 3x3y2z2");
	TPolinom b("10x3y7z0-2x1y1z3");
	ASSERT_NO_THROW(b = a);
};

TEST(TPolinom, can_add_two_polinoms)
{
	TPolinom a("5x2y2z2 + 3x3y3z3");
	TPolinom b("10x2y2z2 + 1x3y3z3");
	TPolinom c("15x2y2z2+4x3y3z3");
	EXPECT_EQ(a + b, c);
};

TEST(TPolinom, can_add_two_polinoms_diff_indexes)
{
	TPolinom a("5x2y2z2 + 3x3y3z3");
	TPolinom b("10x2y2z2 + 1x2y3z3");
	TPolinom c("15x2y2z2+3x3y3z3+1x2y3z3");
	EXPECT_EQ(a + b, c);
};

TEST(TPolinom, can_add_two_polinoms_diff_indexes_hard_test)
{
	TPolinom a("5x2y2z2 + 3x3y3z3 -5x2y2z2- 3x5y5z9");
	TPolinom b("10x2y2z2 + 1x2y3z3 +4x2y2z2+ 3x5y5z8");
	TPolinom c("14x2y2z2 + 3x3y3z3 + 1x2y3z3 - 3x5y5z9 + 3x5y5z8");
	EXPECT_EQ(a + b, c);
};

TEST(TPolinom, can_multiply_two_singe_polinoms_noneq_indexes)
{
	TPolinom a("5 x2y2z2");
	TPolinom b("2 x3y4z2");
	TPolinom c("10x5y6z4");
	EXPECT_EQ(a*b, c);
};

TEST(TPolinom, can_divide_two_single_polinoms_noneq_indexes)
{
	TPolinom a("15x2y4z8");
	TPolinom b("3 x2y2z2");
	TPolinom c("5 x0y2z6");
	EXPECT_EQ(a / b, c);
};

TEST(TPolinom, can_multiply_two_double_polinoms_noneq_indexes)
{
	TPolinom a("5 x2y2z2 + 10x2y2z2");
	TPolinom b("2 x3y4z2 +3x0y1z1");
	TPolinom c("30x5y6z4 + 45x2y3z3");
	EXPECT_EQ(a*b, c);
};

TEST(TPolinom, can_return_string_all_polynom)
{
	TPolinom a("5 x2y2z2 - 10x2y2z2");
	string res = a.ToString();
	EXPECT_EQ(res, "5x2y2z2-10x2y2z2");
};

TEST(TPolinom, can_return_string_monom_by_pos)
{
	TPolinom a("5x2y2z2 + 3x3y3z3 -5x2y2z2- 3x5y5z9");
	string res = a.ToString(2);
	EXPECT_EQ(res, "3x3y3z3");
};

TEST(TPolinom, can_calculate_single_polynom)
{
	TPolinom a("3x3y3z3");
	double res = 3;
	EXPECT_EQ(res, a.Calculate(1, 1, 1));
};

TEST(TPolinom, can_calculate_double_polynom)
{
	TPolinom a("3x3y3z3-4x2y3z8");
	double res = -1;
	EXPECT_EQ(res, a.Calculate(1, 1, 1));
};

TEST(TPolinom, can_calculete_big_numbers)
{
	TPolinom a("5x2y2z2 + 3x3y3z3");
	double res = 1856;
	EXPECT_EQ(res, a.Calculate(2, 2, 2));
};

TEST(TPolinom, can_mult_polynom_by_value)
{
	TPolinom a("3x3y3z3-4x2y3z8");
	TPolinom c("9x3y3z3-12x2y3z8");
	TPolinom b = a * 3;
	EXPECT_EQ(b, c);
};