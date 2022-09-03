#pragma once
// Auther: Lane Murray
// Date: 9/21/2021
#include <stdexcept>
#include "stackADT.h"

using namespace std;

template<typename T> // I prefer typename over class because class can get confusing when reading the code.
class stack // This entire class is pretty much exactly what was written in class.
{
private:

	T* list;
	int stackTop;
	int maxStackSize;

public:
	// Constructors
	stack(int size = 100);

	stack(const stack<T>& otherStack);

	// Destructor
	~stack();

	void initializeStack();

	void pop();

	void push(const T& element);

	T top() const;

	bool isEmpty() const;

	bool isFullStack() const;

	void purge();

	void copyStack(const stack<T>& otherStack);

	const stack<T>& operator=(const stack<T>& otherStack);
};

template <typename T>
stack<T>::stack(int size) // Constructor
{
	if (size <= 0)
	{
		maxStackSize = 100;
		stackTop = 0;
		list = new T[maxStackSize];
		throw out_of_range("Size of the array to hold the stack must be positive.");
	}
	else
	{
		maxStackSize = size;
		stackTop = 0;
		list = new T[maxStackSize];
	}
}

template <typename T> // Constructor
stack<T>::stack(const stack<T>& otherStack)
{
	list = nullptr;

	copyStack(otherStack);
}


template <typename T>
stack<T>::~stack() // Destructor
{
	delete[] list;
}

template <typename T>
void stack<T>::initializeStack() // initalizes the stack
{
	stackTop = 0;
}

template <typename T>
void stack<T>::pop() // Removes the top element from the stack
{
	if (isEmpty())
		throw out_of_range("Cannot remove from an empty stack.");

	stackTop--;
}

template <typename T>
void stack<T>::push(const T& element) // Adds a new element to the stack
{
	if (!isFullStack())
	{
		list[stackTop] = element;
		stackTop++;
	}
	else
		throw out_of_range("Cannot add to a full stack.");
}

template <typename T>
T stack<T>::top() const // Returns the top element of the stack
{
	if (isEmpty())
		throw out_of_range("Cannot use top with an empty stack.");

	return list[stackTop - 1];
}

template <typename T>
bool stack<T>::isEmpty() const // Returns true if stack is Empty, else false
{
	return stackTop == 0;
}

template <typename T>
bool stack<T>::isFullStack() const // Returns true if stack is Full, else false
{
	return stackTop == maxStackSize;
}

template<typename T>
void stack<T>::purge()
{
	while (isEmpty() != true)
	{
		pop();
	}
}

template <typename T>
void stack<T>::copyStack(const stack<T>& otherStack)
{
	delete[] list;
	maxStackSize = otherStack.maxStackSize;
	stackTop = otherStack.stackTop;

	list = new T[maxStackSize];

	for (int i = 0; i < stackTop; i++)
	{
		list[i] = otherStack.list[i];
	}
}

template <typename T>
const stack<T>& stack<T>::operator=(const stack<T>& otherStack)
{
	if (this != &otherStack)
	{
		copyStack(otherStack);
	}

	return*this;
}