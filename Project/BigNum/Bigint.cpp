#include "Bigint.h"


Bigint::Bigint() {
	mSize = 1;
	mSign = 1;
	mNumber = "0";
}

Bigint::Bigint(const char* number) {
	mSize = strlen(number);
	mSign = (number[0] == '-' ? -1: 1);
	if (mSign == -1) {
		mNumber = string(number + 1);
		mSize -= 1;
	}
	else {
		mNumber = string(number);
	}
}


Bigint& Bigint::operator+=(const Bigint& num) {
	string num1 = mNumber, num2 = num.mNumber;
	//reverse(num1.begin(), num1.end());
	//reverse(num2.begin(), num2.end());
		
	mNumber.clear();
	if (mSign * num.mSign == 1) {
		int n1 = mSize, n2 = num.mSize;
		int k1 = 0, k2 = 0, gain = 0;

		while (n1 > 0 || n2 > 0|| gain) {
			int sum = 0;
			if (n1 > 0) {
				sum += (num1[n1 - 1] - '0');
			}
			
			if (n2 > 0) {
				sum += (num2[n2 - 1] - '0');
			}

			sum += gain;
			gain = sum / 10;

			mNumber.push_back((sum % 10) + '0');
			n1--, n2--;
		}

		reverse(mNumber.begin(), mNumber.end());
		mSize = (int)mNumber.size();
	}
	else {

	}
	return (*this);
}

Bigint& Bigint::operator-=(const Bigint& num) {
	string num1 = mNumber, num2 = num.mNumber;
	if (mSign * num.mSign == -1) {
		
	}
	return (*this);
}


bool Bigint::operator>(const Bigint& num) {
	if (mSign == 1 && num.mSign == -1)
		return true;
	if (mSign == -1 && num.mSign == 1)
		return false;

	if (mSign == 1) {
		if (mSize > num.mSize)
			return true;
		return false;
	}
	
	else {
		if (mSize > num.mSize)
			return false;
		return true;
	}

	int n = mSize, i = 0;
	while (i < n) {
		if (mNumber[i] > num.mNumber[i])
			return true;
		else if (mNumber[i] < num.mNumber[i++])
			break;
	}
	return false;
}

bool Bigint::operator==(const Bigint& num) {
	if (mSign * num.mSign == -1 || mSize != num.mSize)
		return false;

	int i = 0, n = mSize;
	while (i < n) {
		if (mNumber[i] != num.mNumber[i])
			return false;
	}

	return true;
}

bool Bigint::operator<(const Bigint& num) {
	return (*this > num || *this == num) == false;
}

bool Bigint::operator>=(const Bigint& num) {
	return (*this < num) == false;
}

bool Bigint::operator<=(const Bigint& num) {
	return (*this > num) == false;
}

bool Bigint::operator!=(const Bigint& num) {
	return (*this == num) == false;
}

ostream& operator<<(ostream& out, const Bigint& num) {
	if (num.mSign == -1)
		out << '-';
	out << num.mNumber;
	return out;
}

Bigint operator+(Bigint num1, const Bigint& num2) {
	num1 += num2;
	return num1;
}