#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

#ifndef STRING_H
#define STRING_H

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

#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
	T m_data;
	Node<T>* m_next;
	template <class U> friend class LinkedList;
	friend class CongTy;
public:
	Node();
	Node(const T& data);
};

#endif // !NODE_H

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <class T>
class LinkedList {
private:
	Node<T>* m_head;
	Node<T>* m_tail;
	friend class CongTy;
public:
	LinkedList();
	~LinkedList();

	LinkedList& operator=(const LinkedList&);

	int length() const;
	bool is_empty() const;

	void push_head(const T&);
	void push_tail(const T&);
	void pop_head();
	void pop_tail();
	void print();

	void remove_all();
};

#endif // LINKED_LIST_H

#ifndef DATE_H
#define DATE_H

class Date {
private:
	int m_Day;
	int m_Month;
	int m_Year;
public:
	Date();
	Date(int, int, int);
	Date(const Date&);

	Date& operator=(const Date&);

	bool operator==(const Date&) const;
	bool operator!=(const Date&) const;

	int dateDiff(const Date&) const;
	friend istream& operator>>(istream&, Date&);
	friend ostream& operator<<(ostream&, const Date&);
};

#endif // DATE_H

#ifndef NUMBER_STRING_H
#define NUMBER_STRING_H

class NumberString {
private:
	int m_Number;
	int MAX_SIZE = 5;
public:
	NumberString();
	NumberString(const int&);
	NumberString(const NumberString&);

	NumberString& operator=(const NumberString&);

	bool operator==(const NumberString&) const;
	bool operator<(const NumberString&) const;
	bool operator>(const NumberString&) const;
	bool operator!=(const NumberString&) const;
	bool operator<=(const NumberString&) const;
	bool operator>=(const NumberString&) const;

	friend istream& operator>>(istream&, NumberString&);
	friend ostream& operator<<(ostream&, const NumberString&);
};

#endif // NUMBER_STRING_H

#ifndef NHANVIEN_H
#define NHANVIEN_H

class NhanVien {
private:
	NumberString m_MaNV;
	String m_HoTen;
	String m_GioiTinh;
	Date m_NgaySinh;
	String m_DiaChi;
public:
	NhanVien() = default;
	NhanVien(NumberString, String, String, Date, String);
	virtual ~NhanVien() = default;

	NumberString layMaNV();

	virtual long long tinhLuong() = 0;
	void nhapThongTinCoBan();
	virtual void nhapThongTin() = 0;
	void xuatThongTinCoBan();
	virtual void xuatThongTin() = 0;
	double tinhTuoi(const Date&);
};

#endif // NHANVIEN_H

#ifndef NHAN_VIEN_CONG_NHAT_H
#define NHAN_VIEN_CONG_NHAT_H

class NVCongNhat : public NhanVien {
private:
	long long m_SoNgay;
public:
	NVCongNhat();
	NVCongNhat(NumberString, String, String, Date, String, long long);

	long long tinhLuong();
	void nhapThongTin();
	void xuatThongTin();
};

#endif // NHAN_VIEN_CONG_NHAT_H

#ifndef NHAN_VIEN_SAN_XUAT_H
#define NHAN_VIEN_SAN_XUAT_H

class NVSanXuat : public NhanVien {
private:
	long long m_SoSanPham;
public:
	NVSanXuat();
	NVSanXuat(NumberString, String, String, Date, String, long long);

	long long tinhLuong();
	void nhapThongTin();
	void xuatThongTin();
};

#endif // NHAN_VIEN_SAN_XUAT_H

#ifndef CONGTY_H
#define CONGTY_H

class CongTy {
private:
	LinkedList<NhanVien*> m_DanhSach;
public:
	CongTy() = default;
	CongTy(const CongTy&);
	~CongTy();

	void nhapDanhSach();
	void xuatDanhSach();
	long long tinhLuongNVSanXuat();
	long long tinhLuongNVCongNhat();
	long long tinhTongLuong();
	void sapXepTang();
	void themNhanVien(NhanVien*);
	bool ghiNVFile(const String&);
	bool ghiNVSanXuatFile(const String&);
	bool ghiNVCongNhatFile(const String&);
};

#endif // CONGTY_H