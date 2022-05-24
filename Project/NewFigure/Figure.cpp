#include "Figure.h"
vector<Figure*> Figure::sampleObjects;

void Figure::addSample(Figure* pFig) {
	if (pFig == NULL)
		return;

	int pos = sampleObjects.size();
	while (--pos >= 0) {
		Figure* Obj = sampleObjects[pos];
		if (strcmp(pFig->className() , Obj->className()) == 0)
			break;
	}
	if (pos < 0) 
		sampleObjects.push_back(pFig);
}
