#include <iostream>
#include <vector>
#include <stdarg.h>
using namespace std;

auto FindMax(initializer_list<auto> L) {
	auto largest = *(L.begin());
	for (auto & obj: L) {
		if (largest < obj) {
			largest = obj;
		}
	}
	return largest;
}

class PhanSo {
private:
	int tu;
	int mau;
public:
	PhanSo (int t = 0, int m = 1)
		: tu(t), mau(m) 
	{}

	const PhanSo operator+(const PhanSo& a) const {
		PhanSo temp;
		temp.tu = tu * a.mau + mau * a.tu;
		temp.mau = mau * a.mau;
		return temp;
	}
	const bool operator<(const PhanSo& a) const {
		PhanSo temp(-a.tu, a.mau);
		temp = *this + temp;
		return (temp.tu * temp.mau < 0);
	}
	friend ostream& operator<<(ostream& out, const PhanSo& a);
};

ostream& operator<<(ostream& out, const PhanSo& a) {
	if (a.mau == 0) out << "{inf.}";
	else if (a.mau == 1 || a.tu == 0) out << a.tu;
	else out << a.tu << "/" << a.mau;
	return out;
}

int main() {
	PhanSo ps = FindMax({ PhanSo(2, 3), PhanSo(1, 2), PhanSo(5, 11) });
	cout << ps << endl;
	cin.get();
	return 0;
}
