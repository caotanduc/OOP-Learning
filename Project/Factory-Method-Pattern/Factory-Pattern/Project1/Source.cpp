/*
	Số câu làm được: 8
	Số câu chạy được: 8
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdexcept>
using namespace std;

#ifndef GIAOVIEN_H
#define GIAOVIEN_H

struct NGAYSINH {
	int ngay, thang, nam;
};

struct DIACHI {
	char* soNha;
	char* tenDuong;
	char* phuong;
	char* quan;
	char* tp;
};

class GiaoVien {
private:
	char* maGV;
	char* hoten;
	NGAYSINH ngSinh;
	DIACHI diaChi;
	double hesoLuong;
	double luongCB;
	int soNgayNghi;
public:
	GiaoVien() {
		maGV = nullptr;
		hoten = nullptr;
		ngSinh.ngay = 1;
		ngSinh.thang = 1;
		ngSinh.nam = 0;
		diaChi.soNha = nullptr;
		diaChi.tenDuong = nullptr;
		diaChi.phuong = nullptr;
		diaChi.quan = nullptr;
		diaChi.tp = nullptr;
		hesoLuong = 0;
		luongCB = 0;
		soNgayNghi = 0;
	}

	~GiaoVien() {
		if (maGV != nullptr) {
			delete[] maGV;
			maGV = nullptr;
		}

		if (hoten != nullptr) {
			delete[] hoten;
			hoten = nullptr;
		}

		if (diaChi.soNha != nullptr) {
			delete[] diaChi.soNha;
			diaChi.soNha = nullptr;
		}

		if (diaChi.tenDuong != nullptr) {
			delete[] diaChi.tenDuong;
			diaChi.tenDuong = nullptr;
		}

		if (diaChi.phuong != nullptr) {
			delete[] diaChi.phuong;
			diaChi.phuong = nullptr;
		}

		if (diaChi.quan != nullptr) {
			delete[] diaChi.quan;
			diaChi.quan = nullptr;
		}

		if (diaChi.tp != nullptr) {
			delete[] diaChi.tp;
			diaChi.tp = nullptr;
		}

	}

	const char* layMAGV() const {
		return maGV;
	}

	virtual void Nhap() {
		char temp[1000];

		cout << "Nhap ma so: ";
		cin.getline(temp, 1000);
		if (strlen(temp) != 6)
			throw invalid_argument("Ma GV khong hop le");

		for (int i = 0; i < 6; i++) {
			if (temp[i] < '0' || temp[i] > '9')
				throw invalid_argument("Ma GV khong hop le");
		}

		maGV = new char[strlen(temp)];
		strcpy(maGV, temp);
		maGV[strlen(temp)] = '\0';


		cout << "Nhap ho ten: ";
		cin.getline(temp, 1000);
		hoten = new char[strlen(temp) + 1];
		strcpy(hoten, temp);
		hoten[strlen(temp)] = '\0';

		cout << "Nhap ngay thang nam sinh (dd mm yyyy) : ";
		cin >> ngSinh.ngay >> ngSinh.thang >> ngSinh.nam;

		cin.ignore(10000, '\n');
		cout << "Nhap dia chi: " << endl;
		cout << "Nhap so nha: ";
		cin.getline(temp, 1000);
		diaChi.soNha = new char[strlen(temp) + 1];
		strcpy(diaChi.soNha, temp);
		diaChi.soNha[strlen(temp)] = '\0';

		cout << "Nhap ten duong: ";
		cin.getline(temp, 1000);
		diaChi.tenDuong = new char[strlen(temp) + 1];
		strcpy(diaChi.tenDuong, temp);
		diaChi.tenDuong[strlen(temp)] = '\0';

		cout << "Nhap phuong: ";
		cin.getline(temp, 1000);
		diaChi.phuong = new char[strlen(temp) + 1];
		strcpy(diaChi.phuong, temp);
		diaChi.phuong[strlen(temp)] = '\0';

		cout << "Nhap quan: ";
		cin.getline(temp, 1000);
		diaChi.quan = new char[strlen(temp) + 1];
		strcpy(diaChi.quan, temp);
		diaChi.quan[strlen(temp)] = '\0';

		cout << "Nhap thanh pho: ";
		cin.getline(temp, 1000);
		diaChi.tp = new char[strlen(temp) + 1];
		strcpy(diaChi.tp, temp);
		diaChi.tp[strlen(temp)] = '\0';

		cout << "Nhap he so luong: ";
		cin >> hesoLuong;
		bool check_hsl = false;
		double hsl[5] = { 4, 5.02, 5.7, 6.04, 6.38 };
		for (int i = 0; i < 5; i++)
			if (hsl[i] == hesoLuong) {
				check_hsl = true;
				break;
			}
		if (check_hsl == false) {
			throw invalid_argument("He so luong khong hop le");
		}

		cout << "Nhap luong co ban: ";
		cin >> luongCB;
		if (luongCB != 1600000)
			throw invalid_argument("Luong co ban khong hop le");

		cout << "Nhap so ngay nghi: ";
		cin >> soNgayNghi;
	}

	virtual void Xuat() {
		cout << "Ma GV: " << maGV << endl;
		cout << "Ho ten: " << hoten << endl;
		cout << "Ngay sinh: " << ngSinh.ngay << "/" << ngSinh.thang << "/" << ngSinh.nam << endl;
		cout << "Dia chi: "
			<< diaChi.soNha << ", " << diaChi.tenDuong << ", "
			<< diaChi.phuong << ", " << diaChi.quan << ", " << diaChi.tp << endl;
		cout << "He so luong: " << hesoLuong << endl;
		cout << "Luong co ban: " << luongCB << endl;
		cout << "So ngay nghi: " << soNgayNghi << endl;
	}
	virtual double TinhLuong() {
		return hesoLuong * luongCB - soNgayNghi * 100000.0;
	}
};

#endif // !GIAOVIEN_H

#ifndef GV_CHUNHIEM_H
#define GV_CHUNHIEM_H

class GV_ChuNhiem : public GiaoVien {
private:
	char* lopCN;
public:
	GV_ChuNhiem() : GiaoVien()
	{
		lopCN = nullptr;
	}

	~GV_ChuNhiem()
	{
		if (lopCN != nullptr) {
			delete[] lopCN;
			lopCN = nullptr;
		}
	}

	void Nhap() {
		GiaoVien::Nhap();
		cin.ignore(10000, '\n');
		cout << "Nhap ten lop chu nhiem: ";
		char temp[1000];
		cin.getline(temp, 1000);
		lopCN = new char[strlen(temp)];
		strcpy(lopCN, temp);
		lopCN[strlen(temp)] = '\0';
	}

	void Xuat() {
		GiaoVien::Xuat();
		cout << "Lop chu nhiem: " << lopCN << endl;
	}

	double tinhLuong() {
		return GiaoVien::TinhLuong() + 500000.0;
	}
};

#endif // !GV_CHUNHIEM_H

#ifndef MY_VECTOR_H
#define MY_VECTOR_H

template <class T>
class MyVector {
private:
	int sz;
	T* ptr;
public:
	MyVector() {
		sz = 0;
		ptr = nullptr;
	}

	~MyVector() {
		if (sz != 0 && ptr != nullptr) {
			delete[] ptr;
			ptr = nullptr;
		}
		sz = 0;
	}

	T& operator[](int n) {
		return ptr[n];
	}

	int size() const {
		return sz;
	}

	void push_back(const T& elem) {
		T* temp = ptr;
		ptr = new T[sz + 1];
		for (int i = 0; i < sz; i++)
			ptr[i] = temp[i];

		ptr[sz++] = elem;
		if (temp != nullptr) {
			delete[] temp;
			temp = nullptr;
		}
	}

	void delete_at(const int& id) {
		if (id < 0 || id >= sz)
			return;

		if (ptr == nullptr)
			return;

		if (sz - 1 == 0) {
			delete[] ptr;
			ptr = nullptr;
		}

		T* new_ptr = new T[sz - 1];
		int k = 0;
		for (int i = 0; i < id; i++)
			new_ptr[k++] = ptr[i];

		for (int i = id + 1; i < sz; i++)
			new_ptr[k++] = ptr[i];

		delete[] ptr;
		ptr = new_ptr;
		sz -= 1;
	}

	void push_id(const int& id, const T& elem) {
		if (id == sz) {
			push_back(elem);
			return;
		}

		if (ptr == nullptr)
			return;

		int k = 0;
		T* new_ptr = new T[sz + 1];
		for (int i = 0; i < id; i++) {
			new_ptr[k++] = ptr[i];
		}

		new_ptr[k++] = elem;
		for (int i = id; i < sz; i++) {
			new_ptr[k++] = ptr[i];
		}

		delete[] ptr;
		ptr = new_ptr;
		sz += 1;
	}
};

#endif

#ifndef TRUONGHOC_H
#define TRUONGHOC_H

class TruongHoc : public GiaoVien {
private:
	MyVector<GiaoVien*> dsgv;
public:
	TruongHoc() {};
	~TruongHoc() {
		for (int i = 0; i < dsgv.size(); i++) {
			if (dsgv[i] != nullptr) {
				delete dsgv[i];
				dsgv[i] = nullptr;
			}
		}
	}

	void Nhap() {
		int n;
		cout << "Nhap so luong giao vien co trong truong: ";
		cin >> n;
		int loai = 0;
		GiaoVien* gv = nullptr;
		for (int i = 0; i < n; i++) {
			cout << "Nhap loai (0: gv thuong, 1: gv chu nhiem) : ";
			cin >> loai;
			try {
				if (loai == 0)
					gv = new GiaoVien;
				else
					gv = new GV_ChuNhiem;

				cin.ignore(10000, '\n');
				gv->Nhap();
			}
			catch (invalid_argument& ia) {
				delete gv;
				gv = nullptr;
				cout << ia.what() << endl;
				continue;
			}
			dsgv.push_back(gv);
		}
	}

	void Xuat() {
		if (dsgv.size() == 0) {
			cout << "Danh sach trong." << endl;
			return;
		}

		for (int i = 0; i < dsgv.size(); i++) {
			cout << "Thong tin cua giao vien thu " << i << endl;
			dsgv[i]->Xuat();
			cout << endl;
		}
	}

	double tbLuongGVThuong() {
		double luong = 0.0;
		int n = 0;
		for (int i = 0; i < dsgv.size(); i++) {
			GV_ChuNhiem* p = dynamic_cast<GV_ChuNhiem*>(dsgv[i]);
			if (p == nullptr) {
				n += 1;
				luong += dsgv[i]->TinhLuong();
			}
		}
		if (n == 0)
			return 0;

		return luong / (double)n;
	}

	double tbLuongGVChuNhiem() {
		double luong = 0.0;
		int n = 0;
		for (int i = 0; i < dsgv.size(); i++) {
			GV_ChuNhiem* p = dynamic_cast<GV_ChuNhiem*>(dsgv[i]);
			if (p != nullptr) {
				n += 1;
				luong += dsgv[i]->TinhLuong();
			}
		}

		if (n == 0)
			return 0;
		return luong / (double)n;
	}

	void themGiaoVienTang() {
		GiaoVien* gv = nullptr;

		int loai;
		cout << "Nhap loai (0: gv thuong, 1: gv chu nhiem) : ";
		cin >> loai;
		if (loai == 0)
			gv = new GiaoVien;
		else
			gv = new GV_ChuNhiem;

		cin.ignore(10000, '\n');
		gv->Nhap();

		int id = 0;
		while (id < dsgv.size() && strcmp(dsgv[id]->layMAGV(), gv->layMAGV()) != 1) {
			id += 1;
		}

		dsgv.push_id(id, gv);
	}

	void xoaGVTheoMaSO() {
		if (dsgv.size() == 0)
			return;

		char temp[1000];
		cout << "Nhap ma so can xoa: ";
		cin.getline(temp, 1000);

		int id = 0;
		while (id < dsgv.size() && strcmp(dsgv[id]->layMAGV(), temp) != 0) {
			id += 1;
		}

		dsgv.delete_at(id);
	}
};


#endif

void menu() {
	int chon;
	bool quit = false;
	TruongHoc th;
	do
	{
		cout << "---------------------------------menu" << endl;
		cout << "1. Nhap danh sach giao vien: " << endl;
		cout << "2. Xuat danh sach giao vien: " << endl;
		cout << "3. Luong trung binh giao vien thuon: " << endl;
		cout << "4. Luong trung binh giao vien chu nhiem: " << endl;
		cout << "5. Them giao vien vao danh sach tang: " << endl;
		cout << "6. Xoa giao vien co ma so: " << endl;
		cout << "0. Thoat" << endl;
		cout << "-------------------------------------" << endl;
		cout << "Nhap lenh: ";
		cin >> chon;
		system("cls");
		switch (chon) {
		case 1:
			th.Nhap();
			break;
		case 2:
			th.Xuat();
			break;
		case 3:
			cout << th.tbLuongGVThuong() << endl;
			break;
		case 4:
			cout << th.tbLuongGVChuNhiem() << endl;
			break;
		case 5:
			th.themGiaoVienTang();
			break;
		case 6:
			cin.ignore(10000, '\n');
			th.xoaGVTheoMaSO();
			break;
		case 0:
			quit = true;
			break;
		default:
			quit = true;
		}
	} while (!quit);
}

#include <crtdbg.h>

int main() {
	freopen("input.txt", "r", stdin);
	_CrtDumpMemoryLeaks();
	menu();
	return 0;
}
