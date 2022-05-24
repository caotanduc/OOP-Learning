#include "Rectangle.h"
#include "Square.h"

int main() {
	Rectangle* pRec;
	Rectangle Rec;
	Square Sq;


	cout << "Rectangle's sizes (width and height): ";
	pRec = &Rec;
	pRec->Input(cin);
	cout << "Rectangle's area = " << pRec->Area() << endl;


	cout << "Square's size: ";
	pRec = &Sq;
	pRec->Input(cin);
	cout << "Square's area = " << pRec->Area() << endl;
	return 0;
}
