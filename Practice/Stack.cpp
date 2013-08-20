
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
