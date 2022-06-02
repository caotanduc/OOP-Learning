#ifndef NHAN_VIEN_SAN_XUAT_H
#define NHAN_VIEN_SAN_XUAT_H

#include "NhanVien.h"

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
