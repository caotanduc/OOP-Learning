#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

#ifndef cvector_h
#define cvector_h

template <class T>
class cvector {
private:
	int m_size;
	T* m_ptr;
public:
	cvector() {
		m_size = 0;
		m_ptr = nullptr;
	}

	~cvector() {
		if (m_size != 0 && m_ptr != nullptr) {
			delete[] m_ptr;
			m_ptr = nullptr;
		}
	}

	int size() const { return m_size; }

	T& operator[](int n) {
		return m_ptr[n];
	}

	void push_back(const T& elem) {
		T* temp = m_ptr;
		m_ptr = new T[m_size + 1];
		for (int i = 0; i < m_size; i++)
			m_ptr[i] = temp[i];

		m_ptr[m_size++] = elem;
		if (temp != nullptr) {
			delete[] temp;
			temp = nullptr;
		}
	}
};
#endif // cvector_h

#ifndef nhanvien_h
#define nhanvien_h

struct Ngay {
	int m_ngay, m_thang, m_nam;
	Ngay& operator=(const Ngay& ng) {
		m_ngay = ng.m_ngay;
		m_thang = ng.m_thang;
		m_nam = ng.m_nam;
		return *this;
	}
};

class NhanVien {
private:
	char m_maso[10];
	char m_hoten[50];
	char m_gioitinh[10];
	Ngay m_ngaysinh;
	char m_diachi[50];
public:
	NhanVien() {}
	NhanVien(const char* maso, const char* hoten, const char* gioitinh, const Ngay& ngaysinh, const char* diachi) {
		strcpy(m_maso, maso);
		strcpy(m_hoten, hoten);
		strcpy(m_gioitinh, gioitinh);
		m_ngaysinh = ngaysinh;
		strcpy(m_diachi, diachi);

		m_maso[strlen(maso)] = '\0';
		m_hoten[strlen(hoten)] = '\0';
		m_gioitinh[strlen(gioitinh)] = '\0';
		m_gioitinh[strlen(diachi)] = '\0';
	}

	const char* layMaSo() const {
		return m_maso;
	}

	void nhapThongTinCoBan() {
		cout << "Nhap ma so: ";
		cin.getline(m_maso, 10);
		cout << "Nhap ho ten: ";
		cin.getline(m_hoten, 50);
		cout << "Nhap gioi tinh: ";
		cin.getline(m_gioitinh, 10);
		cout << "Nhap ngay sinh (dd mm yyyy): ";
		cin >> m_ngaysinh.m_ngay >> m_ngaysinh.m_thang >> m_ngaysinh.m_nam;
		cin.ignore(10000, '\n');
		cout << "Nhap dia chi: ";
		cin.getline(m_diachi, 50);
	}

	void xuatThongTinCoBan() {
		cout << "Ma so: " << m_maso << endl;
		cout << "Ho ten: " << m_hoten << endl;
		cout << "Gioi tinh: " << m_gioitinh << endl;
		cout << "Ngay sinh: " << m_ngaysinh.m_ngay << "/" << m_ngaysinh.m_thang << "/" << m_ngaysinh.m_nam << endl;
		cout << "Dia chi: " << m_diachi << endl;
	}

	virtual void nhapToanBoThongTin() = 0;
	virtual void xuatToanBoThongTin() = 0;
	virtual int tinhLuong() = 0;
};
#endif // !nhanvien_h

#ifndef nvcongnhat_h
#define nvcongnhat_h

class NVCongNhat : public NhanVien{
private:
	int m_songay;
public:
	NVCongNhat() : NhanVien() 
	{
		m_songay = 0;
	}

	NVCongNhat(const char* maso, const char* hoten, const char* gioitinh, const Ngay& ngaysinh, const char* diachi, const int& songay)
		:NhanVien(maso, hoten, gioitinh, ngaysinh, diachi)
	{
		m_songay = songay;
	}

	NVCongNhat(const NVCongNhat& nv)
		:NhanVien(nv)
	{
		m_songay = nv.m_songay;
	}

	void nhapToanBoThongTin() {
		nhapThongTinCoBan();
		cout << "Nhap so ngay lam viec: ";
		cin >> m_songay;
	}

	void xuatToanBoThongTin() {
		xuatThongTinCoBan();
		cout << "So ngay: " << m_songay << endl;
		cout << "Luong: " << tinhLuong() << endl;
	}

	int tinhLuong() {
		return 300000 * m_songay;
	}
};
#endif // !nvcongnhat_h


#ifndef nvsanxuat_h
#define nvsanxuat_h

class NVSanXuat : public NhanVien {
private:
	int m_sosanpham;
public:
	NVSanXuat() : NhanVien()
	{
		m_sosanpham = 0;
	}

	NVSanXuat(const char* maso, const char* hoten, const char* gioitinh, const Ngay& ngaysinh, const char* diachi, const int& sosanpham)
		:NhanVien(maso, hoten, gioitinh, ngaysinh, diachi)
	{
		m_sosanpham = sosanpham;
	}

	NVSanXuat(const NVSanXuat& nv)
		:NhanVien(nv)
	{
		m_sosanpham = nv.m_sosanpham;
	}

	void nhapToanBoThongTin() {
		nhapThongTinCoBan();
		cout << "Nhap so san pham: ";
		cin >> m_sosanpham;
	}

	void xuatToanBoThongTin() {
		xuatThongTinCoBan();
		cout << "So san pham: " << m_sosanpham << endl;
		cout << "Luong: " << tinhLuong() << endl;
	}

	int tinhLuong() {
		return 20000 * m_sosanpham;
	}
};
#endif // !nvcongnhat_h

#ifndef congty_h
#define congty_h

char nvcn[10] = "nvcn";
char nvsx[10] = "nvsx";

