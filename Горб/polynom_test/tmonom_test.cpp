#include "tmonom.h"
#include <gtest.h>

TEST(TMonom, can_create_without_throws)
{
	ASSERT_NO_THROW(TMonom a);
};

TEST(TMonom, can_substract_two_monoms)
{
	TMonom a(2, 0);
	TMonom b(3, 0);
	TMonom c(5, 0);
	EXPECT_EQ(a+b, c);
};
