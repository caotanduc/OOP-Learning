#ifndef _COMPLEX_H
#define _COMPLEX_H


#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imaginary;
public:
    // constructor
    Complex();                                              // ( num ) = i
    Complex(double a, double b);                            // ( num ) = a + b * i

    // operator
    const Complex operator+(const Complex& a) const;
    const Complex operator-(const Complex& a) const;
    const Complex operator*(const Complex& a) const;
    const Complex operator/(const Complex& a) const;
    bool operator==(const Complex& a) const;
    bool operator!=(const Complex& a) const;

    double getModule() const;


// in & out
friend istream& operator>>(istream& in, Complex& a);
friend ostream& operator<<(ostream& out, const Complex& a);
};


#endif
