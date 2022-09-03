#ifndef STACK_H
#define STACK_H
// Auther: Lane Murray
// Date: 9/21/2021 

template <typename T>
class stackADT
{
public:

	virtual void initializeStack() = 0;
	virtual bool isEmpty() const = 0;
	virtual bool isFullStack() const = 0;
	virtual void push(const T& element) = 0;
	virtual T top() const = 0;
	virtual void pop() = 0;
	virtual void purge() = 0;
};


#endif