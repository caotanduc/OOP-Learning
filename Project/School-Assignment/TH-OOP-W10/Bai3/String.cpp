#include "String.h"

const int LIMIT_STRING_LEN = 10000;

String::String() {
	m_buffer = nullptr;
	m_size = 0;
}


String::String(const int& len) {
	m_buffer = nullptr;
	m_size = 0;
}


String::String(const char* buffer) {
	m_size = strlen(buffer);
	if (m_size != 0) {
		m_buffer = new char [m_size + 1];
		strcpy(m_buffer, buffer);
		m_buffer[m_size] = '\0';
	}
}


String::String(const String& str) {
	m_size = str.m_size;
	if (m_size != 0) {
		m_buffer = new char[m_size + 1];
		strcpy(m_buffer, str.m_buffer);
		m_buffer[m_size] = '\0';
	}
}


String::~String() {
	if (m_buffer != nullptr) {
		delete[] m_buffer;
		m_buffer = nullptr;
	}
	m_size = 0;
}



String& String::operator=(const String& str) {
	if (this == &str) 
		return *this;
	

	if (m_buffer != nullptr) {
		delete[] m_buffer;
		m_buffer = nullptr;
	}

	m_size = str.m_size;
	if (m_size != 0) {
		m_buffer = new char [m_size + 1];
		strcpy(m_buffer, str.m_buffer);
		m_buffer[m_size] = '\0';
	}

	return *this;
}


int String::size() const {
	return m_size;
}


void String::push_back(const char* s) {
	*this += s;
}


const char* String::c_str() const {
	return m_buffer;
}


String& String::operator+=(const String& str) {
	bool buffer_check = (m_buffer == nullptr);
	if (buffer_check) {
		*this = str;
	}

	if (buffer_check == false && str.m_buffer == nullptr) {
		int final_size = m_size + str.m_size;
		char* temp_buffer = m_buffer;

		m_buffer = new char[final_size + 1];
		strcpy(m_buffer, temp_buffer);
		strcpy(m_buffer + m_size, str.m_buffer);
		m_buffer[final_size] = '\0';

		m_size = final_size;
		delete[] temp_buffer;
		temp_buffer = nullptr;
	}

	return *this;
}



char& String::operator[](int n) {
	if (m_buffer == nullptr || n >= m_size) 
		throw invalid_argument("Index out of range!");
	return m_buffer[n];
}




bool String::operator==(const String& str) {
	return strcmp(m_buffer, str.m_buffer) == 0;
}


bool String::operator>(const String& str) {
	return strcmp(m_buffer, str.m_buffer) == 1;
}


bool String::operator<(const String& str) {
	return strcmp(m_buffer, str.m_buffer) == -1;
}


bool String::operator!=(const String &str) {
	return (*this == str) == false;
}


bool String::operator>=(const String& str) {
	return (*this < str) == false;
}


bool String::operator<=(const String& str) {
	return (*this > str) == false;
}



istream& operator>>(istream& in, String& str) {
	char temp_buffer[LIMIT_STRING_LEN];		
	in.getline(temp_buffer, LIMIT_STRING_LEN);
	str = temp_buffer;
	return in;
}


ostream& operator<<(ostream& out, const String& str) {
	if (str.m_buffer == nullptr) 
		throw invalid_argument("Empty String");
	out << str.m_buffer;
	return out;
}


String operator+(String s1, const String& s2) {
	return s1 += s2;
}