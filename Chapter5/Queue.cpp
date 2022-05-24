#include "Queue.h"

void Queue::enqueue(Object& obj) {
	if (!isFull()) {
		listObjs.addLast(obj);
		++iCount;
	}
}


Objects& Queue::dequeue() {
	if (!isEmpty()) {
		--iCount;
		return listObjs.extractHead();
	}
}


Object& Queue::front() {
	if (!isEmpty()) {
		return listObjs.getHead();
	}
}
