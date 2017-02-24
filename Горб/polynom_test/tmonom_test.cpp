#include "tmonom.h"
#include <gtest.h>

TEST(TMonom, can_create_without_throws)
{
	ASSERT_NO_THROW(TMonom a);
};

TEST(TMonom, can_add_two_monoms)
{
	TMonom a(2, 0);
	TMonom b(3, 0);
	TMonom c(5, 0);
	EXPECT_EQ(a + b, c);
};

TEST(TMonom, cant_add_two_monoms_diff_ind)
{
	TMonom a(2, 1);
	TMonom b(3, 0);
	ASSERT_ANY_THROW(a + b);
};

TEST(TMonom, can_substract_two_monoms)
{
	TMonom a(5, 0);
	TMonom b(2, 0);
	TMonom c(3, 0);
	EXPECT_EQ(a - b, c);
};

TEST(TMonom, cant_substract_two_monoms_diff_ind)
{
	TMonom a(5, 0);
	TMonom b(2, 2);
	ASSERT_ANY_THROW(a - b);
};

TEST(TMonom, can_compare_eq_monoms)
{
	TMonom a(2, 0);
	TMonom b(2, 0);
	EXPECT_EQ(a, b);
}; 

TEST(TMonom, can_compare_non_eq_monoms)
{
	TMonom a(2, 0);
	TMonom b(2, 1);
	EXPECT_NE(a, b);
};

TEST(TMonom, can_copy_operator)
{
	TMonom a(2, 2);
	TMonom b;
	b = a;
	EXPECT_EQ(a, b);
};

TEST(TMonom, can_copy_operator_has_own_memory)
{
	TMonom a(2, 2);
	TMonom b;
	b = a;
	b.SetConsta(1);
	EXPECT_NE(a, b);
};

TEST(TMonom, can_mult_two_monoms)
{
	TMonom a(5, 1);
	TMonom b(2, 2);
	TMonom c(10, 3);
	EXPECT_EQ(a * b, c);
};

TEST(TMonom, can_div_two_monoms)
{
	TMonom a(15, 3);
	TMonom b(3, 2);
	TMonom c(5, 1);
	EXPECT_EQ(a / b, c);
};

TEST(TMonom, can_set_consta)
{
	TMonom a(5, 2);
	a.SetConsta(1);
	TMonom b(1, 2);
	EXPECT_EQ(a , b);
};

TEST(TMonom, can_set_ind)
{
	TMonom a(5, 2);
	a.SetIndex(1);
	TMonom b(5, 1);
	EXPECT_EQ(a, b);
};

TEST(TMonom, can_get_ind)
{
	TMonom a(5, 2);
	EXPECT_EQ(a.GetIndex(), 2);
};

TEST(TMonom, can_get_consta)
{
	TMonom a(5, 2);
	EXPECT_EQ(a.GetConsta(), 5);
};

