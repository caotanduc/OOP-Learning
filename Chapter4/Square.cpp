#include "Square.h"

Square::Square(float a) {
	width = height = a;
}

void Square::Input(istream& inDevice) {
	inDevice >> width;
	height = width;
}
