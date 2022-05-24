#ifndef _TRIANGLE_H
#define _TRIANGLE_H
#include "Figure.h"

class Triangle : public Figure {
protected:
	float basesize, height;
public:
	Triangle(float a = 0, float h = 0);
	Triangle(Triangle& other);
	virtual void Input(istream& inDev);
	virtual float Area();
	virtual char* className() {
		return (char*)"Triangle";
	}
	virtual Figure* Clone();
};

#endif
