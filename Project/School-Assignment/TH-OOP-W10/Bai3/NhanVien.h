#ifndef NHANVIEN_H
#define NHANVIEN_H

#include "NumberString.h"
#include "String.h"
#include "Date.h"

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
