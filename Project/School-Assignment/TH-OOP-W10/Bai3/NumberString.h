#ifndef NUMBER_STRING_H
#define NUMBER_STRING_H

#include <iostream>
#include <stdexcept>
using namespace std;

class NumberString {
private:
	int m_Number;
	int MAX_SIZE = 5;
public:
	NumberString();
	NumberString(const int&);
	NumberString(const NumberString&);

	NumberString& operator=(const NumberString&);

	bool operator==(const NumberString&) const;
	bool operator<(const NumberString&) const;
	bool operator>(const NumberString&) const;
	bool operator!=(const NumberString&) const;
	bool operator<=(const NumberString&) const;
	bool operator>=(const NumberString&) const;

	friend istream& operator>>(istream&, NumberString&);
	friend ostream& operator<<(ostream&, const NumberString&);
};

#endif // NUMBER_STRING_H
