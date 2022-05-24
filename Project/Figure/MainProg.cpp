#include "Figure.h"
#include "Rectangle.h"
#include "Square.h"
#include "Ellipse.h"
#include "Circle.h"
#include "Triangle.h"

Figure* figMaxArea(Figure* figs[], int nFig) {
	Figure* figMax = NULL;
	if (nFig > 0) {
		figMax = figs[0];
		for (int i = 1; i < nFig; i++) {
			if (figMax->Area() < figs[i]->Area()) {
				figMax = figs[i];
			}
		}
	}
	return figMax;
}

Figure* Cloning(Figure* pFig) {
	if (pFig == NULL) 
		return NULL;
	return pFig->Clone();
}


int main() {
	Figure* figs[] = {
		new Rectangle(9.3F, 9.7F),
		new Circle(4.5F),
		new Ellipse(4.2F, 4.7F),
		new Square(9.5F),
		new Triangle(10.7F, 6.4F),
		new Ellipse(3.7F, 7.8F)
	};

	/* int nFig = sizeof(figs) / sizeof(Figure); */
	int nFig = 6;
	/* Figure* aFig = figMaxArea(figs, nFig); */
	/* if (aFig != NULL) { */
	/* 	cout << aFig->Area() << endl; */
	/* } */
	for (int i = 0; i < nFig; i++) {
		cout << figs[i]->className() << ", area: ";
		cout << figs[i]->Area() << endl;
	}
	return 0;
}
