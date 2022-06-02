#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

#ifndef _MY_VECTOR_H
#define _MY_VECTOR_H

template <class T>
class MyVector {
private:
	int m_size;
	T* m_ptr;
public:
	MyVector() {
		m_ptr = nullptr;
		m_size = 0;
	}

	~MyVector() {
		if (m_ptr != nullptr && m_size != 0) {
			delete[] m_ptr;
			m_ptr = nullptr;
		}
		m_size = 0;
	}

	int size() const {
		return m_size;
	}

	T& operator[](const int& n) {
		return m_ptr[n];
	}

	void push_back(const T& elem) {
		T* temp_ptr = m_ptr;
		m_ptr = new T[m_size + 1];
		for (int i = 0; i < m_size; i++) {
			m_ptr[i] = temp_ptr[i];
		}

		m_ptr[m_size++] = elem;
		if (temp_ptr != nullptr) {
			delete temp_ptr;
			temp_ptr = nullptr;
		}
	}
};
#endif // !_MY_VECTOR_H

#ifndef _NHANVIEN_H_
#define _NHANVIEN_H_

struct Ngay {
	int m_Ngay, m_Thang, m_Nam;
};

class NhanVien {
private:
	char m_MaSo[10];
	char m_HoTen[30];
	char m_GioiTinh[5];
	Ngay m_NgaySinh;
	char m_DiaChi[50];
public:
	NhanVien() {}
	NhanVien(const char* maso, const char* hoten, const char* gioitinh, const Ngay& ngsinh, const char* diachi) {
		strcpy(m_MaSo, maso);
		m_MaSo[strlen(maso)] = '\0';
		strcpy(m_HoTen, hoten);
		m_HoTen[strlen(hoten)] = '\0';
		strcpy(m_GioiTinh, gioitinh);
		m_GioiTinh[strlen(gioitinh)] = '\0';
		m_NgaySinh.m_Ngay = ngsinh.m_Ngay;
		m_NgaySinh.m_Thang = ngsinh.m_Thang;
		m_NgaySinh.m_Nam = ngsinh.m_Nam;
		strcpy(m_DiaChi, diachi);
		m_DiaChi[strlen(diachi)] = '\0';
	}

	const char* layMaSo() {
		return m_MaSo;
	}

	virtual ~NhanVien() = default;

	void nhapThongTinCoBan() {
		cout << "Nhap Ma So: ";
		cin.getline(m_MaSo, 10);
		cout << "Nhap Ho Ten: ";
		cin.getline(m_HoTen, 30);
		cout << "Nhap Gioi Tinh: ";
		cin.getline(m_GioiTinh, 5);
		cout << "Nhap ngay sinh (dd mm yyyy): ";
		cin >> m_NgaySinh.m_Ngay >> m_NgaySinh.m_Thang >> m_NgaySinh.m_Nam;
		cin.ignore(10000, '\n');
		cout << "Nhap dia chi: ";
		cin.getline(m_DiaChi, 50);
	}
	void xuatThongTinCoBan() {
		cout << "Ma so: " << m_MaSo << endl;
		cout << "Ho ten: " << m_HoTen << endl;
		cout << "Phai: " << m_GioiTinh << endl;
		cout << "Ngay sinh: " << m_NgaySinh.m_Ngay << "/" << m_NgaySinh.m_Thang << "/" << m_NgaySinh.m_Nam << endl;
		cout << "Dia chi: " << m_DiaChi << endl;
	}

	virtual void nhapToanBoThongTin() = 0;
	virtual void xuatToanBoThongTin() = 0;
	virtual int tinhLuong() = 0;
};
#endif // !_NHANVIEN_H_

#ifndef _NVCONGNHAT_H_
#define _NVCONGNHAT_H_

class NVCongNhat : public NhanVien {
private:
	int m_SoNgay;
public:
	NVCongNhat()
		: NhanVien()
	{
		m_SoNgay = 0;
	}
	NVCongNhat(const char* maso, const char* hoten, const char* gioitinh, const Ngay& ngsinh, const char* diachi, int songay) 
		: NhanVien(maso, hoten, gioitinh, ngsinh, diachi) 
	{
		m_SoNgay = songay;
	}

	NVCongNhat(const NVCongNhat& nvcn)
		:NhanVien(nvcn)
	{
		m_SoNgay = nvcn.m_SoNgay;
	}

	void nhapToanBoThongTin() {
		nhapThongTinCoBan();
		cout << "Nhap so ngay: ";
		cin >> m_SoNgay;
	}

	void xuatToanBoThongTin() {
		xuatThongTinCoBan();
		cout << "So Ngay: " << m_SoNgay;
	}

	int tinhLuong() {
		return 300000 * m_SoNgay;
	}
};

#endif


#ifndef _NVSANXUAT_H_
#define _NVSANXUAT_H_

class NVSanXuat : public NhanVien {
private:
	int m_SoSanPham;
public:
	NVSanXuat()
		: NhanVien()
	{
		m_SoSanPham = 0;
	}

	NVSanXuat(const char* maso, const char* hoten, const char* gioitinh, const Ngay& ngsinh, const char* diachi, int sosanpham)
		: NhanVien(maso, hoten, gioitinh, ngsinh, diachi)
	{
		m_SoSanPham = sosanpham;
	}

	NVSanXuat(const NVSanXuat& nvsx)
		: NhanVien(nvsx) 
	{
		m_SoSanPham = nvsx.m_SoSanPham;
	}

	void nhapToanBoThongTin() {
		nhapThongTinCoBan();
		cout << "Nhap so ngay: ";
		cin >> m_SoSanPham;
	}

	void xuatToanBoThongTin() {
		xuatThongTinCoBan();
		cout << "So Ngay: " << m_SoSanPham;
	}

