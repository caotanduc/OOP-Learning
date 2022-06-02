#include "Bai3.h"

// String.cpp
const int LIMIT_STRING_LEN = 10000;
String::String() {
	m_buffer = nullptr;
	m_size = 0;
}


String::String(const int& len) {
	m_buffer = nullptr;
	m_size = 0;
}


String::String(const char* buffer) {
	m_size = strlen(buffer);
	if (m_size == 0) {
		m_buffer = nullptr;
		return;
	}
	m_buffer = new char[m_size + 1];
	strcpy(m_buffer, buffer);
	m_buffer[m_size] = '\0';
}


String::String(const String& str) {
	m_size = str.m_size;
	if (m_size == 0) {
		m_buffer = nullptr;
		return;
	}
	m_buffer = new char[m_size + 1];
	strcpy(m_buffer, str.m_buffer);
	m_buffer[m_size] = '\0';
}


String::~String() {
	if (m_buffer != nullptr) {
		delete[] m_buffer;
		m_buffer = nullptr;
	}
	m_size = 0;
}



String& String::operator=(const String& str) {
	if (this == &str)
		return *this;


	if (m_buffer != nullptr) {
		delete[] m_buffer;
		m_buffer = nullptr;
	}

	m_size = str.m_size;
	if (m_size != 0) {
		m_buffer = new char[m_size + 1];
		strcpy(m_buffer, str.m_buffer);
		m_buffer[m_size] = '\0';
	}

	return *this;
}


int String::size() const {
	return m_size;
}


void String::push_back(const char* s) {
	*this += s;
}


const char* String::c_str() const {
	return m_buffer;
}


String& String::operator+=(const String& str) {
	bool buffer_check = (m_buffer == nullptr);
	if (buffer_check) {
		*this = str;
	}

	if (buffer_check == false && str.m_buffer != nullptr) {
		int final_size = m_size + str.m_size;
		char* temp_buffer = m_buffer;

		m_buffer = new char[final_size + 1];
		strcpy(m_buffer, temp_buffer);
		strcpy(m_buffer + m_size, str.m_buffer);
		m_buffer[final_size] = '\0';

		m_size = final_size;
		delete[] temp_buffer;
		temp_buffer = nullptr;
	}

	return *this;
}



char& String::operator[](int n) {
	if (m_buffer == nullptr || n >= m_size)
		throw invalid_argument("Index out of range!");
	return m_buffer[n];
}




bool String::operator==(const String& str) {
	return strcmp(m_buffer, str.m_buffer) == 0;
}


bool String::operator>(const String& str) {
	return strcmp(m_buffer, str.m_buffer) == 1;
}


bool String::operator<(const String& str) {
	return strcmp(m_buffer, str.m_buffer) == -1;
}


bool String::operator!=(const String& str) {
	return (*this == str) == false;
}


bool String::operator>=(const String& str) {
	return (*this < str) == false;
}


bool String::operator<=(const String& str) {
	return (*this > str) == false;
}



istream& operator>>(istream& in, String& str) {
	char temp_buffer[LIMIT_STRING_LEN];
	in.getline(temp_buffer, LIMIT_STRING_LEN);
	str = temp_buffer;
	return in;
}


ostream& operator<<(ostream& out, const String& str) {
	if (str.m_buffer == nullptr)
		throw invalid_argument("Empty String");
	out << str.m_buffer;
	return out;
}


