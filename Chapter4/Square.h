#ifndef _SQUARE_H
#define _SQUARE_H

#include "Rectangle.h"

class Square: public Rectangle {
public:
	Square(float a = 0);
	void Input(istream& inDevice);
};

#endif
