#include "NhanVien.h"
Date hientai(18, 5, 2022);

NhanVien::NhanVien(NumberString manv, String hoten, String gioitinh, Date ngaysinh, String diachi) {
	m_MaNV = manv;
	m_HoTen = hoten;
	m_GioiTinh = gioitinh;
	m_NgaySinh = ngaysinh;
	m_DiaChi = diachi;
}

NumberString NhanVien::layMaNV() {
	return m_MaNV;
}


void NhanVien::nhapThongTinCoBan() {
	cout << "Nhap ma so nhan vien: ";
	cin >> m_MaNV;
	cin.ignore(10000, '\n');
	cout << "Nhap ho ten: ";
	cin >> m_HoTen;
	cout << "Nhap gioi tinh: ";
	cin >> m_GioiTinh;
	cout << "Nhap ngay sinh: " ;
	cin >> m_NgaySinh;
	if (m_GioiTinh == "nam") {
		double tuoi = tinhTuoi(hientai);
		if (tuoi < 18 || tuoi > 60)
			throw invalid_argument("Invalid Age for male");
	}
	else {
		double tuoi = tinhTuoi(hientai);
		if (tuoi < 18 || tuoi > 55)
			throw invalid_argument("Invalid Age for female");
	}

	cin.ignore(10000, '\n');
	cout << "Nhap dia chi: ";
	cin >> m_DiaChi;
}

void NhanVien::xuatThongTinCoBan() {
	cout << "MSNV: " << m_MaNV << endl;
	cout << "Ho ten: " << m_HoTen << endl;
	cout << "Gioi tinh: " << m_GioiTinh << endl;
	cout << "Ngay sinh: " << m_NgaySinh << endl;
	cout << "Dia chi: " << m_DiaChi << endl;
	cout << "Tuoi: " << tinhTuoi(hientai) << endl;
}

double NhanVien::tinhTuoi(const Date& d) {
	return (double)d.dateDiff(m_NgaySinh) / 365.0;
}
