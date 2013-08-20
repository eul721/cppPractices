#ifndef STACK_H
#define STACK_H
/*
This file implements everything needed for an abstract stack data type. Implementation section could not be 
seperated from this header.
*/
#include <vector>
#include <stdexcept>

template<typename T>
class Stack
{
private: 
	std::vector<T> elems;
public:
	Stack(void);
	~Stack(void);
	Stack(const Stack<T>&); // copy constructor
	Stack<T>& operator= (const Stack<T>&);
	void push(const T&);
	void pop();
	T top();
	bool empty() const;

};


template<typename T>
Stack<T>::Stack(void)
{
}

template<typename T>
Stack<T>::~Stack(void)
{
}

template<typename T>
void Stack<T>::push(const T& elem)
{
	elems.push_back(elem);
}

template<typename T>
void Stack<T>::pop()
{
	if (elems.empty())
		throw std::out_of_range("Stack<>::pop(): empty stack");
	elems.pop_back();
}

template<typename T>
T Stack<T>::top()
{
	if (elems.empty())
		throw std::out_of_range("Stack<>::pop(): empty stack");
	return elems.back();
}

template<typename T>
bool Stack<T>::empty() const
{
	return elems.empty();
}





#endif
