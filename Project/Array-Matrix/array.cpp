#include <iostream>
#include <vector>
using namespace std;

class MyIntArray {
private:
	vector<int> Data;
public:
	int size() { return Data.size(); };
	void resize(int m) { Data.resize(m); };
	MyIntArray (const initializer_list<int>& L)
		:Data{L}
	{};

	int& operator[] (int i) { return Data.at(i); };
	friend ostream& operator << (ostream& out, const MyIntArray& a);
};

ostream& operator << (ostream& out, const MyIntArray& a) {
	for (auto& x: a.Data) {
		out << x << " ";
	}
	return out;
}

int main() {
	MyIntArray b {31, 37, 41, 43, 47};
	cout << "b: " << b << endl;
	b = {1, 2, 3, 4, 5, 6, 7, 8};
	cout << "new b: " << b << endl;
	return 0;
}