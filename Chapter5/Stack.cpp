#include "Stack.h"

void Stack::push(Object& obj) {
	if (!isFull()) {
		listObjs.addFirst(obj);
		++iCount;
	}
}


Object& Stack::pop() {
	if (!isEmpty()) {
		--iCount;
		return listObjs.extractHead();
	}
}


Object& Stack::top() {
	if (!isEmpty()) {
		return listObjs.getHead();
	}
}
