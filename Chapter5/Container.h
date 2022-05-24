#ifndef _CONTAINER_H
#define _CONTAINER_H
#include "Object.h"

class Container {
public:
	virtual void put(Object&) = 0;
	virtual Object& get() = 0;
	virtual Object& seek() = 0;
	virtual bool isEmpty() const;
	virtual bool isFull() const;
	virtual int numberOfElems() const;
protected:
	int iCount;
};

#endif
