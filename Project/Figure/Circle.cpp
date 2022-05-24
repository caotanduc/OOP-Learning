#include "Circle.h"

Circle::Circle(float r): Ellipse(r, r) {
	classNameStr = (char*)"Circle";
	addSample(this);
}

void Circle::Input(istream& inDev) {
	inDev >> Ra;
	Rb = Ra;
}

Figure* Circle::Clone() {
	return new Circle(*this);
}
