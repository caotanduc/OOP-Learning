#ifndef _FIGURE_H
#define _FIGURE_H
#include <iostream>
#include <vector>
using namespace std;

class Figure {
	static vector<Figure*> sampleObjects;
protected:
	static void addSample(Figure* pFig);
public:
	static Figure* createObject(char* clsName);
	virtual char* className() = 0;
	virtual Figure* Clone() = 0;
};

#endif
