#include "Bai2.h"

char NVCN[50] = "NVCongNhat";
char NVSX[50] = "NVSanXuat";

// Node.cpp
template <class T>
Node<T>::Node() {
	m_next = nullptr;
}

template <class T>
Node<T>::Node(const T& data) {
	m_data = data;
	m_next = nullptr;
}

//template class Node<NhanVien*>;
// End of Node.cpp

// LinkedList.cpp
template <class T>
LinkedList<T>::LinkedList() {
	m_head = nullptr;
	m_tail = nullptr;
}


template <class T>
LinkedList<T>::~LinkedList() {
	Node<T>* p;
	while (m_head != nullptr) {
		p = m_head;
		m_head = m_head->m_next;
		delete p;
		p = nullptr;
	}

	m_head = m_tail = nullptr;
}

template <class T>
int LinkedList<T>::length() const {
	int len = 0;
	Node<T>* run = m_head;
	while (run != nullptr) {
		run = run->m_next;
		len += 1;
	}
	return len;
}

template <class T>
bool LinkedList<T>::is_empty() const {
	return m_head == nullptr;
}

template <class T>
void LinkedList<T>::push_head(const T& data) {
	Node<T>* p = new Node<T>(data);
	if (m_head == nullptr) {
		m_head = m_tail = p;
	}
	else {
		p->m_next = m_head;
		m_head = p;
	}
}


template <class T>
void LinkedList<T>::push_tail(const T& data) {
	Node<T>* p = new Node<T>(data);
	if (m_head == nullptr) {
		m_head = m_tail = p;
		return;
	}
	else {
		m_tail->m_next = p;
		m_tail = p;
	}
}


template <class T>
void LinkedList<T>::pop_head() {
	if (is_empty() == false)
		return;

	if (m_head == m_tail) {
		delete m_head;
		m_head = m_head = nullptr;
	}
	else {
		Node<T>* tar = m_head;
		m_head = m_head->m_next;
		delete tar;
		tar = nullptr;
	}
}


template <class T>
void LinkedList<T>::pop_tail() {
	if (is_empty() == false)
		return;

	if (m_head == m_tail) {
		delete m_head;
		m_head = m_tail = nullptr;
	}
	else {
		Node<T>* temp = m_head;
		while (temp->m_next != m_tail) {
			temp = temp->m_next;
		}

		delete m_tail;
		m_tail = temp;
		m_tail->m_next = nullptr;
	}
}


//template class LinkedList<NhanVien*>;
// End of LinkedList.cpp

int number_len(int n) {
	int len = 0;
	for (int i = n; i > 0; i /= 10) {
		len += 1;
	}
	return len;
}



NhanVien::NhanVien(int manv, const char* hoten, const char* gioitinh, const char* ngaysinh, const char* diachi) {
	m_MaNV = manv;
	strcpy(m_HoTen, hoten);
	m_HoTen[strlen(hoten)] = '\0';
	strcpy(m_GioiTinh, gioitinh);
	m_GioiTinh[strlen(gioitinh)] = '\0';
	strcpy(m_NgaySinh, ngaysinh);
	m_NgaySinh[strlen(ngaysinh)] = '\0';
	strcpy(m_DiaChi, diachi);
	m_DiaChi[strlen(diachi)] = '\0';
}

int NhanVien::layMaNV() {
	return m_MaNV;
}


void NhanVien::nhapThongTinCoBan() {
	cout << "Nhap ma so nhan vien: ";
	cin >> m_MaNV;
	if (number_len(m_MaNV) > 5)
		throw invalid_argument("invalid id");
	cin.ignore(5000, '\n');
	cout << "Nhap ho ten: ";
	cin.getline(m_HoTen, 50);
	cout << "Nhap gioi tinh: ";
	cin.getline(m_GioiTinh, 50);
	cout << "Nhap ngay sinh: ";
	cin.getline(m_NgaySinh, 50);
	if (strcmp(m_GioiTinh, "nam") == 0) {
		double tuoi = tinhTuoi(2022);
		if (tuoi < 18 || tuoi > 60)
			throw invalid_argument("Invalid Age for male");
	}
	else {
		double tuoi = tinhTuoi(2022);
		if (tuoi < 18 || tuoi > 55)
			throw invalid_argument("Invalid Age for female");
	}
	cout << "Nhap dia chi: ";
	cin.getline(m_DiaChi, 50);
}

