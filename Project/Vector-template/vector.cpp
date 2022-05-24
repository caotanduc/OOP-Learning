#include "Bai1.h"

template <typename T>
vector<T>::vector() {
	ptr = NULL;
	sz = 0;
	capacity = 0;
}


template <typename T>
vector<T>::vector(int s) {
	sz = capacity = s;
	ptr = new T[sz]();
}

template <typename T>
vector<T>::~vector() {
	if (ptr != NULL) {
		delete[] ptr;
		ptr = NULL;
	}
	sz = 0;
	capacity = 0;
}

template <typename T>
vector<T>::vector(const vector<T>& v) {
	sz = v.sz;
	capacity = v.capacity;
	ptr = new T[capacity]();
	for (int i = 0; i < sz; i++) {
		ptr[i] = v.ptr[i];
	}
}

template <typename T>
T& vector<T>::operator[](int n) {
	assert(ptr != NULL && n < capacity);
	return ptr[n];
}

template <typename T>
int vector<T>::size() const {
	return sz;
}

template <typename T>
int vector<T>::getCapacity() const {
	return capacity;
}

template <typename T>
void vector<T>::reserve(int newalloc) {
	if (newalloc <= capacity)
		return;
	T* temp = ptr;
	capacity = newalloc;
	ptr = new T[capacity]();
	if (temp) {
		for (int i = 0; i < sz; i++) {
			ptr[i] = temp[i];
		}
		delete[] temp;
		temp = NULL;
	}
}

template <typename T>
void vector<T>::push_back(const T& elem) {
	if (sz + 1 > capacity) {
		reserve(capacity + 1);
	}
	ptr[sz++] = elem;
}


template <typename T>
void vector<T>::print() const {
	if (ptr == NULL) {
		cout << "there's no one at all!" << endl;
	}

	for (int i = 0; i < sz; i++) {
		cout << ptr[i] << " ";
	}

	cout << endl;
}

template <typename T>
void vector<T>::resize(int newsize) {
	if (newsize == capacity) {
		sz = capacity;
		return;
	}
	if (newsize <= 0) {
		if (ptr != NULL) {
			delete[] ptr;
			ptr = NULL;
		}
		sz = 0;
		capacity = 0;
		return;
	}

	if (newsize > capacity) {
		reserve(newsize);
	}
	sz = newsize;
}

template <typename T>
vector<T>& vector<T>::operator=(const vector<T>& v) {
	if (this == &v)
		return *this;

	if (ptr != NULL) {
		delete[] ptr;
		ptr = NULL;
	}

	sz = v.sz;
	capacity = v.capacity;
	ptr = new T[capacity]();
	for (int i = 0; i < sz; i++) {
		ptr[i] = v.ptr[i];
	}

	return *this;
}