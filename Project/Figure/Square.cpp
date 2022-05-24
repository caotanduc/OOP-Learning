#include "Square.h"

Square::Square(float a) {
	width = height = a;
	classNameStr = (char*)"Square";
	addSample(this);
}

void Square::Input(istream& inDevice) {
	inDevice >> width;
	height = width;
}
