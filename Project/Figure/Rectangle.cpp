#include "Rectangle.h"

Rectangle::Rectangle(float w, float h) {
	width = w;
	height = h;
	classNameStr = (char*)"Rectangle";
	addSample(this);
}

void Rectangle::Input(istream& inDevice) {
	inDevice >> width >> height;
}

float Rectangle::Area() {
	return width * height;
}

Rectangle::Rectangle(Rectangle& other) {
	this->width = other.width;
	this->height = other.height;
}

Figure* Rectangle::Clone() {
	return new Rectangle(*this);
}
