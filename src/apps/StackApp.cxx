#include "core/Stack.h"

int main(int argc, char *argv[])
{
	Stack<int> intStack;
	Stack<char> charStack;
	Stack<std::string> stringStack;
 
	std::cout << "----------STACK----------" << std::endl;
	std::cout << std::endl;

	for (int i = 1; i < 11; ++i)
	{
		intStack.Add(i);
	}

	for (int i = 1; i < 11; ++i)
	{
		std::cout << std::to_string(intStack.Get()) << std::endl;
	}

	for (int i = 1; i < 11; ++i)
	{
		intStack.Add(i);
	}

	intStack.Add(11);
	//intStack.Add(INT_MAX + 1);

	std::cout << std::to_string(intStack.Get()) << std::endl;

	for (int i = 1; i < 11; ++i)
	{
		char ch = i + '@';
		charStack.Add(ch);
	}

	for (int i = 1; i < 11; ++i)
	{
		std::cout << charStack.Get() << std::endl;
	}

	for (int i = 1; i < 11; ++i)
	{
		char ch = i + '@';
		charStack.Add(ch);
	}

	charStack.Add('K');

	std::cout << charStack.Get() << std::endl;

	stringStack.Add("Hello");

	std::cout << stringStack.Get() << std::endl;

	return 0;
}