	int tinhLuong() {
		return 20000 * m_SoSanPham;
	}
};

#endif // !_NVSANXUAT_H_

#ifndef _CONGTY_H_
#define _CONGTY_H_

char NVCN[10] = "NVCN";
char NVSX[10] = "NVSX";

class CongTy {
private:
	MyVector<NhanVien*> m_DanhSach;
public:
	CongTy() {}
	~CongTy() {
		if (m_DanhSach.size() != 0) {
			for (int i = 0; i < m_DanhSach.size(); i++) {
				if (m_DanhSach[i] != nullptr) {
					delete m_DanhSach[i];
					m_DanhSach[i] = nullptr;
				}
			}
		}
	}

	void nhapDanhSach() {
		int n;
		cout << "Nhap so luong nhanvien: ";
		cin >> n;

		int loai = 0;
		for (int i = 0; i < n; i++) {
			cout << "Nhap loai (0: NVSanXuat, 1: NVCongNhat): ";
			cin >> loai;
			NhanVien* nv = nullptr;
			if (loai == 0) {
				nv = new NVSanXuat;
			}
			else {
				nv = new NVCongNhat;
			}
			cin.ignore(10000, '\n');
			nv->nhapToanBoThongTin();
			m_DanhSach.push_back(nv);
		}
	}

	void xuatDanhSach() {
		if (m_DanhSach.size() == 0) {
			cout << "Danh sach trong" << endl;
			return;
		}
		
		for (int i = 0; i < m_DanhSach.size(); i++) {
			cout << "Thong Tinh nhanvien " << i << endl;
			m_DanhSach[i]->xuatToanBoThongTin();
			cout << endl << endl;
		}
	}

	void themNhanVien() {
		NhanVien* nv;
		int loai = 0;
		cout << "Nhap loai (0: NVSanXuat, 1: NVCongNhat): ";
		cin >> loai;
		if (loai == 0)
			nv = new NVSanXuat;
		else
			nv = new NVCongNhat;
		cin.ignore(10000, '\n');
		cout << "Nhap thong tin cua nhanvien" << endl;
		nv->nhapToanBoThongTin();
		m_DanhSach.push_back(nv);
		cout << "Them thanh cong nhanvien vao danh sach cua cong ty" << endl;
	}

	void sapXepTheoMaSo() {
		for (int i = 0; i < m_DanhSach.size() - 1; i++) {
			for (int j = 0; j < m_DanhSach.size() - 1 - i; j++) {
				if (strcmp(m_DanhSach[j]->layMaSo(), m_DanhSach[j + 1]->layMaSo()) == 1) {
					NhanVien* p = m_DanhSach[j];
					m_DanhSach[j] = m_DanhSach[j + 1];
					m_DanhSach[j + 1] = p;
				}
			}
		}
	}

	int tinhTongLuong() {
		int luon = 0;
		for (int i = 0; i < m_DanhSach.size(); i++) {
			luon += m_DanhSach[i]->tinhLuong();
		}
		return luon;
	}

	int tinhLuongNVCN() {
		int luong = 0;
		for (int i = 0; i < m_DanhSach.size(); i++) {
			NVCongNhat* p = dynamic_cast<NVCongNhat*>(m_DanhSach[i]);
			if (p != nullptr) {
				luong += m_DanhSach[i]->tinhLuong();
			}
		}
		return luong;
	}

	int tinhLuongNVSX() {
		int luong = 0;
		for (int i = 0; i < m_DanhSach.size(); i++) {
			NVSanXuat* p = dynamic_cast<NVSanXuat*>(m_DanhSach[i]);
			if (p != nullptr) {
				luong += m_DanhSach[i]->tinhLuong();
			}
		}
		return luong;
	}

	void ghiFile(const char* ten_file) {
		ofstream fout(ten_file, ios::app | ios::binary);
		if (!fout)
			return;

		for (int i = 0; i < m_DanhSach.size(); i++) {
			NVCongNhat* p = dynamic_cast<NVCongNhat*>(m_DanhSach[i]);
			if (p != nullptr) {
				fout.write(::NVCN, sizeof(::NVCN));
				fout.write((char*)m_DanhSach[i], sizeof(NVCongNhat));
			}
			else {
				fout.write(::NVSX, sizeof(::NVSX));
				fout.write((char*)m_DanhSach[i], sizeof(NVSanXuat));
			}
		}
	}

	void docFile(const char* ten_file) {
		ifstream fin(ten_file, ios::binary);
		if (!fin)
			return;

		char lnv[10];
		while (fin.eof() == false) {
			fin.read(lnv, sizeof(lnv));
			if (fin.eof() == true)
				return;
			if (strcat(lnv, ::NVCN) == 0) {
				NVCongNhat nvcn;
				fin.read((char*)&nvcn, sizeof(NVCongNhat));
				m_DanhSach.push_back(new NVCongNhat(nvcn));
			}
			else {
				NVSanXuat nvsx;
				fin.read((char*)&nvsx, sizeof(NVSanXuat));
				m_DanhSach.push_back(new NVSanXuat(nvsx));
			}
		}
	}
};
#endif // !_CONGTY_H_

#include <crtdbg.h>

void test() {
	CongTy ct;
	ct.nhapDanhSach();
	ct.xuatDanhSach();
	ct.themNhanVien();
	ct.sapXepTheoMaSo();
	ct.xuatDanhSach();
	ct.ghiFile("nhanvien.dat");
}

void test_2() {
	CongTy ct;
	ct.docFile("nhanvien.dat");
	ct.xuatDanhSach();
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//test();
	test_2();
	_CrtDumpMemoryLeaks();
}