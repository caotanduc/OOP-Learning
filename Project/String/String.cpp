#include "String.h"


String::String() {
	mBuffer = NULL;
	mSize = 0;
}

String::~String() {
	if (mBuffer != NULL) {
		delete[] mBuffer;
		mBuffer = NULL;
	}
	mSize = 0;
}

String::String(const char* arr) {
	mSize = strlen(arr);
	mBuffer = new char[mSize + 1];
	strcpy(mBuffer, arr);
	mBuffer[mSize] = '\0';
}

String::String(const long long k) {
	int n = 0;
	long long temp = k;
	while (temp > 0) {
		n += 1;
		temp /= 10;
	}

	mSize = n;
	mBuffer = new char[n + 1];
	mBuffer[n] = '\0';

	temp = k;
	while (n--) {
		mBuffer[n] = (temp % 10) + '0';
		temp /= 10;
	}
}

String::String(const String& str) {
	mSize = str.mSize;
	mBuffer = new char[mSize + 1];
	strcpy(mBuffer, str.mBuffer);
	mBuffer[mSize] = '\0';
}

String& String::operator=(const String& str) {
	if (this == &str)
		return (*this);

	if (mBuffer != NULL) {
		delete[] mBuffer;
		mBuffer = NULL;
	}

	mSize = str.mSize;
	mBuffer = new char[mSize + 1];
	strcpy(mBuffer, str.mBuffer);
	mBuffer[mSize] = '\0';
	return (*this);
}
	
String& String::operator+=(const String& str) {
	int n = mSize;
	char* tempStr = new char[n + 1];
	strcpy(tempStr, mBuffer);
	tempStr[n] = '\0';

	mSize += str.mSize;
	delete[] mBuffer;
	mBuffer = new char[mSize + 1];
	strcpy(mBuffer, tempStr);
	strcpy(mBuffer + n, str.mBuffer);
	mBuffer[mSize] = '\0';

	delete[] tempStr;
	tempStr = NULL;
	return (*this);
}

char& String::operator[](int k) const {
	return mBuffer[k];
}

int String::size() const {
	return mSize;
}

bool String::operator>(const String& str) {
	return strcmp(mBuffer, str.mBuffer) == 1;
}

bool String::operator<(const String& str) {
	return strcmp(mBuffer, str.mBuffer) == -1;
}

bool String::operator==(const String& str) {
	return strcmp(mBuffer, str.mBuffer) == 0;
}

bool String::operator>=(const String& str) {
	return strcmp(mBuffer, str.mBuffer) != -1;
}

bool String::operator<=(const String& str) {
	return strcmp(mBuffer, str.mBuffer) != 1;
}

bool String::operator!=(const String& str) {
	return strcmp(mBuffer, str.mBuffer) != 0;
}



// friend
String operator+(String s1, const String& s2) {
	String newStr;
	newStr.mSize = s1.mSize + s2.mSize;
	newStr.mBuffer = new char[newStr.mSize + 1];
	newStr.mBuffer[newStr.mSize] = '\0';

	strcpy(newStr.mBuffer, s1.mBuffer);
	strcpy(newStr.mBuffer + s1.mSize, s2.mBuffer);
	return newStr;
}

std::ostream& operator<<(std::ostream& out, const String& str) {
	if (str.mBuffer == NULL) {
		out << "Empty String!" << std::endl;
	}
	else
		out << str.mBuffer;
	return out;
}

std::istream& operator>>(std::istream& in, String& str) {
	char temp[10000];
	std::cin.getline(temp, 9999);
	str = temp;
	return in;
}