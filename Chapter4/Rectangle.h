#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include <iostream>
using namespace std;

class Rectangle {
protected:
	float width, height;
public:
	Rectangle() = default;
	Rectangle(float w, float h);
	float Area();
	virtual void Input(istream& inDevice);
};

#endif
