#include "NVSanXuat.h"

const long long BASIC_PAY = 20000;

NVSanXuat::NVSanXuat() 
	: NhanVien() {
		m_SoSanPham = 0;
}

NVSanXuat::NVSanXuat(NumberString maso, String hoten, String gioitinh, Date ngaysinh, String diachi, long long sosp)
	: NhanVien(maso, hoten, gioitinh, ngaysinh, diachi) {
		m_SoSanPham = sosp;
}

long long NVSanXuat::tinhLuong() {
	return m_SoSanPham * BASIC_PAY;
}

void NVSanXuat::nhapThongTin() {
	nhapThongTinCoBan();
	cout << "Nhap so san pham lam duoc: ";
	cin >> m_SoSanPham;
}

void NVSanXuat::xuatThongTin() {
	xuatThongTinCoBan();
	cout << "So san pham: " << m_SoSanPham;
	cout << endl;
}
