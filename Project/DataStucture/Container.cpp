#include "Container.h"

template <class T>
bool Container<T>::isEmpty() const {
	return nCount == 0;
}


template <class T>
bool Container<T>::isFull() const {
	return nCount == MAX_ELEMENTS;
}


template <class T>
int Container<T>::numberOfElements() const {
	return nCount;
}
