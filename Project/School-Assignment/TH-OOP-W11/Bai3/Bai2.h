#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <cstring>
using namespace std;


#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
public:
	T m_data;
	Node<T>* m_next;
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


	int length() const;
	bool is_empty() const;

	void push_head(const T&);
	void push_tail(const T&);
	void pop_head();
	void pop_tail();
};

#endif // LINKED_LIST_H


#ifndef NHANVIEN_H
#define NHANVIEN_H

class NhanVien {
private:
	int m_MaNV;
	char m_HoTen[50];
	char m_GioiTinh[50];
	char m_NgaySinh[50];
	char m_DiaChi[50];
public:
	NhanVien() = default;
	NhanVien(int, const char*, const char*, const char*, const char*);
	virtual ~NhanVien() = default;

	int layMaNV();

	void nhapThongTinCoBan();
	void xuatThongTinCoBan();
	double tinhTuoi(const int&);
	virtual int tinhLuong() = 0;
	virtual void nhapThongTin() = 0;
	virtual void xuatThongTin() = 0;
};

#endif // NHANVIEN_H

#ifndef NHAN_VIEN_CONG_NHAT_H
#define NHAN_VIEN_CONG_NHAT_H

class NVCongNhat : public NhanVien {
private:
	int m_SoNgay;
public:
	NVCongNhat();
	NVCongNhat(int, const char*, const char*, const char*, const char*, int);
	NVCongNhat(const NVCongNhat&);
	int tinhLuong();
	void nhapThongTin();
	void xuatThongTin();
};

#endif // NHAN_VIEN_CONG_NHAT_H

#ifndef NHAN_VIEN_SAN_XUAT_H
#define NHAN_VIEN_SAN_XUAT_H

class NVSanXuat : public NhanVien {
private:
	int m_SoSanPham;
public:
	NVSanXuat();
	NVSanXuat(int, const char*, const char*, const char*, const char*, int);
	NVSanXuat(const NVSanXuat&);
	int tinhLuong();
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
	int tinhLuongNVSanXuat();
	int tinhLuongNVCongNhat();
	int tinhTongLuong();
	void timNhanVienCoLuongLonNhat();
	void sapXepTang();
	void themNhanVien(NhanVien*);
	bool ghiNVFile(const string&);
	bool docNVFile(const string&);
	bool luongLonHonTrungBinh(const string&);
};

#endif // CONGTY_H
