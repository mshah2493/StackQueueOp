#include<gtest/gtest.h>

#include "core/Stack.h"

struct StackGTests : public testing::Test
{
	void SetUp()
	{ }

	void TearDown()
	{ }
};

TEST_F(StackGTests, Test_Stack_Int_Add)
{
	Stack<int> stack;
	stack.Add(1);
	
	ASSERT_EQ(stack.Size(), 1);
	ASSERT_EQ(stack.Get(), 1);
}

TEST_F(StackGTests, Test_Stack_String_Add)
{
	Stack<std::string> stack;
	stack.Add("Hello");

	ASSERT_EQ(stack.Size(), 1);
	ASSERT_EQ(stack.Get(), "Hello");
}

TEST_F(StackGTests, Test_Stack_Float_Add)
{
	Stack<float> stack;
	stack.Add(1.5);

	ASSERT_EQ(stack.Size(), 1);
	ASSERT_EQ(stack.Get(), 1.5);
}

TEST_F(StackGTests, Test_Stack_Double_Add)
{
	Stack<double> stack;
	stack.Add(50.50);

	ASSERT_EQ(stack.Size(), 1);
	ASSERT_EQ(stack.Get(), 50.50);
}

TEST_F(StackGTests, Test_Stack_Char_Add)
{
	Stack<char> stack;
	stack.Add('A');

	ASSERT_EQ(stack.Size(), 1);
	ASSERT_EQ(stack.Get(), 'A');
}

TEST_F(StackGTests, Test_Stack_Size)
{
	Stack<int> stack;

	for (int i = 1; i < 11; ++i)
	{
		stack.Add(i);
	}

	ASSERT_EQ(stack.Size(), 10);
}

TEST_F(StackGTests, Test_Stack_Dynamicity)
{
	Stack<int> stack; //capacity is 10

	for (int i = 1; i < 12; ++i) //adding 11 values
	{
		stack.Add(i);
	}

	ASSERT_EQ(stack.Size(), 11);
}

TEST_F(StackGTests, Test_Stack_IsEmpty)
{
	Stack<char> stack;
	stack.Add('A');

	ASSERT_EQ(stack.IsEmpty(), false);
}

TEST_F(StackGTests, Test_Stack_Get)
{
	Stack<int> stack; //capacity is 10

	for (int i = 1; i < 12; ++i) //adding 11 values
	{
		stack.Add(i);
	}

	for (int i = 11; i > 0; --i) //testing 11 values
	{
		ASSERT_EQ(stack.Get(), i);
	}
}

TEST_F(StackGTests, Test_Stack_Int_BoundryValue)
{
	Stack<int> stack;

	try
	{
		stack.Add(INT_MAX + 1);
	}
	catch (std::range_error const & err)
	{
		EXPECT_EQ(err.what(), std::string("Value is smaller or bigger than the min-max values."));
	}
}

TEST_F(StackGTests, Test_Stack_Long_BoundryValue)
{
	Stack<long> stack;

	try
	{
		stack.Add(LONG_MAX + 1);
	}
	catch (std::range_error const & err)
	{
		EXPECT_EQ(err.what(), std::string("Value is smaller or bigger than the min-max values."));
	}
}

TEST_F(StackGTests, Test_Stack_Char_BoundryValue)
{
	Stack<char> stack;

	try
	{
		char ch = CHAR_MAX + '1';
		stack.Add(ch);
	}
	catch (std::range_error const & err)
	{
		EXPECT_EQ(err.what(), std::string("Value is smaller or bigger than the min-max values."));
	}
}

TEST_F(StackGTests, Test_Stack_Empty_Exception)
{
	Stack<char> stack;

	try
	{
		stack.Get();
	}
	catch (std::runtime_error const & err)
	{
		EXPECT_EQ(err.what(), std::string("Stack is empty."));
	}
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	
	int ret = RUN_ALL_TESTS();

	return ret;
}