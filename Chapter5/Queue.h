#ifndef _QUEUE_H
#define _QUEUE_H
#include "Container.h"

class Queue : public Container {
public:
	void enqueue(Object&);
	Object& dequeue();
	Object& first();
private:
	LinkedList<Object> listObjs;
};

#endif
