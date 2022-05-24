#ifndef _FIGURE_H
#define _FIGURE_H

#include <iostream>
#include <vector>
using namespace std;

class Figure {
private:
	static vector<Figure*> sampleObjects;
protected:
	char* classNameStr;
	static void addSample(Figure* pFig);
public:
	Figure() {};
	virtual void Input(istream& inDev) = 0;
	virtual float Area() = 0;
	virtual char* className() = 0;
	virtual Figure* Clone() = 0;
	char* getClass() {
		return classNameStr;
	}
	static Figure* createObject(char* clsName);
};

#endif
