#include "Date.h"


const int MAX_VALID_YR = 9999;
const int MIN_VALID_YR = 1800;
 
bool isLeap(int year)
{
	return (((year % 4 == 0) &&
			 (year % 100 != 0)) ||
			 (year % 400 == 0));
}
 
bool isValidDate(int d, int m, int y)
{
    if (y > MAX_VALID_YR || y < MIN_VALID_YR)
		return false; 
	if (m < 1 || m > 12)
		return false;
    if (d < 1 || d > 31)
		return false;
    if (m == 2)
    {
        if (isLeap(y))
        return (d <= 29);
        else
        return (d <= 28);
    }
 
    if (m == 4 || m == 6 ||
        m == 9 || m == 11)
        return (d <= 30);
 
    return true;
}

int rdn(int d, int m, int y) { /* Rata Die day one is 0001-01-01 */
    if (m < 3)
        y--, m += 12;
    return 365*y + y/4 - y/100 + y/400 + (153*m - 457)/5 + d - 306;
}

Date::Date() {
	m_Day = m_Month = m_Year = 0;
}

Date::Date(int day, int month, int year) {
	m_Day = day;
	m_Month = month;
	m_Year = year;
	if (isValidDate(m_Day, m_Month, m_Year) == false) {
		throw invalid_argument("Invalid Date");
	}
}

Date::Date(const Date& d) {
	m_Day = d.m_Day;
	m_Month = d.m_Month;
	m_Year = d.m_Year;
	if (isValidDate(m_Day, m_Month, m_Year) == false) {
		throw invalid_argument("Invalid Date");
	}
}

Date& Date::operator=(const Date& d) {
	if (this == &d) 
		return *this;

	if (isValidDate(m_Day, m_Month, m_Year) == false) {
		throw invalid_argument("Invalid Date");
	}

	m_Day = d.m_Day;
	m_Month = d.m_Month;
	m_Year = d.m_Year;
	return *this;
}

bool Date::operator==(const Date& d) const {
	if (isValidDate(m_Day, m_Month, m_Year) == false) {
		throw invalid_argument("Invalid Date");
	}
	return (m_Day == d.m_Day) && (m_Month == d.m_Month) && (m_Year == d.m_Year);
}

bool Date::operator!=(const Date& d) const {
	if (isValidDate(m_Day, m_Month, m_Year) == false) {
		throw invalid_argument("Invalid Date");
	}
	return (*this == d) == false;
}

int Date::dateDiff(const Date& d) const {
	return rdn(m_Day, m_Month, m_Year) - rdn(d.m_Day, d.m_Month, d.m_Year);
}

istream& operator>>(istream& in, Date& d) {
	in >> d.m_Day >> d.m_Month >> d.m_Year;
	if (isValidDate(d.m_Day, d.m_Month, d.m_Year) == false) {
		throw invalid_argument("Invalid Date");
	}
	return in;
}

ostream& operator<<(ostream& out, const Date& d) {
	if (isValidDate(d.m_Day, d.m_Month, d.m_Year) == false) 
		throw invalid_argument("Invalid Date");
	out << d.m_Day << "/" << d.m_Month << "/" << d.m_Year;
	return out;
}
