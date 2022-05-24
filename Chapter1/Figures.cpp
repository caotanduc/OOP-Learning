#include "Figures.h"

void Point2D::Set(double Xo, double Yo) {
    X = Xo;
    Y = Yo;
}

void Point2D::Move(double dX, double dY) {
    X += dX;
    Y += dY;
}


void Point2D::Scale(double sX, double sY) {
    X *= sX;
    Y *= sY;
}

const double PI = 3.14159;
void Circle::Set(double Xo, double Yo, double r) {
    Center.Set(Xo, Yo);
    if (r < 0) r = 0;
    Radius = r;
}

void Circle::Set(double r) {
    if (r >= 0)
        Radius = r;
}

void Circle::Move(double dX, double dY) {
    Center.Move(dX, dY);
}

double Circle::Area() {
    return PI * Radius * Radius;
}

double Circle::Perimeter() {
    return 2 * PI * Radius;
} 
