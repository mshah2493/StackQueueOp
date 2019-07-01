#include "Array.h"

template <class T>
class Stack : public Array<T>
{
	public:
		Stack();
		
		~Stack();

		//************************************
		// Method:    Add - Add objects into an array
		// FullName:  Queue::Add (overridden from Array)
		// Access:    public 
		// Returns:   void
		// Parameter: T value
		//************************************
		void Add(T value);

		//************************************
		// Method:    Get - Get objects from an array
		// FullName:  Queue::Get (overridden from Array)
		// Access:    public 
		// Returns:   T
		// Parameter:
		//************************************
		T Get();

		//************************************
		// Method:    IsEmpty - checks if an array is empty
		// FullName:  Queue::IsEmpty (overridden from Array)
		// Access:    public 
		// Returns:   bool
		// Parameter:
		//************************************
		bool IsEmpty();

	private:
		int top;
};

template <class T>
Stack<T>::Stack() : Array()
{
	top = -1;
}

template <class T>
Stack<T>::~Stack()
{
}

template <class T>
void Stack<T>::Add(T value)
{
	if (!IsBetweenBoundries(value))
	{
		throw std::range_error("Value is smaller or bigger than the min-max values.");
	}

	if (IsFull())
	{
		Resize();
	}

	array[++top] = value;

	size += 1;
}

template <class T>
T Stack<T>::Get()
{
	if (IsEmpty())
	{
		throw std::runtime_error("Stack is empty.");
	}

	size -= 1;

	return array[top--];
}

template <class T>
bool Stack<T>::IsEmpty()
{
	return top == -1;
}

