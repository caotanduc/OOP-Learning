#ifndef _STACK_H
#define _STACK_H
#include "Container.h"
#include <vector>

template <class T>
class Stack : public Container<T> {
private:
	vector<T> data;
public:
	void push(T&);
	T& pop();
	T& top();
};

#endif
