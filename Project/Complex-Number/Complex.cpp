#include "Complex.h"
#include <iostream>
#include <cmath>
using namespace std;

Complex::Complex() {
    this->real = 0;
    this->imaginary = 1;
}


double Complex::getModule() const {
    return sqrt(this->real * this->real + this->imaginary * this->imaginary);
}

Complex::Complex(double a, double b) {
    this->real = a;
    this->imaginary = b;
}

const Complex Complex::operator+(const Complex& a) const {
    Complex temp; 
    temp.real = this->real + a.real;
    temp.imaginary = this->imaginary + a.imaginary;
    return temp;
}

const Complex Complex::operator-(const Complex& a) const {
    Complex temp;
    temp.real = this->real - a.real;
    temp.imaginary = this->imaginary - a.imaginary;
    return temp;
}

const Complex Complex::operator*(const Complex& a) const {
    Complex temp;
    temp.real = this->real * a.real - this->imaginary * a.imaginary;
    temp.imaginary = this->real * a.imaginary + this->imaginary * a.real;
    return temp;
}


const Complex Complex::operator/(const Complex& a) const {
    Complex temp(a.real, -a.imaginary);
    temp = *this * temp;
    double module = a.getModule() * a.getModule();
    temp.real /= module;
    temp.imaginary /= module;
    return temp;
}

bool Complex::operator==(const Complex& a) const {
    if (this->real == a.real && this->imaginary == a.imaginary)
        return true;
    return false;
}


bool Complex::operator!=(const Complex& a) const {
    if (this->real != a.real || this->imaginary != a.imaginary)
        return true;
    return false;
}

istream& operator>>(istream& in, Complex& a) {
    double r, i;
    in >> a.real >> a.imaginary;
    return in;
}


ostream& operator<<(ostream& out, const Complex& a) {
    out << a.real << " " << a.imaginary << "i";
    return out;
}
