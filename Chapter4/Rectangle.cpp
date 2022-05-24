#include "Rectangle.h"

Rectangle::Rectangle(float w, float h) {
	width = w;
	height = h;
}

void Rectangle::Input(istream& inDevice) {
	inDevice >> width >> height;
}

float Rectangle::Area() {
	return width * height;
}
