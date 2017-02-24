#include "tlist.h"
#include <gtest.h>

TEST(TList, can_create_without_throws)
{
	ASSERT_NO_THROW(TList<double> a);
};

TEST(TList, can_return_true_len)
{
	TList<int> a;
	a.InsFirst(1);
	a.InsFirst(2);
	EXPECT_EQ(2, a.GetLen());
};

TEST(TList, can_ins_by_pos)
{
	TList<int> a;
	a.InsFirst(1);
	a.InsLast(3);
	a.Ins(1, 2);
	EXPECT_EQ(a.GetVal(1), 2);
};

TEST(TList, can_ins_first_and_last_by_once)
{
	TList<int> a;
	a.InsFirst(1);
	a.InsLast(2);
	EXPECT_EQ(a.GetLen(), 2);
};

TEST(TList, can_ins_by_random)
{
	TList<int> a;
	a.InsFirst(1);
	a.Ins(1, 2);
	a.Ins(2, 3);
	EXPECT_EQ(a.GetLen(), 3);
};

TEST(TList, second_can_ins_by_random)
{
	TList<int> a;
	a.InsFirst(1);
	a.Ins(1, 2);
	a.Ins(2, 3);
	a.InsFirst(3);
	a.InsLast(9);
	a.InsLast(2);
	a.Ins(3, 6);
	EXPECT_EQ(a.GetLen(), 7);
};

TEST(TList, can_del_first_check_len)
{
	TList<int> a;
	a.InsFirst(1);
	a.InsFirst(2);
	a.DelFirst();
	EXPECT_EQ(a.GetLen(), 1);
};

TEST(TList, can_del_first_check_val)
{
	TList<int> a;
	a.InsFirst(1);
	a.InsFirst(2);
	a.DelFirst();
	EXPECT_EQ(a.GetVal(0), 1);
};

TEST(TList, can_del_last_check_val)
{
	TList<int> a;
	a.InsFirst(1);
	a.InsFirst(3);
	a.Ins(1, 2);
	a.DelLast();
	EXPECT_EQ(a.GetVal(1), 2);
};

TEST(TList, can_del_last_check_len)
{
	TList<int> a;
	a.InsFirst(1);
	a.InsFirst(3);
	a.Ins(1, 2);
	a.InsFirst(67);
	a.DelLast();
	EXPECT_EQ(a.GetLen(), 3);
};

TEST(TList, can_get_val_no_del)
{
	TList<int> a;
	a.InsLast(1);
	a.InsLast(2);
	a.InsLast(3);
	EXPECT_EQ(a.GetVal(2), 3);
};

TEST(TList, can_get_val_with_del)
{
	TList<int> a;
	a.InsLast(1);
	a.InsLast(2);
	a.InsLast(3);
	a.DelFirst();
	EXPECT_EQ(a.GetVal(0), 2);
};

TEST(TList, can_del_by_pos_check_len)
{
	TList<int> a;
	a.InsFirst(1);
	a.InsLast(2);
	a.InsLast(4);
	a.Ins(2, 3);
	a.DelCell(1);
	EXPECT_EQ(a.GetLen(),3);
};

TEST(TList, can_del_by_pos_check_val_first)
{
	TList<int> a;
	a.InsFirst(1);
	a.InsLast(2);
	a.InsLast(4);
	a.Ins(2, 3);
	a.DelCell(1);
	EXPECT_EQ(a.GetVal(1), 3);
};

TEST(TList, can_del_by_pos_check_val_second)
{
	TList<int> a;
	a.InsFirst(1);
	a.InsLast(2);
	a.InsLast(4);
	a.Ins(2, 3);
	a.DelCell(1);
	EXPECT_EQ(a.GetVal(2), 4);
};

TEST(TList, can_set_val)
{
	TList<int> a;
	a.InsFirst(2);
	a.InsFirst(4);
	a.SetVal(1, 3);
	EXPECT_EQ(a.GetVal(1), 3);
};

TEST(TList, check_stress_test_0)
{
	TList<double> a;
	a.InsLast(99);
	a.InsFirst(98);
	a.InsLast(100);
	a.InsFirst(96);
	a.Ins(1, 97);
	a.Ins(2, 98);
	a.InsFirst(96);
	a.Ins(0, 95);
	a.DelCell(5);
	a.DelFirst();
	a.DelLast();
	EXPECT_EQ(a.GetLen(), 5);
}

TEST(TList, check_stress_test_1)
{
	TList<double> a;
	a.InsLast(99);
	a.InsFirst(98);
	a.InsLast(100);
	a.InsFirst(95);
	a.Ins(1, 96);
	a.Ins(2, 97);
	a.InsFirst(94);
	a.Ins(0, 93);
	a.DelCell(5);
	a.DelFirst();
	a.DelLast();
	EXPECT_EQ(a.GetVal(4), 99);
}

TEST(TList, can_delete_list)
{
	TList<int> a;
	a.InsFirst(1);
	a.InsLast(2);
	a.InsLast(3);
	a.Delete();
	EXPECT_EQ(a.GetLen(), 0);
}

TEST(TList, can_delete_empty_list)
{
	TList<int> a;
	ASSERT_NO_THROW(a.Delete());
}