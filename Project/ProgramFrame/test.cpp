#include <iostream>
#include <typeinfo>
#include <string>
#include <map>
using namespace std;

class RootClass {
protected:
	static map<string, RootClass*> prototypeObjects;
	static RootClass* addPrototype(RootClass* pObj) {
		if (pObj == nullptr) return nullptr;
		prototypeObjects.insert( {pObj->className(), pObj} );
		return pObj;
	};
public:
	RootClass() {};
	virtual ~RootClass() {};

	string classStrID() {
		return typeid(*this).name();
	}

	string className() {
		string s = classStrID();

		int i;
		for (i = 0; i < s.length(); i++) {
			if (s[i] < '0' || s[i] > '9') break;
		}
		return s.substr(i);
	}
	virtual RootClass* createObject() = 0;
	static RootClass* createObject(const char* clsName) {
		if (clsName == nullptr) return nullptr;
		auto obj = prototypeObjects.find(clsName);
		if (obj != prototypeObjects.end()) {
			return obj->second->createObject();
		}
		return nullptr;
	}
};

map<string, RootClass*> RootClass::prototypeObjects;

// macros
/* #define INIT_MEMBER(CLASS) \ */
/* 	virtual RootClass* createObject() {return new CLASS;} */

#define INIT_MEMBER(CLASS) static RootClass* BootObj##CLASS; \
	virtual RootClass* createObject() { return new CLASS; }

#define INIT_OBJECT(CLASS) RootClass* CLASS::BootObj##CLASS = \
								  RootClass::addPrototype(new CLASS())

class Circle : public RootClass {
	INIT_MEMBER(Circle);
	int R;
};
INIT_OBJECT(Circle);

class Rectangle : public RootClass {
	INIT_MEMBER(Rectangle);
	int Rx, Ry;
public:
	virtual int Area() final { return Rx * Ry; };
	Rectangle(int X = 0, int Y = 0): Rx(X), Ry(Y) {};
};
INIT_OBJECT(Rectangle);

class Square final : public Rectangle {
	INIT_MEMBER(Square);
public:
	Square(int D = 0): Rectangle(D, D) {};
};
INIT_OBJECT(Square);

int main(int argc, char** argv) {
	RootClass* prc = new Square;
	cout << typeid(*prc).name() << endl;
	cout << "Of Pointer to Square: " << prc->className() << endl;
	RootClass* pObj = prc->createObject();
	cout << "pObj class: " << pObj->className() << endl;
	delete prc;
	delete pObj;
	return 0;
}
