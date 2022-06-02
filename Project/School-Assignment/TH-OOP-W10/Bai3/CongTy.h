#ifndef CONGTY_H
#define CONGTY_H

#include "LinkedList.h"
#include "NhanVien.h"
#include "NVSanXuat.h"
#include "NVCongNhat.h"
#include <fstream>

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
