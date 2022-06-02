#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cassert>
#include <fstream>

using namespace std;

#ifndef STRING_H
#define STRING_H


class String {
private:
	char* m_buffer;
	int m_size;
public:
	String();
	String(const char* );
	String(const String&);
	~String();

	int size() const;
	bool is_empty() const;
	void push_back(const char*);
	const char* c_str() const;


	String& operator=(const String&);
	String& operator+=(const String&);
	char& operator[](int);

	bool operator<(const String&);
	bool operator>(const String&);
	bool operator==(const String&);
	bool operator<=(const String&);
	bool operator>=(const String&);
	bool operator!=(const String&);

	friend istream& operator>>(istream&, String&);
	friend ostream& operator<<(ostream&, const String&);
	friend String operator+(String, const String&);
};

#endif

#ifndef SINHVIEN_H
#define SINHVIEN_H
class SinhVien {
private:
	String m_HoTen;
	String m_MaSo;
	String m_NgaySinh;
	// 0: baitap 0.25
	// 1: giuaky 0.25
	// 2: cuoiky 0.5
	double m_Diem[3];
public:
	SinhVien();
	SinhVien(const String&, const String&, const String&, const double&, const double&, const double&);
	~SinhVien() = default;

	bool operator>(const SinhVien& sv) {
		return m_MaSo > sv.m_MaSo;
	}

	bool operator<(const SinhVien& sv) {
		return m_MaSo < sv.m_MaSo;
	}

	SinhVien(const SinhVien&);
	SinhVien& operator=(const SinhVien&);
	double tinhDiemTB() const;
	void print();
	String layTen() const;
	String layMaSo() const;
	String layNgaySinh() const;
	double layDBT() const;
	double layDGK() const;
	double layDCK() const;
	String xepLoai() const;
};

#endif


#ifndef CVECTOR_H
#define CVECTOR_H

template<typename T>
class cvector {
private:
	T* ptr;
	int sz;
	int capacity;
public:
	cvector();
	cvector(int s);
	~cvector();
	T& operator[](int n);
	T operator[](int n) const;
	int size() const;
	int getCapacity() const;
	void reserve(int newalloc);
	void push_back(const T& elem);
	void print() const;
	// other methods

	cvector(const cvector<T>&);
	void resize(int newsize);
	cvector<T>& operator=(const cvector<T>&);

	// algorithm
	bool is_increase() const;
	void sort(bool asc = true);
};

#endif


#ifndef QLSINHVIEN_H
#define QLSINHVIEN_H

class QLSinhVien {
private:
	cvector<SinhVien> ds;
public:
	QLSinhVien() = default;
	~QLSinhVien() = default;
	QLSinhVien(const cvector<SinhVien>&);

	double tinhDiemTB();
	friend bool docFile(const String&, QLSinhVien&);
	friend bool ghiFile(const String&, const QLSinhVien&);
	bool ghiThapHonTBFile(const String&);
	bool ghiMotSV(const String&, const SinhVien&);
	cvector<SinhVien> timThapHonTB();
	void print();
	bool themVaoDSTang(const SinhVien&);
	bool ghiTangVaoFile(const String&,const SinhVien&);
	bool ghiXepLoaiFile(const String&);
};

#endif

