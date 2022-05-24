#include "ProgramFrame.h"
#include <vector>

template <class T>
istream& operator >> (istream& inDev, vector<T>& a) {
	int n;
	inDev >> n;
	if (n > 0) {
		a.resize(n);
		for (int i = 0; i < n; i++) 
			cin >> a[i];
	}
	return inDev;
}

template <class T>
ostream& operator << (ostream& outDev, vector<T>& a) {
	for (int i = 0; i < (int)a.size(); i++) {
		outDev << a[i] << " ";
	}
	return outDev;
}


class SortAlgTry : public ProgramFrame {
	vector<float> a;
	int n;
public:
	SortAlgTry() {};
	void Input(istream& inDevice) {
		inDevice >> n;
		if (n <= 0)
			return;
		a.resize(n);
		for (int i = 0; i < n; i++) 
			inDevice >> a[i];
	}
	void Output(ostream& outDevice) {
		outDevice << "Result after sorting: ";
		for (int i = 0; i < n; i++) 
			outDevice << a[i] << " ";
		outDevice << endl;
	}
	bool ValidData() {
		return (n > 0);
	}

	void StartMessage(ostream& outDevice) {
		outDevice << "Enter n, a[0], a[1], ..., a[n - 1]: ";
	}

	void Processing() {
		int m = a.size() - 1;
		for (int i = 0; i < m; i++) {
			int idMin = i;
			for (int j = i + 1; j <= m; j++) {
				if (a[j] < a[idMin])
					idMin = j;
			}
			std::swap(a[idMin], a[i]);
		}
	}
};

template <class T>
class ArrayAlgorithm {
public:
	virtual void Processing(vector<T>& a) = 0;
};

template <class T>
class AlgorithmTest : public ProgramFrame {
	ArrayAlgorithm<T>* mAlg;
	vector<T> Data;
public:
	AlgorithmTest(ArrayAlgorithm<T>* pAlg) {
		mAlg = pAlg;
	}
	
	void Input(istream& inDev) {
		inDev >> Data;
	}

	void Output(ostream& outDev) {
		outDev << Data;
	}

	bool ValidData() {
		return (Data.size() > 0);
	}

	void StartMessage(ostream& outDev) {
		outDev << "Enter n, then a[0], a[1], ..., a[n-1]: ";
	}

	void Processing() {
		if (mAlg != NULL) {
			mAlg->Processing(Data);
		}
	}
};

template <class T>
class SelectionSort : public ArrayAlgorithm<T> {
public:
	virtual void Processing(vector<T> &a) {
		int m = (int)a.size() - 1;
		for (int i = 0; i < m; i++) {
			int idMin = i;
			for (int j = i + 1; j <= m; j++) {
				if (a[j] < a[idMin])
					idMin = j;
			}
			std::swap(a[i], a[idMin]);
		}
	}
};


#include <algorithm>
template <class T>
class ArrayReverse : public ArrayAlgorithm<T> {
public:
	virtual void Processing(vector<T>& a) {
		reverse(a.begin(), a.end());
	}
};

template <class T>
class STL_Sort : public ArrayAlgorithm<T> {
public:
	virtual void Processing(vector<T>& a) {
		sort(a.begin(), a.end());
	}
};


int main() {
	AlgorithmTest<double> sortTest(new ArrayReverse<double>);
	sortTest.Run(cin, cout);
	return 0;
}
