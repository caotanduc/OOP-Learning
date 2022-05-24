#include <iostream>
using namespace std;


class MyIntArray {
private:
    int* pArr;
    int size;
public:
    ~MyIntArray();
    MyIntArray(int sz);
    MyIntArray& operator=(const MyIntArray&);
};

MyIntArray& MyIntArray::operator=(const MyIntArray& src) {
    if (this != &src) {
        delete[] this->pArr;
        this->size = src.size;
        this->pArr = new int [this->size];
        for (int i = 0; i < this->size; i++) {
            this->pArr[i] = src.pArr[i];
        } 
    }
    return *this;
}


MyIntArray::~MyIntArray() {
    if (this->size > 0) {
        this->size = 0;
        delete[] this->pArr;
        this->pArr = NULL;
    }
    /* cout << "delete successfully" << endl; */
}


MyIntArray::MyIntArray(int sz) {
    if (sz <= 0) {
        sz = 0;
        this->pArr = NULL;
        return;
    }
    this->size = sz;
    this->pArr = new int[this->size];
    for (int i = 0; i < this->size; i++) {
        pArr[i] = 0;
    }
}


int main() {
    MyIntArray a(10);
    MyIntArray *b = new MyIntArray(20);

        
    delete b;
    return 0;
}
