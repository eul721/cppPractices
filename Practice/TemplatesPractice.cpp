#include <iostream>
#include <string>
#include <cstdlib>
#include "Stack.h"

typedef Stack<int> IntStack;

int main()
{
	try{
		IntStack intStack;
		Stack<std::string> strStack;

		intStack.push(5);
		std::cout << intStack.top() << std::endl;

		strStack.push("Hello");
		std::cout << strStack.top() << std::endl;
		strStack.pop();
		strStack.pop();
	} catch (std::exception e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return -1;
	}

	return 0;
}