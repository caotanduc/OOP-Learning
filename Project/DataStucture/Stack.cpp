#include "Stack.h"

template <class T>
void Stack<T>::push(T& a) {
	if (isFull() == true) 
		return;
	
	nCount += 1;
	data.push_back(a);
}


