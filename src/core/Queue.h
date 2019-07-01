#include "Array.h"

template <class T>
class Queue : public Array<T>
{
	public:
		Queue();

		~Queue();

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
		int front, rear;
};

template <class T>
Queue<T>::Queue() : Array()
{
	front = 0;
	rear = -1;
}

template <class T>
Queue<T>::~Queue()
{
}

template <class T>
void Queue<T>::Add(T value)
{
	if (!IsBetweenBoundries(value))
	{
		throw std::range_error("Value is smaller or bigger than the min-max values.");
	}

	if (IsFull())
	{
		Resize();
	}

	rear = (rear + 1) % capacity;
	array[rear] = value;

	size += 1;
}

template <class T>
T Queue<T>::Get()
{
	if (IsEmpty())
	{
		throw std::runtime_error("Queue is empty.");
	}

	size -= 1;

	T value = array[front++];

	return value;
}

template <class T>
bool Queue<T>::IsEmpty()
{
	return front == -1;
}