#include "Figure.h"
vector<Figure*> Figure::sampleObjects;

void Figure::addSample(Figure* pFig) {
	if (pFig == NULL)
		return;
	int pos = sampleObjects.size();
	while (--pos) {
		Figure* Obj = sampleObjects[pos];
		if (strcmp(pFig->className(), Obj->className()) == 0)
			break;
	}
	if (pos < 0) {
		sampleObjects.push_back(pFig);
	}
}

Figure* Figure::createObject(char* clsName) {
	if (clsName == NULL)
		return NULL;
	int pos = sampleObjects.size();
	while (--pos >= 0) {
		Figure* Obj = sampleObjects[pos];
		if (Obj == NULL) 
			continue;
		if (strcmp(clsName, Obj->className()) == 0) 
			break;
	}
	if (pos >= 0)
		return sampleObjects[pos]->Clone();
	else
		return NULL;
}
