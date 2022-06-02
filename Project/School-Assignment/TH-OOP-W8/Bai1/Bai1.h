/*****************************************************************************
* Khai bao cac lop cua chuong trinh Hien thuc clone
*****************************************************************************/
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
// Cau truc Diem
struct Point {
	double X;
	double Y;
};

#ifndef SHAPE_H
#define SHAPE_H
// Lop doi tuong hinh ve tong quat 'Shape'
class Shape {
public:
	// Constructors, Example: Shape(); ~Shape();
	virtual ~Shape() {};
	/* Se cai dat lai trong tung lop dan xuat */
	virtual Shape* Clone() = 0;
	virtual bool IsSelected(Point p) = 0;
	// other methods, Example: input(); print();
	virtual void input() = 0;
	virtual void print() = 0;
};

#endif


#ifndef CIRCLE_H
#define CIRCLE_H
// Lớp Circle
class Circle : public Shape {
public:
	static int count;
protected:
	Point C; //toạ độ tâm
	double R; //độ dài bán kính
public:
	// Constructors
	Circle(double x = 0, double y = 0, double r = 0);
	Circle(const Circle&);
	~Circle();

	// Overriding base class’s IsSelected method
	bool IsSelected(Point);
	// Overriding base class’s Clone method
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
	int sz; //Number of shapes
	Shape** Children; //Array of <Shape*>
public:
	// Constructors
	ComplexShape();
	ComplexShape(int sz, Shape**);
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
