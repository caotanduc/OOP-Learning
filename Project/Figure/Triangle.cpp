#include "Triangle.h"

Triangle::Triangle(float a, float h) {
	basesize = a;
	height = h;
	classNameStr = (char*)"Triangle";
	addSample(this);
}

void Triangle::Input(istream& inDev) {
	inDev >> basesize >> height;
}

float Triangle::Area() {
	return basesize * height / 2;
}


Triangle::Triangle(Triangle& other) {
	this->basesize = other.basesize;
	this->height = other.height;
}

Figure* Triangle::Clone() {
	return new Triangle(*this);
}
