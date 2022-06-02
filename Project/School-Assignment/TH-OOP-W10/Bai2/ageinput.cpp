/******************************************************
* File hien thuc AgeInput, ageinput.cpp
*******************************************************/
#ifndef AGEINPUT_CPP
#define AGEINPUT_CPP
#include <iostream>
#include <exception>
#include <string>
using namespace std;
#include "myexception.h"
class AgeInput : public myException {
private:
	string DEFAULT_MESSAGE = "Your age: ";
	int DEFAULT_LOWER_BOUND = 0;
	int DEFAULT_UPPER_BOUND = 99;
	int lowerBound;
	int upperBound;
public:
	AgeInput() {
		lowerBound = DEFAULT_LOWER_BOUND;
		upperBound = DEFAULT_UPPER_BOUND;
	}
	AgeInput(int low, int high) {
		lowerBound = low;
		upperBound = high;
	}
	int getAge() {
		return getAge(DEFAULT_MESSAGE);
	}
	int getAge(string promt) {
		int age = 0;
		while (true) {
			cout << promt;
			try {
				cin >> age;
				if (age < lowerBound || age > upperBound) {
					throw myException("Input out of bound! ");
				}
				return age;
			}
			catch (myException& ex) {
				cout << ex.getMessage() << endl;
			}
		}
	}
};
#endif