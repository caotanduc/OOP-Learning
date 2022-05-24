#include "Ellipse.h"

Ellipse::Ellipse(float a, float b) {
	Ra = a;
	Rb = b;
	classNameStr = (char*)"Ellipse";
	addSample(this);
}


void Ellipse::Input(istream& inDev) {
	inDev >> Ra >> Rb;
}

float Ellipse::Area() {
	return PI * Ra * Rb;
}

Ellipse::Ellipse(Ellipse& other) {
	this->Ra = other.Ra;
	this->Rb = other.Rb;
}

Figure* Ellipse::Clone() {
	return new Ellipse(*this);
}
