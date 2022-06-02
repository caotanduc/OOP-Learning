#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <cstring>
using namespace std;

class NV {
private:
	string maso;
	string hoten;
	double luong;
public:
	NV() {
		maso = "";
		hoten = "";
		luong = 0;
	};

	NV(string ms, string ht, double l) {
		maso = ms;
		hoten = ht;
		luong = l;
	}

	void print() {
		cout << maso << "\t" << hoten << "\t" << luong << endl;
	}
};


void ghifile(ofstream& fout, const NV& nv) {
}


void ghiMangFile(string fn, const vector<NV>& l) {
	ofstream fout(fn, ios::app | ios::binary);
	if (!fout)
		return;

	for (const NV& nv : l) {
		fout.write((char*)&nv, sizeof(nv));
	}

	fout.close();
}

void docFile(string fn, vector<NV>& l) {
	ifstream fin(fn, ios::binary);
	if (!fin)
		return;

	NV nv;
	while (!fin.eof()) {
		fin.read((char*)&nv, sizeof(nv));
		if (fin.eof())
			break;
		l.push_back(nv);
	}
	fin.close();
	for (auto& li : l) {
		li.print();
	}

	exit(0);
}


int main() {
	cout << fixed;
	cout << setprecision(3);
	vector<NV> l;
	//l.push_back(NV("1234", "Cao Tan Duc", 1000000));
	//l.push_back(NV("1235", "Tan Duc Cao", 2000000));
	//l.push_back(NV("1236", "Duc Cao Tan", 3000000));
	//l.push_back(NV("1237", "Duc Tan Cao", 4000000));

	//ghiMangFile("data.dat", l); 


	docFile("data.dat", l);
	for (auto& li : l) {
		li.print();
	}
	return 0;
}
