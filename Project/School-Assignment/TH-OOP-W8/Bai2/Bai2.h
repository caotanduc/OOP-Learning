#include <iostream>
#include <string>
using namespace std;

#ifndef NHANVIEN_H
#define NHANVIEN_H


class NhanVien
{
protected:
	string maNV;
	string hoTen;
	struct NGSINH {
		int ngay;
		int thang;
		int nam;
	} ngSinh;
	string diaChi;
public:
	NhanVien();
	NhanVien(string, string, struct NGSINH, string);
	NhanVien(const NhanVien&);

	virtual string layMANV();
	virtual string layHoTen();
	virtual string layNGSINH();
	virtual string layDC();
	virtual int layThangSinh();
	virtual long long tinhLuong() = 0;
	virtual void nhapThongTin() = 0;
	virtual void nhapThongTinCoBan();
	virtual void xuatThongTinCoBan();
	virtual void xuatThongTin() = 0;
	virtual NhanVien* saoChep() = 0;
};
#endif

#ifndef NVSANXUAT_H
#define NVSANXUAT_H

class NVSanXuat : public NhanVien {
private:
	long long soSP;
public:
	NVSanXuat();
	NVSanXuat(string, string, struct NGSINH, string, long long);
	NVSanXuat(const NVSanXuat&);
	long long tinhLuong();
	void nhapThongTin();
	void xuatThongTin();
	NhanVien* saoChep();
};

#endif

#ifndef NVCONGNHAT_H
#define NVCONGNHAT_H

class NVCongNhat : public NhanVien {
private:
	long long soNgay;
public:
	NVCongNhat();
	NVCongNhat(string, string, struct NGSINH, string, long long);
	NVCongNhat(const NVCongNhat&);
	long long tinhLuong();
	void nhapThongTin();
	void xuatThongTin();
	NhanVien* saoChep();
};


#endif // !NVCONGNHAT_H


#ifndef CONGTY_H
#define CONGTY_H

class CongTy {
private:
	NhanVien** ds;
	int sl;
public:
	CongTy();
	CongTy(const CongTy&);
	~CongTy();
	void nhapDanhSach();
	void xuatDanhSach();
	long long tongLuong();
	void NVMaxLuong();
	long long tinhLuongTB();
	void timNhanVienTheoMa();
	void timNhanVienTheoTen();
	int nhanVienSinhTrongThang5();
};

#endif
