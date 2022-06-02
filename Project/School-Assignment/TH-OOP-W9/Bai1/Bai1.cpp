#include "Bai1.h"

template <typename T>
cvector<T>::cvector() {
	ptr = NULL;
	sz = 0;
	capacity = 0;
}


template <typename T>
cvector<T>::cvector(int s) {
	sz = capacity = s;
	ptr = new T[sz]();
}

template <typename T>
cvector<T>::~cvector() {
	if (ptr != NULL) {
		delete[] ptr;
		ptr = NULL;
	}
	sz = 0;
	capacity = 0;
}

template <typename T>
cvector<T>::cvector(const cvector<T>& v) {
	sz = v.sz;
	capacity = v.capacity;
	ptr = new T[capacity]();
	for (int i = 0; i < sz; i++) {
		ptr[i] = v.ptr[i];
	}
}

template <typename T>
T& cvector<T>::operator[](int n) const {
	assert(ptr != NULL && n < capacity);
	return ptr[n];
}

template <typename T>
int cvector<T>::size() const {
	return sz;
}

template <typename T>
int cvector<T>::getCapacity() const {
	return capacity;
}

template <typename T>
void cvector<T>::reserve(int newalloc) {
	if (newalloc <= capacity)
		return;
	T* temp = ptr;
	capacity = newalloc;
	ptr = new T[capacity]();
	if (temp) {
		for (int i = 0; i < sz; i++) {
			ptr[i] = temp[i];
		}
		delete[] temp;
		temp = NULL;
	}
}

template <typename T>
void cvector<T>::push_back(const T& elem) {
	if (sz + 1 > capacity) {
		reserve(capacity + 1);
	}
	ptr[sz++] = elem;
}


template <typename T>
void cvector<T>::print() const {
	if (ptr == NULL) {
		cout << "there's no one at all!" << endl;
	}

	for (int i = 0; i < sz; i++) {
		cout << ptr[i] << " ";
	}

	cout << endl;
}

template <typename T>
void cvector<T>::resize(int newsize) {
	if (newsize == capacity) {
		sz = capacity;
		return;
	}
	if (newsize <= 0) {
		if (ptr != NULL) {
			delete[] ptr;
			ptr = NULL;
		}
		sz = 0;
		capacity = 0;
		return;
	}

	if (newsize > capacity) {
		reserve(newsize);
	}
	sz = newsize;
}

template <typename T>
cvector<T>& cvector<T>::operator=(const cvector<T>& v) {
	if (this == &v)
		return *this;

	if (ptr != NULL) {
		delete[] ptr;
		ptr = NULL;
	}

	sz = v.sz;
	capacity = v.capacity;
	ptr = new T[capacity]();
	for (int i = 0; i < sz; i++) {
		ptr[i] = v.ptr[i];
	}

	return *this;
}


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
	cout << "Nhap toa do tam cua hinh tron C(x, y):" << endl;
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
	cout << "Nhap goc trai X(x, y)" << endl;
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
	Children = NULL;
}

ComplexShape::ComplexShape(int sz, cvector<Shape*> children) {
	Children.resize(sz);
	for (int i = 0; i < sz; i++) {
		Children[i] = children[i]->Clone();
	}
}

ComplexShape::ComplexShape(const ComplexShape& cs) {
	Children.resize(cs.Children.size());
	for (int i = 0; i < Children.size(); i++) {
		Children[i] = cs.Children[i]->Clone();
	}
}

ComplexShape::~ComplexShape() {
	if (Children.size() != 0) {
		for (int i = 0; i < Children.size(); i++) {
			delete Children[i];
		}
	}
}

bool ComplexShape::IsSelected(Point p) {
	for (int i = 0; i < Children.size(); i++) {
		if (Children[i]->IsSelected(p) == true)
			return true;
	}
	return false;
}


Shape* ComplexShape::Clone() {
	ComplexShape* p = new ComplexShape;
	p->Children.resize(Children.size());
	for (int i = 0; i < Children.size(); i++) {
		p->Children[i] = Children[i]->Clone();
	}
	return p;
}



void ComplexShape::input() {
	if (Children.size() != 0) {
		for (int i = 0; i < Children.size(); i++) {
			if (Children[i] != NULL) {
				delete Children[i];
				Children[i] = NULL;
			}
		}

	}

	int sz;
	cout << "Nhap so luong hinh trong complexshape: ";
	cin >> sz;

	cout << "Nhap thong tin hinh: " << endl;
	Children.resize(sz);

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
	cout << "So luong hinh trong complexshape: " << Children.size() << endl;
	cout << "Cac hinh con: " << endl;
	for (int i = 0; i < Children.size(); i++) {
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
	//{
	//	int n = 3;
	//	vector<Shape*> cps(n);
	//	cps[0] = new Circle(3, 3, 3);
	//	cps[1] = new Circle(1, 2, 3);
	//	cps[2] = new Rectangle(1, 2, 3, 4);

	//	vector<Shape*> shapes(n);
	//	shapes[0] = new ComplexShape(n, cps);
	//	shapes[1] = new Circle(1, 3.2, 3.3);
	//	shapes[2] = new Rectangle(1, 2, 3, 4);

	//	countNumberOfShape();
	//	cout << endl;

	//	for (int i = 0; i < n; i++) {
	//		cps[i]->print();
	//	}

	//	cout << "shapes" << endl;
	//	for (int i = 0; i < n; i++) {
	//		shapes[i]->print();
	//	}

	//	for (int i = 0; i < n; i++) {
	//		delete cps[i];
	//		cps[i] = NULL;
	//	}

	//	for (int i = 0; i < n; i++) {
	//		delete shapes[i];
	//		shapes[i] = NULL;
	//	}
	//}

	//cout << endl;
	//countNumberOfShape();
	ComplexShape s;
	s.input();
	s.print();
	return 0;
}