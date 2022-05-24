#ifndef _CONTAINER_H
#define _CONTAINER_H
#define MAX_ELEMENTS (int)50
#include <iostream>
using namespace std;

template <class T>
class Container {
protected:
	int nCount;
public:
	virtual bool isEmpty() const;
	virtual bool isFull() const;
	virtual int numberOfElements() const;

	virtual void push(T&);
	virtual T& pop() = 0;
	virtual T& top() = 0;
};

#endif
