#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "Ellipse.h"

class Circle : public Ellipse {
public:
	Circle(float r = 0);
	virtual void Input(istream& inDev);
	virtual char*  className() {
		return (char*)"Circle";
	}
	virtual Figure* Clone();
};

#endif
