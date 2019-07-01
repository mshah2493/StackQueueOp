#include <string>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

template <class T>
class Array
{
	public:
		Array();

		~Array();

		//************************************
		// Method:    Add - Add objects into an array
		// FullName:  Array::Add
		// Access:    public 
		// Returns:   void
		// Parameter: T value
		//************************************
		virtual void Add(T value) = 0;

		//************************************
		// Method:    Get - Get objects from an array
		// FullName:  Array::Get
		// Access:    public 
		// Returns:   T
		// Parameter:
		//************************************
		virtual T Get() = 0;

		//************************************
		// Method:    IsEmpty - checks if an array is empty
		// FullName:  Array::IsEmpty
		// Access:    public 
		// Returns:   bool
		// Parameter:
		//************************************
		virtual bool IsEmpty() = 0;

		//************************************
		// Method:    Size - checks the size of an array
		// FullName:  Array::Size
		// Access:    public 
		// Returns:  
		// Parameter:
		//************************************
		size_t Size();

	protected:
		T * array;
		size_t size;
		int capacity = 10;

		//************************************
		// Method:    IsFull - checks the array is full
		// FullName:  Array::IsFull
		// Access:    protected 
		// Returns:  bool
		// Parameter:
		//************************************
		bool IsFull();

		//************************************
		// Method:    Resize - Resize an array
		// FullName:  Array::Resize
		// Access:    protected 
		// Returns:  void
		// Parameter:
		//************************************
		void Resize();

		//************************************
		// Method:    IsBetweenBoundries - checks if the value is between boundry values of a datatype
		// FullName:  Array::IsBetweenBoundries
		// Access:    protected 
		// Returns:  bool
		// Parameter:
		//************************************
		bool IsBetweenBoundries(T value);

	private:
		std::string dataType;
};

template <class T>
Array<T>::Array()
{
	array = new T[capacity];

	if (array == NULL)
	{
		std::runtime_error("Initialization of the array Failed.");
	}

	size = 0;
}

template <class T>
Array<T>::~Array()
{
	delete[] array;
}

template <class T>
size_t Array<T>::Size()
{
	return size;
}

template <class T>
bool Array<T>::IsFull()
{
	return size == capacity;
}

template <class T>
void Array<T>::Resize()
{
	int newCapacity = capacity * 2;

	T * temp = new T[newCapacity];

	if (temp == NULL)
	{
		std::runtime_error("Resizing the array Failed.");
	}

	memcpy(temp, array, capacity * sizeof(T));

	capacity = newCapacity;

	delete[] array;

	array = temp;
}

template <class T>
bool Array<T>::IsBetweenBoundries(T value)
{
	dataType = typeid(value).name();
	
	if (dataType.find("basic_string") != std::string::npos) return true;
	
	return value > std::numeric_limits<T>::min() && value <= std::numeric_limits<T>::max();
}