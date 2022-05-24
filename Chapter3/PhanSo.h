#ifndef _PHAN_SO_H
#define _PHAN_SO_H

#include <iostream>
using namespace std;

class PhanSo {
private: 
    int tu;
    int mau;
public:
    PhanSo();
    PhanSo(int, int);
    PhanSo& operator+=(const PhanSo&);
    const PhanSo operator+(const PhanSo&) const;
    bool operator==(const PhanSo&) const;
    PhanSo& operator++();
    PhanSo operator++(int);

friend ostream& operator<<(ostream& out, const PhanSo& src) ;
};

#endif