String operator+(String s1, const String& s2) {
	return s1 += s2;
}
// end of String.cpp

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
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& lt) {
	if (this == &lt)
		return *this;

	remove_all();
	Node<T>* run = m_head;
	while (run != nullptr) {
		push_tail(run->m_data);
		run = run->m_next;
	}

	return *this;
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

template <class T>
void LinkedList<T>::print() {
	Node<T>* run = m_head;
	while (run != nullptr) {
		cout << run->m_data << "->";
		run = run->m_next;
	}
	cout << endl;
}

template <class T>
void LinkedList<T>::remove_all() {
	Node<T>* p;
	while (m_head != nullptr) {
		p = m_head;
		m_head = m_head->m_next;
		delete p;
		p = nullptr;
	}
	m_head = m_tail = nullptr;
}

//template class LinkedList<NhanVien*>;
// End of LinkedList.cpp

// Date.cpp
const int MAX_VALID_YR = 9999;
const int MIN_VALID_YR = 1800;

bool isLeap(int year)
{
	return (((year % 4 == 0) &&
		(year % 100 != 0)) ||
		(year % 400 == 0));
}

bool isValidDate(int d, int m, int y)
{
	if (y > MAX_VALID_YR || y < MIN_VALID_YR)
		return false;
	if (m < 1 || m > 12)
		return false;
	if (d < 1 || d > 31)
		return false;
	if (m == 2)
	{
		if (isLeap(y))
			return (d <= 29);
		else
			return (d <= 28);
	}

	if (m == 4 || m == 6 ||
		m == 9 || m == 11)
		return (d <= 30);

	return true;
}

int rdn(int d, int m, int y) { /* Rata Die day one is 0001-01-01 */
	if (m < 3)
		y--, m += 12;
	return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}

Date::Date() {
	m_Day = m_Month = m_Year = 0;
}

Date::Date(int day, int month, int year) {
	m_Day = day;
	m_Month = month;
	m_Year = year;
	if (isValidDate(m_Day, m_Month, m_Year) == false) {
		throw invalid_argument("Invalid Date");
	}
}

Date::Date(const Date& d) {
	m_Day = d.m_Day;
	m_Month = d.m_Month;
	m_Year = d.m_Year;
	if (isValidDate(m_Day, m_Month, m_Year) == false) {
		throw invalid_argument("Invalid Date");
	}
}

Date& Date::operator=(const Date& d) {
	if (this == &d)
		return *this;

	if (isValidDate(m_Day, m_Month, m_Year) == false) {
		throw invalid_argument("Invalid Date");
	}

	m_Day = d.m_Day;
	m_Month = d.m_Month;
	m_Year = d.m_Year;
	return *this;
}

bool Date::operator==(const Date& d) const {
	if (isValidDate(m_Day, m_Month, m_Year) == false) {
		throw invalid_argument("Invalid Date");
	}
	return (m_Day == d.m_Day) && (m_Month == d.m_Month) && (m_Year == d.m_Year);
}

bool Date::operator!=(const Date& d) const {
	if (isValidDate(m_Day, m_Month, m_Year) == false) {
		throw invalid_argument("Invalid Date");
	}
	return (*this == d) == false;
}

int Date::dateDiff(const Date& d) const {
	return rdn(m_Day, m_Month, m_Year) - rdn(d.m_Day, d.m_Month, d.m_Year);
}

istream& operator>>(istream& in, Date& d) {
	in >> d.m_Day >> d.m_Month >> d.m_Year;
	if (isValidDate(d.m_Day, d.m_Month, d.m_Year) == false) {
		throw invalid_argument("Invalid Date");
	}
	return in;
}

ostream& operator<<(ostream& out, const Date& d) {
	if (isValidDate(d.m_Day, d.m_Month, d.m_Year) == false)
		throw invalid_argument("Invalid Date");
	out << d.m_Day << "/" << d.m_Month << "/" << d.m_Year;
	return out;
}
// End of Date.cpp

// NumberString.cpp
int number_len(int n) {
	int len = 0;
	for (int i = n; i > 0; i /= 10) {
		len += 1;
	}
	return len;
}

NumberString::NumberString() {
	m_Number = 0;
}

NumberString::NumberString(const int& number) {
	m_Number = number;
	if (number_len(m_Number) > MAX_SIZE)
		throw invalid_argument("Number String is out of len");
}


NumberString::NumberString(const NumberString& num) {
	m_Number = num.m_Number;
	if (number_len(m_Number) > MAX_SIZE)
		throw invalid_argument("Number String is out of len");
}


NumberString& NumberString::operator=(const NumberString& num) {
	if (this == &num) {
		return *this;
	}

	m_Number = num.m_Number;
	if (number_len(m_Number) > MAX_SIZE)
		throw invalid_argument("Number String is out of len");
	return *this;
}

bool NumberString::operator==(const NumberString& num) const {
	return m_Number == num.m_Number;
}


bool NumberString::operator>(const NumberString& num) const {
	return m_Number > num.m_Number;
}


bool NumberString::operator<(const NumberString& num) const {
	return m_Number < num.m_Number;
}


bool NumberString::operator!=(const NumberString& num) const {
	return (*this == num) == false;
}

bool NumberString::operator>=(const NumberString& num) const {
	return (*this < num) == false;
}

bool NumberString::operator<=(const NumberString& num) const {
	return (*this > num) == false;
}

istream& operator>>(istream& in, NumberString& num) {
	int temp_number;
	in >> temp_number;
	if (number_len(temp_number) > num.MAX_SIZE) {
		throw invalid_argument("Number String is out of len");
	}
	num.m_Number = temp_number;
	return in;
}

ostream& operator<<(ostream& out, const NumberString& num) {
	if (number_len(num.m_Number) > num.MAX_SIZE) {
		throw invalid_argument("Number String is out of len");
	}
	out << num.m_Number;
	return out;
}
// End of NumberString.cpp

// NhanVien.cpp
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
	cout << "Nhap ngay sinh: ";
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
// End of NhanVien.cpp


// NVCongNhat.cpp
const long long BASIC_PAY_NVCN = 300000;

NVCongNhat::NVCongNhat()
	: NhanVien() {
	m_SoNgay = 0;
}

NVCongNhat::NVCongNhat(NumberString maso, String hoten, String gioitinh, Date ngaysinh, String diachi, long long songay)
	: NhanVien(maso, hoten, gioitinh, ngaysinh, diachi) {
	m_SoNgay = songay;
}

long long NVCongNhat::tinhLuong() {
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
// End of NVCongNhat.cpp

// NVSanXuat.cpp
const long long BASIC_PAY_NVSX = 20000;

NVSanXuat::NVSanXuat()
	: NhanVien() {
	m_SoSanPham = 0;
}

NVSanXuat::NVSanXuat(NumberString maso, String hoten, String gioitinh, Date ngaysinh, String diachi, long long sosp)
	: NhanVien(maso, hoten, gioitinh, ngaysinh, diachi) {
	m_SoSanPham = sosp;
}

long long NVSanXuat::tinhLuong() {
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

long long CongTy::tinhTongLuong() {
	long long tongluong = 0;
	Node<NhanVien*>* p = m_DanhSach.m_head;
	while (p != nullptr) {
		tongluong += p->m_data->tinhLuong();
		p = p->m_next;
	}
	return tongluong;
}

long long CongTy::tinhLuongNVSanXuat() {
	long long tongluong = 0;
	Node<NhanVien*>* p = m_DanhSach.m_head;
	while (p != nullptr) {
		NVSanXuat* ptr = dynamic_cast<NVSanXuat*>(p->m_data);
		if (ptr != nullptr)
			tongluong += p->m_data->tinhLuong();
		p = p->m_next;
	}
	return tongluong;
}

long long CongTy::tinhLuongNVCongNhat() {
	long long tongluong = 0;
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
}

bool CongTy::ghiNVFile(const String& ten_file) {
	ofstream fout(ten_file.c_str());
	if (!fout)
		return false;
	fout.write((char*)&m_DanhSach, sizeof(m_DanhSach));
	fout.close();
	return true;
}

bool CongTy::ghiNVCongNhatFile(const String& ten_file) {
	ofstream fout(ten_file.c_str());
	if (!fout)
		return false;
	LinkedList<NhanVien*> temp;
	Node<NhanVien*>* run = m_DanhSach.m_head;
	while (run != nullptr) {
		NVCongNhat* ptr = dynamic_cast<NVCongNhat*>(run->m_data);
		if (ptr != nullptr)
			temp.push_tail(ptr);
		run = run->m_next;
	}
	fout.write((char*)&temp, sizeof(temp));
	fout.close();
	return true;
}

bool CongTy::ghiNVSanXuatFile(const String& ten_file) {
	ofstream fout(ten_file.c_str());
	if (!fout)
		return false;
	LinkedList<NhanVien*> temp;
	Node<NhanVien*>* run = m_DanhSach.m_head;
	while (run != nullptr) {
		NVSanXuat* ptr = dynamic_cast<NVSanXuat*>(run->m_data);
		if (ptr != nullptr)
			temp.push_tail(ptr);
		run = run->m_next;
	}
	fout.write((char*)&temp, sizeof(temp));
	fout.close();
	return true;
}
// End of CongTy.cpp


// main: Testing
void menu() {
	CongTy ct;
	int ch = 0;
	String ten_file;
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
		cout << "9: Xuat danh sach nhan vien san xuat ra file" << endl;
		cout << "10: xuat danh sach nhan vien cong nhat ra file" << endl;
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
			cin.ignore(10000, '\n');
			cin >> ten_file;
			ct.ghiNVFile(ten_file);
			break;
		case 9:
			cout << "9: Xuat danh sach nhan vien san xuat ra file" << endl << endl;
			cout << "Nhap ten file: ";
			cin.ignore(10000, '\n');
			cin >> ten_file;
			ct.ghiNVSanXuatFile(ten_file);
			break;
		case 10:
			cout << "10: xuat danh sach nhan vien cong nhat ra file" << endl << endl;
			cout << "Nhap ten file: ";
			cin.ignore(10000, '\n');
			cin >> ten_file;
			ct.ghiNVCongNhatFile(ten_file);
			break;
		default:
			break;
		}
	} while (!quit);
}

int main() {
	menu();
	return 0;
}
