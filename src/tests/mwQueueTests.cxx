#include<gtest/gtest.h>

#include "core/Queue.h"

struct QueueGTests : public testing::Test
{
	void SetUp()
	{ }

	void TearDown()
	{ }
};

TEST_F(QueueGTests, Test_Queue_Int_Add)
{
	Queue<int> queue;
	queue.Add(1);

	ASSERT_EQ(queue.Size(), 1);
	ASSERT_EQ(queue.Get(), 1);
}

TEST_F(QueueGTests, Test_Queue_String_Add)
{
	Queue<std::string> queue;
	queue.Add("Hello");

	ASSERT_EQ(queue.Size(), 1);
	ASSERT_EQ(queue.Get(), "Hello");
}

TEST_F(QueueGTests, Test_Queue_Float_Add)
{
	Queue<float> queue;
	queue.Add(1.5);

	ASSERT_EQ(queue.Size(), 1);
	ASSERT_EQ(queue.Get(), 1.5);
}

TEST_F(QueueGTests, Test_Queue_Double_Add)
{
	Queue<double> queue;
	queue.Add(50.50);

	ASSERT_EQ(queue.Size(), 1);
	ASSERT_EQ(queue.Get(), 50.50);
}

TEST_F(QueueGTests, Test_Queue_Char_Add)
{
	Queue<char> queue;
	queue.Add('A');

	ASSERT_EQ(queue.Size(), 1);
	ASSERT_EQ(queue.Get(), 'A');
}

TEST_F(QueueGTests, Test_Queue_Size)
{
	Queue<int> queue;

	for (int i = 1; i < 11; ++i)
	{
		queue.Add(i);
	}

	ASSERT_EQ(queue.Size(), 10);
}

TEST_F(QueueGTests, Test_Queue_Dynamicity)
{
	Queue<int> queue; //capacity is 10

	for (int i = 1; i < 12; ++i) //adding 11 values
	{
		queue.Add(i);
	}

	ASSERT_EQ(queue.Size(), 11);
}

TEST_F(QueueGTests, Test_Queue_IsEmpty)
{
	Queue<char> queue;
	queue.Add('A');

	ASSERT_EQ(queue.IsEmpty(), false);
}

TEST_F(QueueGTests, Test_Queue_Get)
{
	Queue<int> queue; //capacity is 10

	for (int i = 1; i < 12; ++i) //adding 11 values
	{
		queue.Add(i);
	}

	for (int i = 1; i < 12; ++i) //testing 11 values
	{
		ASSERT_EQ(queue.Get(), i);
	}
}

TEST_F(QueueGTests, Test_Queue_Int_BoundryValue)
{
	Queue<int> queue;

	try
	{
		queue.Add(INT_MAX + 1);
	}
	catch (std::range_error const & err)
	{
		EXPECT_EQ(err.what(), std::string("Value is smaller or bigger than the min-max values."));
	}
}

TEST_F(QueueGTests, Test_Queue_Long_BoundryValue)
{
	Queue<long> queue;

	try
	{
		queue.Add(LONG_MAX + 1);
	}
	catch (std::range_error const & err)
	{
		EXPECT_EQ(err.what(), std::string("Value is smaller or bigger than the min-max values."));
	}
}

TEST_F(QueueGTests, Test_Queue_Char_BoundryValue)
{
	Queue<char> queue;

	try
	{
		char ch = CHAR_MAX + '1';
		queue.Add(ch);
	}
	catch (std::range_error const & err)
	{
		EXPECT_EQ(err.what(), std::string("Value is smaller or bigger than the min-max values."));
	}
}

TEST_F(QueueGTests, Test_Queue_Empty_Exception)
{
	Queue<char> queue;

	try
	{
		queue.Get();
	}
	catch (std::runtime_error const & err)
	{
		EXPECT_EQ(err.what(), std::string("Queue is empty."));
	}
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);

	int ret = RUN_ALL_TESTS();

	return ret;
}