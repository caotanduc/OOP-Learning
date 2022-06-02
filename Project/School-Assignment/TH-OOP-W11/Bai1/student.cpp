#include "student.h"
#include <vector>

Student::Student() {
	stdId = 0;
	stdGpa = 0;
	stdName[0] = '\0';
}

Student::Student(int id, const string& name, double gpa) {
	stdId = id;
	stdGpa = gpa;
	strcpy(stdName, name.c_str());
	stdName[name.length()] = '\0';
}

Student::~Student() {}

int Student::getId() const {
	return stdId;
}

string Student::getName() const {
	return string(stdName);
}

double Student::getGpa() const {
	return stdGpa;
}

void print(const Student& s) {
	cout << s.getId()
		<< "\t" << s.getName()
		<< "\t" << s.getGpa() << endl;
}

void ghiFile(string file_name, const vector<Student>& v) {
	ofstream fout(file_name, ios::app | ios::binary);
	if (!fout)
		return;
	for (const auto& vi : v) {
		fout.write((char*)&vi, sizeof(vi));
	}
	fout.close();
}

void docFile(string file_name, vector<Student>& v) {
	ifstream fin(file_name, ios::binary);
	if (!fin)
		return;
	Student s;
	while (!fin.eof()) {
		fin.read((char*)&s, sizeof(s));
		if (fin.eof())
			break;
		v.push_back(s);
	}
	fin.close();
}

// test
int main() {
	string file_name = "input.dat";
	// ghi vao file
	vector<Student> v;
	v.push_back(Student(1, "Cao", 8));
	v.push_back(Student(2, "Tan", 9));
	v.push_back(Student(3, "Duc", 10));
	ghiFile(file_name, v);

	// 
	vector<Student> vv;
	docFile(file_name, vv);

	for (auto& vi : vv)
		print(vi);
	return 0;
}