#ifndef CVECTOR_H
#define CVECTOR_H
#include<iostream>
#include<string>
#include <cassert>
using namespace std;
/* Dinh nghia lop vectorClass */
template<typename T>
class vector {
private:
	T* ptr;
	int sz;
	int capacity;
public:
	vector();
	vector(int s);
	~vector();
	T& operator[](int n);
	int size() const;
	int getCapacity() const;
	void reserve(int newalloc);
	void push_back(const T& elem);
	void print() const;
	// other methods

	vector(const vector<T>&);
	void resize(int newsize);
	vector<T>& operator=(const vector<T>&);
};
#endif

