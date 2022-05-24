#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> IntVector;
typedef initializer_list<int> InitializerList;

class IntArray2D {
private:
	vector<IntVector> Data;
public:
	int xSize() const { return Data.size(); };
	int ySize() const { return Data[0].size(); };
	IntVector& operator [] (int i) { return Data.at(i); };
	void resize(int m, int n) {
		if (m < 0) m = -m;
		if (n < 0) n = -n;
		Data.resize(m);
		for (auto& a: Data) {
			a.resize(n);
		}
	};
	
	IntArray2D(int m, int n) { resize(m, n); }
	IntArray2D(const initializer_list<InitializerList>& L2D) {
		for (auto& L: L2D) {
			Data.push_back(L);
		}
	};

	friend ostream& operator << (ostream& out, IntArray2D& a);
};

ostream& operator << (ostream& out, IntArray2D& a) {
	for (int i = 0; i < a.xSize(); i++) {
		for (int j = 0; j < a.ySize(); j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return out;
}


int main() {
	IntArray2D A {{1, 2, 3}, {2, 3, 4}, {2, 3, 1}};
	cout << "A:\n" << A << endl;
	IntArray2D B(2, 2), C{4, 3};
	cout << "B:\n" << B << endl;
	cout << "C:\n" << C << endl;
	return 0;
}