void NhanVien::xuatThongTinCoBan() {
	cout << "MSNV: " << m_MaNV << endl;
	cout << "Ho ten: " << m_HoTen << endl;
	cout << "Gioi tinh: " << m_GioiTinh << endl;
	cout << "Ngay sinh: " << m_NgaySinh << endl;
	cout << "Dia chi: " << m_DiaChi << endl;
	cout << "Tuoi: " << tinhTuoi(2022) << endl;
}

double NhanVien::tinhTuoi(const int& cy) {
	string y = "";
	for (int i = strlen(m_NgaySinh) - 4; i < strlen(m_NgaySinh); i++)
		y += m_NgaySinh[i];
	return cy - (int)stoi(y);
}
// End of NhanVien.cpp


// NVCongNhat.cpp
const int BASIC_PAY_NVCN = 300000;

NVCongNhat::NVCongNhat()
	: NhanVien() {
	m_SoNgay = 0;
}

NVCongNhat::NVCongNhat(int maso, const char* hoten, const char* gioitinh, const char* ngaysinh, const char* diachi, int songay)
	: NhanVien(maso, hoten, gioitinh, ngaysinh, diachi) {
	m_SoNgay = songay;
}

int NVCongNhat::tinhLuong() {
	return m_SoNgay * BASIC_PAY_NVCN;
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

NVCongNhat::NVCongNhat(const NVCongNhat& nv) 
	: NhanVien(nv) 
{
	m_SoNgay = nv.m_SoNgay;
}

// End of NVCongNhat.cpp

// NVSanXuat.cpp
const int BASIC_PAY_NVSX = 20000;

NVSanXuat::NVSanXuat()
	: NhanVien() {
	m_SoSanPham = 0;
}

NVSanXuat::NVSanXuat(int maso, const char* hoten, const char* gioitinh, const char* ngaysinh, const char* diachi, int sosp)
	: NhanVien(maso, hoten, gioitinh, ngaysinh, diachi) {
	m_SoSanPham = sosp;
}

int NVSanXuat::tinhLuong() {
	return m_SoSanPham * BASIC_PAY_NVSX;
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

NVSanXuat::NVSanXuat(const NVSanXuat& nv)
	: NhanVien(nv)
{
	m_SoSanPham = nv.m_SoSanPham;
}

// End of NVSanXuat.cpp

// CongTy.cpp
CongTy::CongTy(const CongTy& ct) {
	m_DanhSach = ct.m_DanhSach;
}

CongTy::~CongTy() {
	Node<NhanVien*>* p;
	while (m_DanhSach.m_head != nullptr) {
		p = m_DanhSach.m_head;
		m_DanhSach.m_head = m_DanhSach.m_head->m_next;
		delete p->m_data;
		p->m_data = nullptr;
		delete p;
		p = nullptr;
	}
}

void CongTy::nhapDanhSach() {
	int n;
	cout << "Nhap so luong nhan vien: ";
	cin >> n;
	int ty = 0;
	while (n--) {
		cout << "0: NVSanXuat, 1: NVCongNhat" << endl;
		cin >> ty;
		NhanVien* nv;
		if (ty == 0)
			nv = new NVSanXuat;
		else
			nv = new NVCongNhat;
		nv->nhapThongTin();
		m_DanhSach.push_tail(nv);
	}
}


void CongTy::xuatDanhSach() {
	cout << "Thong tin danh sach nhan vien: " << endl;
	Node<NhanVien*>* p = m_DanhSach.m_head;
	while (p != nullptr) {
		p->m_data->xuatThongTin();
		p = p->m_next;
	}
}

int CongTy::tinhTongLuong() {
	int tongluong = 0;
	Node<NhanVien*>* p = m_DanhSach.m_head;
	while (p != nullptr) {
		tongluong += p->m_data->tinhLuong();
		p = p->m_next;
	}
	return tongluong;
}

int CongTy::tinhLuongNVSanXuat() {
	int tongluong = 0;
	Node<NhanVien*>* p = m_DanhSach.m_head;
	while (p != nullptr) {
		NVSanXuat* ptr = dynamic_cast<NVSanXuat*>(p->m_data);
		if (ptr != nullptr)
			tongluong += p->m_data->tinhLuong();
		p = p->m_next;
	}
	return tongluong;
}

int CongTy::tinhLuongNVCongNhat() {
	int tongluong = 0;
	Node<NhanVien*>* p = m_DanhSach.m_head;
	while (p != nullptr) {
		NVCongNhat* ptr = dynamic_cast<NVCongNhat*>(p->m_data);
		if (ptr != nullptr)
			tongluong += p->m_data->tinhLuong();
		p = p->m_next;
	}
	return tongluong;
}

void CongTy::sapXepTang() {
	Node<NhanVien*>* p = m_DanhSach.m_head;
	while (p && p != m_DanhSach.m_tail) {
		Node<NhanVien*>* q = p->m_next;
		while (q != nullptr) {
			if (q->m_data->layMaNV() < p->m_data->layMaNV()) {
				NhanVien* nv = p->m_data;
				p->m_data = q->m_data;
				q->m_data = nv;
			}
			q = q->m_next;
		}
		p = p->m_next;
	}
}

void CongTy::themNhanVien(NhanVien* nv) {
	m_DanhSach.push_tail(nv);
	string ten_file;
	cout << "Nhap ten file: ";
	cin >> ten_file;
	ofstream fout(ten_file, ios::app | ios::binary);
	if (!fout)
		return;
	NVCongNhat* p = dynamic_cast<NVCongNhat*>(nv);
	size_t sz = sizeof(NVCongNhat);
	if (p != nullptr)
		fout.write(::NVCN, sizeof(::NVCN));
	else {
		fout.write(::NVSX, sizeof(::NVCN));
		sz = sizeof(NVSanXuat);
	}

	fout.write((char*)nv, sz);
	fout.close();
}

bool CongTy::ghiNVFile(const string& ten_file) {
	ofstream fout(ten_file, ios::app | ios::binary);
	if (!fout)
		return false;

	Node<NhanVien*>* run = m_DanhSach.m_head;
	while (run != nullptr) {
		NVCongNhat* p = dynamic_cast<NVCongNhat*>(run->m_data);
		if (p != nullptr) {
			fout.write(::NVCN, sizeof(::NVCN));
			fout.write((char*)run->m_data, sizeof(NVCongNhat));
		}
		else {
			fout.write(::NVSX, sizeof(::NVCN));
			fout.write((char*)run->m_data, sizeof(NVSanXuat));
		}
		run = run->m_next;
	}
	fout.close();
	return true;
}

bool CongTy::docNVFile(const string& ten_file) {
	ifstream fin(ten_file, ios::binary);
	if (!fin)
		return false;

	char loai[50];
	NhanVien* nv = nullptr;
	while (!fin.eof()) {
		fin.read(loai, sizeof(loai));
		if (fin.eof())
			return true;
		if (strcmp(loai, ::NVCN) == 0) {
			NVCongNhat nvcn;
			fin.read((char*)&nvcn, sizeof(NVCongNhat));
			m_DanhSach.push_tail(new NVCongNhat(nvcn));
		}
		else {
			NVSanXuat nvsx;
			fin.read((char*)&nvsx, sizeof(NVSanXuat));
			m_DanhSach.push_tail(new NVSanXuat(nvsx));
		}
	}
	fin.close();
	return true;
}



void CongTy::timNhanVienCoLuongLonNhat() {
	LinkedList<NhanVien*> ds;
	int luongLonNhat = 0;
	Node<NhanVien*>* run = m_DanhSach.m_head;
	while (run != nullptr) {
		luongLonNhat = (run->m_data->tinhLuong() > luongLonNhat ? run->m_data->tinhLuong() : luongLonNhat);
	}

	run = m_DanhSach.m_head;
	while (run != nullptr) {
		if (run->m_data->tinhLuong() == luongLonNhat) {
			ds.push_tail(run->m_data);
		}
	}



	cout << "Thong tin cua nhung nhan vien co luong lon nhat: " << endl;
	run = ds.m_head;
	while (run != nullptr) {
		run->m_data->xuatThongTin();
	}


	while (m_DanhSach.m_head != nullptr) {
		run = ds.m_head;
		ds.m_head = ds.m_head->m_next;
		delete run->m_data;
		run->m_data = nullptr;
		delete run;
		run = nullptr;
	}
	
}

bool CongTy::luongLonHonTrungBinh(const string& ten_file) {
	int luongtb = tinhTongLuong() / m_DanhSach.length();
	ofstream fout(ten_file, ios::app | ios::binary);
	if (!fout)
		return false;

	Node<NhanVien*>* run = m_DanhSach.m_head;
	while (run != nullptr) {
		if (run->m_data->tinhLuong() >= luongtb) {
			size_t sz = sizeof(NVCongNhat);
			NVCongNhat* p = dynamic_cast<NVCongNhat*>(run->m_data);
			if (p != nullptr)
				fout.write(::NVCN, sizeof(::NVCN));
			else {
				fout.write(::NVSX, sizeof(::NVSX));
				sz = sizeof(NVSanXuat);
			}
			fout.write((char*)run->m_data, sz);
		}
	}
	fout.close();
	return true;
}

// End of CongTy.cpp


// main: Testing
void menu() {
	CongTy ct;
	int ch = 0;
	string ten_file;
	bool quit = false;
	do {
		cout << "====================================" << endl;
		cout << "MENU :" << endl;
		cout << "1: Nhap danh sach" << endl;
		cout << "2: Xuat danh sach" << endl;
		cout << "3: Sap xep theo ma so" << endl;
		cout << "4: Them nhan vien" << endl;
		cout << "5: Tong tien luong nhan vien" << endl;
		cout << "6: Tong tien NV San Xuat" << endl;
		cout << "7: Tong tien NV Cong Nhat" << endl;
		cout << "8: Xuat danh sach tat ca nhan vien ra file" << endl;
		cout << "9: Doc danh sach nhan vien tu file" << endl;
		cout << "10: Ghi danh sach nhan vien co luong lon hon luong trung binh" << endl;
		cout << "0: Thoat" << endl;
		cout << "=================X===================" << endl;
		cout << "Nhap lua chon: ";
		cin >> ch;
		system("cls");
		switch (ch)
		{
			system("cls");
		case 0:
			quit = true;
			break;
		case 1:
			cout << "1: Nhap danh sach" << endl << endl;
			try {
				ct.nhapDanhSach();
			}
			catch (invalid_argument& ia) {
				cerr << "Error: " << ia.what() << endl;
			}
			break;
		case 2:
			cout << "2: Xuat danh sach" << endl << endl;
			try {
				ct.xuatDanhSach();
			}
			catch (invalid_argument& ia) {
				cerr << "Error: " << ia.what() << endl;
			}
			break;
		case 3:
			cout << "3: Sap xep theo ma so" << endl << endl;
			try {
				ct.sapXepTang();
			}
			catch (invalid_argument& ia) {
				cerr << "Error: " << ia.what() << endl;
			}

			break;
		case 4:
			cout << "4: Them nhan vien" << endl << endl;
			NhanVien* nv;
			cout << "0: NVSanXuat, 1: NVCongNhat" << endl;
			int ty;
			cout << "Nhap loai: " << endl;
			cin >> ty;
			if (ty == 0)
				nv = new NVSanXuat;
			else
				nv = new NVCongNhat;
			try {
				nv->nhapThongTin();
				ct.themNhanVien(nv);
			}
			catch (invalid_argument& ia) {
				cerr << "Error: " << ia.what() << endl;
			}
			break;
		case 5:
			cout << "Tong luong nhan vien: " << ct.tinhTongLuong() << endl;
			break;
		case 6:
			cout << "Tong luong nhan vien san xuat: " << ct.tinhLuongNVSanXuat() << endl;
			break;
		case 7:
			cout << "Tong luong nhan vien cong nhat: " << ct.tinhLuongNVCongNhat() << endl;
			break;
		case 8:
			cout << "8: Xuat danh sach tat ca nhan vien ra file" << endl << endl;
			cout << "Nhap ten file: ";
			cin.ignore(5000, '\n');
			cin >> ten_file;
			ct.ghiNVFile(ten_file);
			break;
		case 9:
			cout << "9: Doc danh sach nhan vien len tu file: " << endl << endl;
			cout << "Nhap ten file: ";
			cin.ignore(5000, '\n');
			cin >> ten_file;
			if (ct.docNVFile(ten_file)) {
				cout << "Doc danh sach thanh cong: ";
			}
			break;
		case 10:
			cout << "10: Ghi danh sach nhan vien co luong trung binh vao file" << endl << endl;
			cout << "Nhap ten file: ";
			cin.ignore(5000, '\n');
			cin >> ten_file;
			ct.ghiNVFile(ten_file);
			if (ct.luongLonHonTrungBinh(ten_file)) {
				cout << "Ghi vao file thanh cong." << endl;
			}
			break;
		default:
			break;
		}
	} while (!quit);
}

#include <crtdbg.h>
int main() {
	//freopen("input.txt", "r", stdin);
	menu();
	_CrtDumpMemoryLeaks();
	return 0;
}
