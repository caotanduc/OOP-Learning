#include "Container.h"

bool Container::isEmpty() const {
	if (iCount == 0)
		return true;
	return false;
}

bool Container::isFull() const {
	if (iCount == MAX_ELEMENTS)
		return true;
	return false;
}


int Container::numberOfElems() const {
	return iCount;
}
