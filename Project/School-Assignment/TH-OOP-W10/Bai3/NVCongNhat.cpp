#include "NVCongNhat.h"

const long long BASIC_PAY = 300000;

NVCongNhat::NVCongNhat() 
	: NhanVien() {
		m_SoNgay = 0;
}

NVCongNhat::NVCongNhat(NumberString maso, String hoten, String gioitinh, Date ngaysinh, String diachi, long long songay)
	: NhanVien(maso, hoten, gioitinh, ngaysinh, diachi) {
		m_SoNgay = songay;
}

long long NVCongNhat::tinhLuong() {
	return m_SoNgay * BASIC_PAY;
}

void NVCongNhat::nhapThongTin() {
	nhapThongTinCoBan();
	cout << "Nhap so ngay lam duoc: ";
	cin >> m_SoNgay;
}

void NVCongNhat::xuatThongTin() {
	xuatThongTinCoBan();
	cout << "So ngay lam: " << m_SoNgay;
	cout << endl;
}
