#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "Figure.h"

class Rectangle : public Figure {
protected:
	float width, height;
public:
	Rectangle(float w = 0, float h = 0);
	Rectangle(Rectangle& other);
	virtual float Area();
	virtual void Input(istream& inDevice);
	virtual char* className() {
		return (char*)"Rectangle";
	}
	virtual Figure* Clone();
};

#endif
