#include "PhanSo.h"

PhanSo::PhanSo() {
    this->tu = 0;
    this->mau = 1;
}

PhanSo::PhanSo(int t, int m) {
    this->tu = t;
    this->mau = m;
}


PhanSo& PhanSo::operator+=(const PhanSo& src) {
    this->tu = this->tu * src.mau + this->mau * src.tu;
    this->mau = this->mau * src.mau;
    return *this;
}

const PhanSo PhanSo::operator+(const PhanSo& src) const {
    PhanSo temp;
    temp.tu = this->tu * src.mau + this->mau * src.tu;
    temp.mau = this->mau * src.mau;
    return temp;
}

bool PhanSo::operator==(const PhanSo& src) const {
    return ( (this->tu == src.tu) && (this->mau == src.mau) );
}

// prefix
PhanSo& PhanSo::operator++() {
    this->tu = this->tu + this->mau;
    return *this;
}

// postfix
PhanSo PhanSo::operator++(int) {
    PhanSo temp = *this;
    ++(*this);
    return temp;
}


ostream& operator<<(ostream& out, const PhanSo& src) {
    out << src.tu << "/" << src.mau;
    return out;
}
