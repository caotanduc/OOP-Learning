#include "NumberString.h"


int number_len(int n) {
	int len = 0;
	for (int i = n; i > 0; i /= 10) {
		len += 1;
	}
	return len;
}

NumberString::NumberString() {
	m_Number = 0;
}

NumberString::NumberString(const int& number) {
	m_Number = number;
	if (number_len(m_Number) > MAX_SIZE)
		throw invalid_argument("Number String is out of len");
}


NumberString::NumberString(const NumberString& num) {
	m_Number = num.m_Number;
	if (number_len(m_Number) > MAX_SIZE)
		throw invalid_argument("Number String is out of len");
}


NumberString& NumberString::operator=(const NumberString& num) {
	if (this == &num) {
		return *this;
	}

	m_Number = num.m_Number;
	if (number_len(m_Number) > MAX_SIZE)
		throw invalid_argument("Number String is out of len");
	return *this;
}

bool NumberString::operator==(const NumberString& num) const {
	return m_Number == num.m_Number;
}


bool NumberString::operator>(const NumberString& num) const {
	return m_Number > num.m_Number;
}


bool NumberString::operator<(const NumberString& num) const {
	return m_Number < num.m_Number;
}


bool NumberString::operator!=(const NumberString& num) const {
	return (*this == num) == false;
}

bool NumberString::operator>=(const NumberString& num) const {
	return (*this < num) == false;
}

bool NumberString::operator<=(const NumberString& num) const {
	return (*this > num) == false;
}

istream& operator>>(istream& in, NumberString& num) {
	int temp_number;
	in >> temp_number;
	if (number_len(temp_number) > num.MAX_SIZE) {
		throw invalid_argument("Number String is out of len");
	}
	num.m_Number = temp_number;
	return in;
}

ostream& operator<<(ostream& out, const NumberString& num) {
	if (number_len(num.m_Number) > num.MAX_SIZE) {
		throw invalid_argument("Number String is out of len");
	}
	out << num.m_Number;
	return out;
}
