#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <stdexcept>
using namespace std;

class Date {
private:
	int m_Day;
	int m_Month;
	int m_Year;
public:
	Date();
	Date(int, int, int);
	Date(const Date&);

	Date& operator=(const Date&);

	bool operator==(const Date&) const;
	bool operator!=(const Date&) const;

	int dateDiff(const Date&) const ;
	friend istream& operator>>(istream&, Date&);
	friend ostream& operator<<(ostream&, const Date&);
};

#endif // DATE_H
