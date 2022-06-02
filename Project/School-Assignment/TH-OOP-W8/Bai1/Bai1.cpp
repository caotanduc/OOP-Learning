#include "Bai1.h"


Circle::Circle(double x, double y, double r) 
	:C{ x, y }, R(r) 
{
	count += 1;
}

Circle::Circle(const Circle& c)
	: C(c.C), R(c.R) 
{
	count += 1;
}


Circle::~Circle() {
	count -= 1;
}

bool Circle::IsSelected(Point p) {
	double d = sqrt(C.X * p.X + C.Y * p.Y);
	return d <= R;
}


void Circle::input() {
	cout << "Nhap toa do tam cua hinh tron C(x, y):";
	cout << "\tx = ";
	cin >> C.X;
	cout << "\ty = ";
	cin >> C.Y;
	cout << "Nhap ban kinh hinh tron: ";
	cin >> R;
}

void Circle::print() {
	cout << "Hinh tron tam (" << C.X << ", " << C.Y << ") ban kinh " << R << endl;
}

Rectangle::Rectangle(double x, double y, double w, double h)
	:X{ x, y }, W(w), H(h) 
{
	count += 1;
}

Rectangle::Rectangle(const Rectangle& r)
	: X(r.X), W(r.W), H(r.H) 
{
	count += 1;
}


Rectangle::~Rectangle() {
	count -= 1;
}

Shape* Rectangle::Clone() {
	Rectangle* p = new Rectangle;
	if (p == NULL) return NULL;
	p->X = X;
	p->W = W;
	p->H = H;
	return p;
}


void Rectangle::input() {
	cout << "Nhap goc trai X(x, y)";
	cout << "\tx = ";
	cin >> X.X;
	cout << "\ty = ";
	cin >> X.Y;
	cout << "Nhap chieu dai: ";
	cin >> H;
	cout << "Nhap chieu rong: ";
	cin >> W;
}

void Rectangle::print() {
	cout << "Hinh chu nhat co goc trai X(" << X.X << ", " << X.Y << ") co dai " << H << " rong " << W << endl;
}


ComplexShape::ComplexShape() {
	sz = 0;
	Children = NULL;
}

ComplexShape::ComplexShape(int sz, Shape** children) {
	this->sz = sz;
	Children = new Shape* [sz];
	for (int i = 0; i < sz; i++) {
		Children[i] = children[i]->Clone();
	}
}

ComplexShape::ComplexShape(const ComplexShape& cs) {
	sz = cs.sz;
	Children = new Shape* [sz];
	for (int i = 0; i < sz; i++) {
		Children[i] = cs.Children[i]->Clone();
	}
}

ComplexShape::~ComplexShape() {
	if (Children != NULL) {
		for (int i = 0; i < sz; i++) {
			if (Children[i] != NULL) {
				delete Children[i];
				Children[i] = NULL;
			}
		}

		delete[] Children;
		Children = NULL;
	}
}

bool ComplexShape::IsSelected(Point p) {
	for (int i = 0; i < sz; i++) {
		if (Children[i]->IsSelected(p) == true)
			return true;
	}
	return false;
}


Shape* ComplexShape::Clone() {
	ComplexShape* p = new ComplexShape;
	p->sz = sz;
	p->Children = new Shape*[p->sz];
	for (int i = 0; i < p->sz; i++) {
		p->Children[i] = Children[i]->Clone();
	}
	return p;
}



void ComplexShape::input() {
	if (Children != NULL) {
		for (int i = 0; i < sz; i++) {
			if (Children[i] != NULL) {
				delete Children[i];
				Children[i] = NULL;
			}
		}

		delete[] Children;
		Children = NULL;
	}

	cout << "Nhap so luong hinh trong complexshape: ";
	cin >> sz;

	cout << "Nhap thong tin hinh: " << endl;
	Children = new Shape*[sz];

	int ty = 0;
	cout << "Nhap 0: Circle, 1: Rectangle" << endl;
	for (int i = 0; i < sz; i++) {
		cout << "Nhap loai hinh: ";
		cin >> ty;
		if (ty == 0) {
			Children[i] = new Circle;
		}
		else {
			Children[i] = new Rectangle;
		}

		Children[i]->input();
	}
}

void ComplexShape::print() {
	cout << "So luong hinh trong complexshape: " << sz << endl;
	cout << "Cac hinh con: " << endl;
	for (int i = 0; i < sz; i++) {
		cout << "\t" << i << ". ";;
		Children[i]->print();
	}
	cout << endl;
}

void countNumberOfShape() {
	cout << "number of circle: " << Circle::count << endl;
	cout << "number of rectangle: " << Rectangle::count << endl;
}

// testting

int Circle::count = 0;
int Rectangle::count = 0;



int main() {
	{
		int n = 3;
		Shape** cps = new Shape * [n];
		cps[0] = new Circle(3, 3, 3);
		cps[1] = new Circle(1, 2, 3);
		cps[2] = new Rectangle(1, 2, 3, 4);

		Shape** shapes = new Shape * [n];
		shapes[0] = new ComplexShape(n, cps);
		shapes[1] = new Circle(1, 3.2, 3.3);
		shapes[2] = new Rectangle(1, 2, 3, 4);

		countNumberOfShape();
		cout << endl;

		for (int i = 0; i < n; i++) {
			cps[i]->print();
		}

		cout << "shapes" << endl;
		for (int i = 0; i < n; i++) {
			shapes[i]->print();
		}

		for (int i = 0; i < n; i++) {
			delete cps[i];
			cps[i] = NULL;
		}
		delete[] cps;
		cps = NULL;

		for (int i = 0; i < n; i++) {
			delete shapes[i];
			shapes[i] = NULL;
		}
		delete[] shapes;
		shapes = NULL;
	}

	cout << endl;
	countNumberOfShape();
	return 0;
}