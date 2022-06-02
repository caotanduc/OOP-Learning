#ifndef STRING_H
#define STRING_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdexcept>
using namespace std;


class String {
private:
	char* m_buffer;
	int m_size;
public:
	String();
	String(const int&);
	String(const char*);
	String(const String&);
	~String();

	int size() const;
	void push_back(const char*);
	const char* c_str() const;

	String& operator=(const String&);
	String& operator+=(const String&);
	char& operator[](int);

	bool operator==(const String&);
	bool operator>(const String&);
	bool operator<(const String&);
	bool operator!=(const String&);
	bool operator>=(const String&);
	bool operator<=(const String&);

	friend istream& operator>>(istream& in, String& str);
	friend ostream& operator<<(ostream& out, const String& str);
	friend String operator+(String s1, const String& s2);
};
#endif // end of STRING_H
