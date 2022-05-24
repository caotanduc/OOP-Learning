#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Bigint {
private:
	string mNumber;
	int mSign;
	int mSize;
public:
	Bigint();
	Bigint(const char*);
	
	Bigint& operator+=(const Bigint&);
	Bigint& operator-=(const Bigint&);
	bool operator>(const Bigint&);
	bool operator<(const Bigint&);
	bool operator==(const Bigint&);
	bool operator>=(const Bigint&);
	bool operator<=(const Bigint&);
	bool operator!=(const Bigint&):

	friend Bigint operator+(Bigint, const Bigint&);
	//friend Bigint operator-(const Bigint&, const Bigint&);
	//friend Bigint operator*(const Bigint&, const Bigint&);
	friend ostream& operator<<(ostream&, const Bigint&);
};

#endif