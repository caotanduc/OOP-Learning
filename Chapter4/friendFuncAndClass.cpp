class Point {
	int x, y;
public:
	Point (int x0 = 0, int y0 = 0) {
		x = x0;
		y = y0;
	}
friend class RECT;
};

#include <iostream>
using namespace std;

class Polygon {
protected:
	int nVer;
	Point* Vers;
public:
	Polygon (int n = 0) {
		Vers = NULL;
		nVer = 0;
		if (n > 0) {
			nVer = n;
			Vers = new Point[nVer];
		}
	}

	int nVertice() {
		return nVer;
	}

	virtual ~Polygon() {
		if (Vers != NULL) {
			delete[] Vers;
			Vers = NULL;
			nVer = 0;
		}
	}
};


class RECT : public Polygon {
	Point P, Q;
	char* Buffer;
public:
	Point Center();
	RECT (Point A, Point B);
	virtual ~RECT();
};


Point RECT::Center() {
	Point M;
	M.x = ( P.x + Q.x ) / 2;
	M.y = ( P.y + Q.y ) / 2;
	return M;
}

RECT::RECT(Point A, Point B) {
	nVer = 4;
	P = A, Q = B;
	int dx = P.x - Q.x;
	int dy = P.y - Q.y;
	long BufferSize = dx * (long)dy;
	if (BufferSize < 0) {
		BufferSize = -BufferSize;
	}

	Buffer = new char[BufferSize];
}

RECT::~RECT() {
	if (Buffer != NULL) {
		delete[] Buffer;
		Buffer = NULL;
	}
}


int main() {
	Polygon* pq = new RECT( Point(4, 5), Point(-3, 11) );
	cout << pq->nVertice() << endl;
	delete pq;
	return 0;
}
