#ifndef STRING_H
#define STRING_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

class String {
private:
	char* mBuffer;
	size_t mSize;
public:
	String();
	String(const char*);
	String(const long long);
	String(const String&);
	~String();

	String& operator=(const String&);
	String& operator+=(const String&);
	char& operator[](int) const;
	void push_back(const char);

	bool operator<(const String&);
	bool operator>(const String&);
	bool operator==(const String&);
	bool operator>=(const String&);
	bool operator<=(const String&);
	bool operator!=(const String&);

	int size() const;

	friend String operator+(String, const String&);
	friend std::ostream& operator<<(std::ostream&, const String&);
	friend std::istream& operator>>(std::istream&, String&);
};

#endif