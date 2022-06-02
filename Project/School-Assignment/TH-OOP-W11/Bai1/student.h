#define _CRT_SECURE_NO_WARNINGS
#ifndef STUDEN_H
#define STUDEN_H

#include <cstring>
#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <string>
using namespace std;
class Student
{
private:
	int stdId;
	char stdName[30];
	double stdGpa;
public:
	Student(int, const string&, double);
	Student();
	~Student();
	int getId() const;
	string getName() const;
	double getGpa() const;
};

#endif