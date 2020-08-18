#pragma once

#ifndef QUEUE_H
#define QUEUE_H

#include <ostream>
#include <stdexcept>

using std::underflow_error;

template <typename T>
struct Node
{

	T data;
	Node<T>* next;
	Node(const T& = T(), Node<T>* next = nullptr);

};

template <class T>
Node<T>::Node(const T& data, Node* next)
{
	this->data = data;
	this->next = next;
}
 
template <typename T>																//forward declaration of template class Queue 
class Queue;

template <class T>
std::ostream& operator<< (std::ostream&, const Queue<T>&);							//forward declaration of output operator<< template 

template <typename T>
class Queue
{

	friend std::ostream& operator<< <>(std::ostream& lhs, const Queue<T>& rhs);			//friend declaration of stream insertion operator

private:
	Node<T>* qFront;
	Node<T>* qBack;
	unsigned int qSize;

public:
	Queue();
	~Queue();
	Queue(const Queue<T>& other);													//copy constructor

	Queue<T>& operator=(const Queue<T>&);											//copy assignment operator

	size_t size() const;
	bool empty() const;
	void clear();
	const T& front() const;
	const T& back() const;
	void push(const T&);
	void pop();
	void copyList(const Queue<T>& other);

};


template <typename T>
Queue<T>::Queue()
{
	qFront = nullptr;
	qBack = nullptr;
	qSize = 0;
}

template <typename T>
Queue<T>::~Queue()
{
	clear();
}

template <class T>
Queue<T>::Queue(const Queue<T>& other)
{
	// Set the new Queue object to empty
	qFront = qBack = nullptr;
	qSize = 0;

	// Copy the other Queue's linked list
	copyList(other);
}

template <typename T>
size_t Queue<T>::size() const
{
	return qSize;
}

template <typename T>
bool Queue<T>::empty() const
{
	return (qSize == 0);
}

template <typename T>
void Queue<T>::clear()
{
	while (!empty())
	{
		pop();
	}
}

template <typename T>
const T& Queue<T>::front() const
{
	if (empty()) {
		throw underflow_error("Queue underflow on front()"); 
	}

	return qFront->data;
}

template <typename T>
const T& Queue<T>::back() const
{
	//if the queue is empty throw an underflow error
	if (empty()) {
		throw underflow_error("Queue underflow on back()");
	}

	return qBack->data;
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
	if (this != &other)
	{
		// Make the left Queue object empty
		this->clear();

		// Copy the other Queue's linked list
		copyList(other);
	}
	return *this;
}

template <typename T>
std::ostream& operator<< (std::ostream& lhs, const Queue<T>& rhs)
{
	Node<T>* ptr;

	for (ptr = rhs.qFront; ptr != nullptr; ptr = ptr->next)
		lhs << ptr->data << ' ';

	return lhs;
}

template <typename T>
void Queue<T>::pop()
{
	//if the queue is empty throw an underflow error 
	if (empty()) {
		throw underflow_error("Queue underflow on pop()");
	}

	// Remove first node in list
	Node<T>* delNode;
	delNode = qFront;
	qFront = qFront->next;

	// If queue is now empty, make sure both pointers are nullptr
	if (qFront == nullptr)
		qBack = nullptr;

	delete delNode;
	--qSize;
}

template < class T >
void Queue<T>::push(const T& val)
{
	Node<T>* newNode = new Node<T>(val);

	if (empty())
		qFront = newNode;
	else
		qBack->next = newNode;

	qBack = newNode;
	++qSize;
}

template <class T>
void Queue<T>::copyList(const Queue<T>& other)
{
	Node<T>* ptr;

	for (ptr = other.qFront; ptr != nullptr; ptr = ptr->next)
		push(ptr->data);
}

#endif /*QUEUE_H*/
