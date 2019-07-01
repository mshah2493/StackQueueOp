#include "core/Queue.h"

int main(int argc, char *argv[])
{
	Queue<int> intQueue;
	Queue<char> charQueue;

	std::cout << "----------Queue----------" << std::endl;
	std::cout << std::endl;

	for (int i = 1; i < 11; ++i)
	{
		intQueue.Add(i);
	}

	for (int i = 1; i < 11; ++i)
	{
		std::cout << std::to_string(intQueue.Get()) << std::endl;
	}

	for (int i = 1; i < 11; ++i)
	{
		intQueue.Add(i);
	}

	intQueue.Add(11);

	std::cout << std::to_string(intQueue.Get()) << std::endl;

	for (int i = 1; i < 11; ++i)
	{
		char ch = i + '@';
		charQueue.Add(ch);
	}

	for (int i = 1; i < 11; ++i)
	{
		std::cout << charQueue.Get() << std::endl;
	}

	for (int i = 1; i < 11; ++i)
	{
		char ch = i + '@';
		charQueue.Add(ch);
	}

	charQueue.Add('K');

	std::cout << charQueue.Get() << std::endl;

	return 0;
}