#include "PriorityQueue.h"

void PriorityQueue::enqueue(Object& obj) {
	if (!isFull()) {
		listObjs.add(obj);
		++iCount;
	}
}

Object& PriorityQueue::dequeue() {
	if (!isEmpty()) {
		--iCount;
		return listObjs.extractRoot();
	}
}

Object& PriorityQueue::first() {
	if (!isEmpty()) {
		return listObjs.getRoot();
	}
}
