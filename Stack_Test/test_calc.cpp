#include "../mp2-lab3-stack -forgit/TCalc.h"

#include "gtest.h"

TEST(TCalc, can_create_stack_with_positive_MaxSize)
{
  ASSERT_NO_THROW(TCalc v("2+2"));
}
/*
TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v(3);
	for (int i = 0; i < v.GetSize(); i++)
	{
		v[i] = 1;
	}
	TVector<int> v1(v);
	EXPECT_EQ(v1, v);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v(3);
	TVector<int> v1(v);
	EXPECT_EQ(0, &v == &v1);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(3);
	ASSERT_ANY_THROW(v[-1] = 2);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(3);
	ASSERT_ANY_THROW(v[100] = 2);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(3);
	ASSERT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v(3);
	TVector<int> v1(3);
	ASSERT_NO_THROW(v = v1);
	v = v1;
	EXPECT_EQ(v, v1);
}

TEST(TVector, assign_operator_changes_vector_size)
{
	TVector<int> v(3);
	TVector<int> v1(5);
	v = v1;
	EXPECT_EQ(v.GetSize(), v1.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v(3);
	TVector<int> v1(5);
	v = v1;
	EXPECT_EQ(v, v1);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v(3);
	for (int i = 0; i < v.GetSize(); i++)
	{
		v[i] = 1;
	}
	TVector<int> v1(3);
	v1 = v;
	EXPECT_EQ(1, v1 == v);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(3);
	for (int i = 0; i < v.GetSize(); i++)
	{
		v[i] = 1;
	}
	EXPECT_EQ(1, v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v(3);
	TVector<int> v1(5);
	EXPECT_NE(1, v == v1);
	
}


	v = v + 1;
	EXPECT_EQ(v, v1);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v(3);
	TVector<int> v1(3);
	for (int i = 0; i < v.GetSize(); i++)
	{
		v[i] = 2;
		v1[i] = 1;
	}
	ASSERT_NO_THROW(v-1);
	
	v = v - 1;
	EXPECT_EQ(v, v1);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v(3);
	TVector<int> v1(3);
	for (int i = 0; i < v.GetSize(); i++)
	{
		v[i] = 2;
		v1[i] = 4;
	}
	ASSERT_NO_THROW(v*2);
	v = v * 2;
	EXPECT_EQ(v, v1);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v(3);
	TVector<int> v1(3);
	TVector<int> v2(3);
	TVector<int> v_res(3);
	for (int i = 0; i < v.GetSize(); i++)
	{
		v[i] = 2;
		v1[i] = 3;
		v_res[i] = 5;
	}
	ASSERT_NO_THROW(v + v1);
	v2 = v + v1;
	EXPECT_EQ(v2, v_res);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v(3);
	TVector<int> v1(5);
	ASSERT_ANY_THROW(v + v1);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v(3);
	TVector<int> v1(3);
	TVector<int> v2(3);
	TVector<int> v_res(3);
	for (int i = 0; i < v.GetSize(); i++)
	{
		v[i] = 3;
		v1[i] = 2;
		v_res[i] = 1;
	}
	ASSERT_NO_THROW(v - v1);
	v2 = v - v1;
	EXPECT_EQ(v2, v_res);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v(3);
	TVector<int> v1(5);
	ASSERT_ANY_THROW(v - v1);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v(3);
	TVector<int> v1(3);
	int const res = 18;
	int tmp_res=0;
	for (int i = 0; i < v.GetSize(); i++)
	{
		v[i] = 3;
		v1[i] = 2;
		
	}
	ASSERT_NO_THROW(v * v1);
	tmp_res = v * v1;
	EXPECT_EQ(tmp_res, res);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v(3);
	TVector<int> v1(5);
	ASSERT_ANY_THROW(v * v1);
}
*/
