#ifndef _ELLIPSE_H
#define _ELLIPSE_H
#define PI (float)3.14159
#include "Figure.h"

class Ellipse: public Figure {
protected:
	float Ra, Rb;
public:
	Ellipse(float a = 0, float b = 0);
	Ellipse(Ellipse& other);
	virtual void Input(istream& inDev);
	virtual float Area();
	virtual char* className() {
		return (char*)"Ellipse";
	}
	virtual Figure* Clone();
};

#endif