class CongTy {
private:
	cvector<NhanVien*> m_danhsach;
public:
	CongTy() {}
	~CongTy() {
		for (int i = 0; i < m_danhsach.size(); i++) {
			if (m_danhsach[i] != nullptr) {
				delete m_danhsach[i];
				m_danhsach[i] = nullptr;
			}
		}
	}

	void nhapDanhSach() {
		int n;
		cout << "Nhap so luong nhan vien: ";
		cin >> n;
		int loai = 0;
		NhanVien* nv = nullptr;
		for (int i = 0; i < n; i++) {
			cout << "Nhap loai (0: NVCongNhat, 1: NVSanXuat) : ";
			cin >> loai;
			if (loai == 0)
				nv = new NVCongNhat;
			else
				nv = new NVSanXuat;
			cin.ignore(10000, '\n');
			nv->nhapToanBoThongTin();
			m_danhsach.push_back(nv);
		}
	}

	void xuatDanhSach() {
		if (m_danhsach.size() == 0) {
			cout << "Danh sach rong" << endl;
			return;
		}

		cout << "Thong tin nhan vien co  trong cong ty: " << endl;
		for (int i = 0; i < m_danhsach.size(); i++) {
			cout << "Thong tin cua nhan vien thu : " << i << endl;
			m_danhsach[i]->xuatToanBoThongTin();
			cout << endl;
		}
	}

	int tinhTongLuong() {
		int luong = 0;
		for (int i = 0; i < m_danhsach.size(); i++) {
			luong += m_danhsach[i]->tinhLuong();
		}
		return luong;
	}

	int tinhLuongNVCN() {
		int luong = 0;
		for (int i = 0; i < m_danhsach.size(); i++) {
			NVCongNhat* p = dynamic_cast<NVCongNhat*>(m_danhsach[i]);
			if (p != nullptr)
				luong += m_danhsach[i]->tinhLuong();
		}
		return luong;
	}

	int tinhLuongNVSX() {
		int luong = 0;
		for (int i = 0; i < m_danhsach.size(); i++) {
			NVSanXuat* p = dynamic_cast<NVSanXuat*>(m_danhsach[i]);
			if (p != nullptr)
				luong += m_danhsach[i]->tinhLuong();
		}
		return luong;
	}

	void sapXepDanhSach() {
		for (int i = 0; i < m_danhsach.size() - 1; i++) {
			for (int j = 0; j < m_danhsach.size() - 1 - i; j++) {
				if (strcmp(m_danhsach[j]->layMaSo(), m_danhsach[j + 1]->layMaSo()) == 1) {
					NhanVien* p = m_danhsach[j];
					m_danhsach[j] = m_danhsach[j + 1];
					m_danhsach[j + 1] = p;
				}
			}
		}
	}

	void ghiFile(const char* ten_file) {
		ofstream fout(ten_file, ios::app | ios::binary);
		if (!fout)
			return;

		for (int i = 0; i < m_danhsach.size(); i++) {
			NVCongNhat* p = dynamic_cast<NVCongNhat*>(m_danhsach[i]);
			if (p != nullptr) {
				fout.write(::nvcn, sizeof(::nvcn));
				fout.write((char*)m_danhsach[i], sizeof(NVCongNhat));
			}
			else {
				fout.write(::nvsx, sizeof(::nvsx));
				fout.write((char*)m_danhsach[i], sizeof(NVSanXuat));
			}
		}
	}

	void docFile(const char* ten_file) {
		ifstream fin(ten_file, ios::binary);
		if (!fin)
			return;

		char loai[10];
		while (fin.eof() == false) {
			fin.read(loai, sizeof(loai));
			if (fin.eof() == true)
				return;

			if (strcmp(loai, ::nvcn) == 0) {
				NVCongNhat nvcn;
				fin.read((char*)&nvcn, sizeof(nvcn));
				m_danhsach.push_back(new NVCongNhat(nvcn));
			}
			else {
				NVSanXuat nvsx;
				fin.read((char*)&nvsx, sizeof(nvsx));
				m_danhsach.push_back(new NVSanXuat(nvsx));
			}
		}
	}

	void themNhanVien() {
		NhanVien* nv = nullptr;
		int loai = 0;
		cout << "Nhap loai (0: NVCongNhat, 1: NVSanXuat) : ";
		cin >> loai;
		if (loai == 0)
			nv = new NVCongNhat;
		else
			nv = new NVSanXuat;
		cin.ignore(10000, '\n');
		cout << "Nhap thong tin nhan vien moi: " << endl;
		nv->nhapToanBoThongTin();
		m_danhsach.push_back(nv);
		cout << "them thanh cong nhan vien" << endl;
	}
};
#endif // !congty_h


/* #include <crtdbg.h> */

void test() {
	CongTy ct;
	ct.nhapDanhSach();
	ct.xuatDanhSach();
	ct.themNhanVien();
	ct.sapXepDanhSach();
	ct.xuatDanhSach();
	cout << "Tong Luong: " << ct.tinhTongLuong() << endl;
	cout << "Luong nvcn: " << ct.tinhLuongNVCN() << endl;
	cout << "Luong nvsx: " << ct.tinhLuongNVSX() << endl;
	ct.ghiFile("nhanvien.dat");
}

void test_2() {
	CongTy ct;
	ct.docFile("nhanvien.dat");
	ct.xuatDanhSach();
	cout << "Tong Luong: " << ct.tinhTongLuong() << endl;
	cout << "Luong nvcn: " << ct.tinhLuongNVCN() << endl;
	cout << "Luong nvsx: " << ct.tinhLuongNVSX() << endl;
}
int main() {
	//freopen("input.txt", "r", stdin);
	//test();
	test_2();
	/* _CrtDumpMemoryLeaks(); */
	return 0;
}
