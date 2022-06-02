#include<iostream>
#include<string>
#include <cassert>
#include <cmath>
using namespace std;

struct Point {
	double X;
	double Y;
};


#ifndef CVECTOR_H
#define CVECTOR_H

template<typename T>
class cvector {
private:
	T* ptr;
	int sz;
	int capacity;
public:
	cvector();
	cvector(int s);
	~cvector();
	T& operator[](int n) const;
	int size() const;
	int getCapacity() const;
	void reserve(int newalloc);
	void push_back(const T& elem);
	void print() const;
	// other methods

	cvector(const cvector<T>&);
	void resize(int newsize);
	cvector<T>& operator=(const cvector<T>&);
};
#endif



#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
	virtual ~Shape() {};

	virtual Shape* Clone() = 0;
	virtual bool IsSelected(Point p) = 0;
	virtual void input() = 0;
	virtual void print() = 0;
};

#endif


#ifndef CIRCLE_H
#define CIRCLE_H
class Circle : public Shape {
public:
	static int count;
protected:
	Point C; //toạ độ tâm
	double R; //độ dài bán kính
public:

	Circle(double x = 0, double y = 0, double r = 0);
	Circle(const Circle&);
	~Circle();

	bool IsSelected(Point);
	Shape* Clone() {
		Circle* p = new Circle;
		if (p == NULL) return NULL;
		p->C = C;
		p->R = R;
		return p;
	}
	// Other methods,
	void input();
	void print();
};

#endif


#ifndef RECTANGLE_H
#define RECTANGLE_H
// Lớp hình chu nhat
class Rectangle : public Shape {
public:
	static int count;
protected:
	Point X; //toạ độ góc trái trên
	double W, H; //chiều rộng và chiều cao
public:
	//Constructors
	Rectangle(double x = 0, double y = 0, double w = 0, double h = 0);
	Rectangle(const Rectangle&);
	~Rectangle();

	// Overriding base class’s IsSelected method
	bool IsSelected(Point p) {
		return ((p.X >= X.X) && (p.X <= X.X + W)
			&& (p.Y >= X.Y) && (p.Y <= X.Y + H));
	}
	// Overriding base class’s Clone method
	Shape* Clone();

	// other methods
	void input();
	void print();
};

#endif

#ifndef COMPLEXSHAPE_H
#define COMPLEXSHAPE_H
// Lớp ComplexShape
class ComplexShape : public Shape {
protected:
	// Các hình vẽ thành phần: Circle, rectangle, ...
	cvector<Shape*> Children; //Array of <Shape*>
public:
	// Constructors
	ComplexShape();
	ComplexShape(int sz, cvector<Shape*>);
	ComplexShape(const ComplexShape&);
	~ComplexShape();

	// Overriding base class’s IsSelected method
	bool IsSelected(Point);
	// Overriding base class’s Clone method
	Shape* Clone();
	//other methods
	void input();
	void print();
};

#endif

