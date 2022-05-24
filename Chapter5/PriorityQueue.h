#ifndef _PRIORITYQUEUE_H
#define _PRIORITYQUEUE_H
#include "Container.h"

class PriorityQueue : public Container {
public:
	void enqueue(Object&);
	Object& dequeue();
	Object& first();
private:
	Heap<Object> listObjs;
};

#endif
