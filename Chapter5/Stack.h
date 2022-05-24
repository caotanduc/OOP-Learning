#ifndef _STACK_h
#define _STACK_h
#include "Container.h"

class Stack : public Container {
public:
	void push(Object&);
	Object& pop();
	Object& top();
private:
	LinkedList<Object> listObjs;
};

#endif
