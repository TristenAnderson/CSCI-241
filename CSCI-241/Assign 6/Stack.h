#pragma once

#ifndef STACK_H
#define STACK_H

#include <ostream>
using std::ostream;

template <typename T>
class Stack
{

	template <typename T>
	friend std::ostream& operator<<(std::ostream& lhs, const Stack<T>& rhs);

private:
	size_t stackSize, stackCapacity;
	int topSub;
	T * stkArr; 

public:
	Stack();
	~Stack();							//destructor
	Stack(const Stack<T>& other);		//copy constructor

	//member fuctions
	void clear();
	int size() const;
	int capacity() const;
	bool empty() const;
	const T& top() const;
	void push(const T&);
	void pop();
	void reserve(size_t);

	//assignment operator overload
	Stack<T>& operator = (const Stack<T>& other);

};


template <typename T>
Stack<T>::Stack()
{
	stackCapacity = 0;
	stackSize = 0;
	stkArr = nullptr;
}

template <typename T>
Stack<T>::~Stack()
{
	delete[] stkArr;
}

template <typename T>
Stack<T>::Stack(const Stack<T>& other)
{
	stackCapacity = other.stackCapacity;
	stackSize = other.stackSize;

	if (stackCapacity == 0)
		stkArr = nullptr;
	else
		stkArr = new T[stackCapacity];

	for (size_t i = 0; i < stackSize; ++i)
		stkArr[i] = other.stkArr[i];
}

template <typename T>
int Stack<T>::size() const
{
	return stackSize;
}

template <typename T>
int Stack<T>::capacity() const
{
	return stackCapacity;
}

template <typename T>
bool Stack<T>::empty() const
{
	if (stackSize == 0)
		return true;
	else
		return false;
}

template <typename T>
void Stack<T>::clear()
{
	stackSize = 0;
}

template <class T>
void Stack<T>::push(const T& val)
{
	// If stack is full, allocate additional storage
	if (stackSize == stackCapacity)
	{
		if (stackCapacity == 0)
			reserve(1);
		else
			reserve(stackCapacity * 2);
	}

	stkArr[stackSize++] = val;
}

template <class T>
const T& Stack<T>::top() const
{
	if (empty())
		throw std::underflow_error("Stack underflow on call to top()");

	return stkArr[stackSize - 1];
}

template <class T>
std::ostream& operator<<(std::ostream& lhs, const Stack<T>& rhs)
{
	for (size_t i = 0; i < rhs.stackSize; ++i)
		lhs << rhs.stkArr[i] << ' ';

	return lhs;
}

template <class T>
Stack<T>& Stack<T>::operator = (const Stack<T>& other)
{
	if (stkArr == other.stkArr)
		return *this;

	delete[] this->stkArr;
	stackCapacity = other.stackCapacity;
	stackSize = other.stackSize;

	if (stackCapacity == 0)
		stkArr = nullptr;
	else
		stkArr = new T[stackCapacity];

	for (size_t i = 0; i < stackSize; ++i)
		stkArr[i] = other.stkArr[i];

	return *this;
}

template <class T>
void Stack<T>::pop() 
{
	--stackSize;
}

template <class T>
void Stack<T>::reserve(size_t n)
{
	if (n < stackSize || n == stackCapacity)
		return;

	T* tempArray = new T[n];

	for (size_t i = 0; i < stackSize; ++i)
	{
		tempArray[i] = stkArr[i];
	}

	stackCapacity = n;
	delete[] stkArr;
	stkArr = tempArray;
}

#endif  /* STACK_H */