#include "../mp2-lab3-stack -forgit/TStack.h"
#include "gtest.h"

TEST(TStack, can_create_stack_with_positive_MaxSize)
{
    ASSERT_NO_THROW(TStack<int> st(5));
}

TEST(TStack, throws_when_create_stack_with_negative_size)
{
	ASSERT_ANY_THROW(TStack<int> st(-5));
}

TEST(TStack, can_create_copied_stack)
{
  TStack<int> st(5);
  for (int i = 1; i <= 5; i++)
  {
		st.Push(i);
  }
  ASSERT_NO_THROW(TStack<int> st1(st));
  EXPECT_EQ(1, 1);
}

TEST(TStack, copied_vector_is_equal_to_source_one)
{
	const int size = 5;
	TStack<int> st(size);
	for (int i = 1; i <= 5; i++)
	{
		st.Push(i);
	}
	TStack<int> st1(st);
	for (int i = 1; i <= 5; i++)
	{
		EXPECT_EQ(st.Pop(), st1.Pop());
	}
	
}/*
TEST(TStack, copied_stack_is_equal_to_source_one)
{
	int test_size = 5;
	TStack<int> st(test_size);
	for (int i = 0; i < test_size; i++)
	{
		st.Push(i+1);
	}
	TStack<int> st1(st); st.output(); st1.output();
	EXPECT_EQ(st1, st);
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
