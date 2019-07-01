This C++ project contains implementations of the Collection interface - LIFO (last-in, first-out) and FIFO (first-in, first-out). The Collection interface comprises the following operations

• Add(number) - adds the number to the queue
• Get() - removes the next number from the queue and returns it
• IsEmpty() - returns whether the queue is empty
• Size() - returns the queue's size

Note: 

• A fixed-sized arrays or pointers of template (generic) type have been used to implement collections that can grow to an arbitrary size. 
• For code reusability, I have used an Array as an abstract (interface) class that is derived by Stack and Queue classes.

Google tests (C++) are written for unit tests of both classes.

• Test_Int_Add
• Test_String_Add
• Test_Float_Add
• Test_Double_Add
• Test_Char_Add
• Test_Size
• Test_Dynamicity
• Test_IsEmpty
• Test_Get
• Test_Int_BoundryValue
• Test_Long_BoundryValue
• Test_Char_BoundryValue
• Test_Empty_Exception

For compilation process, I have used CMake for the compilation process as it is a cross-platform tool. 
There are multiple CMakeLists.txt included in the project to process different packages. 