#include "Bai2.h"

String::String() {
	m_buffer = nullptr;
	m_size = 0;
}

String::String(const char* buffer) {
	m_size = (int)strlen(buffer);
	m_buffer = new char[m_size + 1];
	strcpy(m_buffer, buffer);
	m_buffer[m_size] = '\0';
}

String::String(const String& str) {
	m_size = str.m_size;
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

int String::size() const {
	return m_size;
}

bool String::is_empty() const {
	return (m_buffer == nullptr || m_size == 0);
}

const char* String::c_str() const {
	return m_buffer;
}

void String::push_back(const char* c) {
	*this += c;
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


String& String::operator+=(const String& str) {
	bool check_null = is_empty();
	if (check_null) {
		*this = str;
	}

	if (check_null == false && str.is_empty() == false) {
		int final_size = m_size + str.m_size;
		char* temp_buffer = m_buffer;
		m_buffer = new char [final_size + 1];
		strcpy(m_buffer, temp_buffer);
		strcpy(m_buffer + m_size, str.m_buffer);
		m_size = final_size;
		m_buffer[m_size] = '\0';
		delete [] temp_buffer;
		temp_buffer = nullptr;
	}

	return *this;
}

char& String::operator[](int k) {
	assert(is_empty() == false && k < m_size);
	return m_buffer[k];
}


bool String::operator<(const String& str) {
	return strcmp(m_buffer, str.m_buffer) == -1;
}

bool String::operator>(const String& str) {
	return strcmp(m_buffer, str.m_buffer) == 1;
}

bool String::operator==(const String& str) {
	return strcmp(m_buffer, str.m_buffer) == 0;
}

bool String::operator<=(const String& str) {
	return (m_buffer > str.m_buffer) == false;
}

bool String::operator>=(const String& str) {
	return (m_buffer < str.m_buffer) == false;
}

bool String::operator!=(const String& str) {
	return (m_buffer == str.m_buffer) == false;
}

istream& operator>>(istream& in, String& str) {
	char c[1000];
	in.getline(c, 1000);
	str = c;
	return in;
}

ostream& operator<<(ostream& out, const String& str) {
	if (str.is_empty())
		out << "Empty string!" << endl;
	else
		out << str.m_buffer;
	return out;
}

String operator+(String s1, const String& s2) {
	return s1 += s2;
}

// sinhvien
SinhVien::SinhVien() {
	for (int i = 0; i < 3; i++) {
		m_Diem[i] = 0;
	}
}

SinhVien::SinhVien(const String& hoten, const String& maso, const String& ngaysinh, const double& bt, const double& gk, const double& ck) {
	m_HoTen = hoten;
	m_MaSo = maso;
	m_NgaySinh = ngaysinh;
	m_Diem[0] = bt;
	m_Diem[1] = gk;
	m_Diem[2] = ck;
}

SinhVien::SinhVien(const SinhVien& sv) {
	m_HoTen = sv.m_HoTen;
	m_MaSo = sv.m_MaSo;
	m_NgaySinh = sv.m_NgaySinh;
	for (int i = 0; i < 3; i++) {
		m_Diem[i] = sv.m_Diem[i];
	}
}

String SinhVien::layTen() const {
	return m_HoTen;
}

String SinhVien::layMaSo() const {
	return m_MaSo;
}

String SinhVien::layNgaySinh() const {
	return m_NgaySinh;
} 

double SinhVien::layDBT() const {
	return m_Diem[0];
}

double SinhVien::layDGK() const {
	return m_Diem[1];
}

double SinhVien::layDCK() const {
	return m_Diem[2];
}

String SinhVien::xepLoai() const {
	double tb = tinhDiemTB();
	if (tb >= 8)
		return "Gioi";
	else if (tb >= 6.5)
		return "Kha";
	else if (tb >= 5)
		return "Trung Binh";
	else if (tb >= 3.5)
		return "Yeu";
	return "Kem";
}

SinhVien& SinhVien::operator=(const SinhVien& sv) {
	if (this != &sv){
		m_HoTen = sv.m_HoTen;
		m_MaSo = sv.m_MaSo;
		m_NgaySinh = sv.m_NgaySinh;
		for (int i = 0; i < 3; i++) {
			m_Diem[i] = sv.m_Diem[i];
		}
	}

	return *this;
}

double SinhVien::tinhDiemTB() const {
	return 0.25 * m_Diem[0] + 0.25 * m_Diem[1] + 0.5 * m_Diem[2];
} 

void SinhVien::print() {
	cout << "Ho va Ten: " << m_HoTen << endl;
	cout << "MSSV: " << m_MaSo << endl;
	cout << "m_NgaySinh: " << m_NgaySinh << endl;
	cout << "Bang diem: " << endl;
	cout << "\tBai tap (25%): " << m_Diem[0] << endl;
	cout << "\tGiua ky (25%): " << m_Diem[1] << endl;
	cout << "\tCuoi ky (50%): " << m_Diem[2] << endl;
	cout << endl;
}





// cvector
template <typename T>
cvector<T>::cvector() {
	ptr = nullptr;
	sz = 0;
	capacity = 0;
}


template <typename T>
cvector<T>::cvector(int s) {
	sz = capacity = s;
	ptr = new T[sz]();
}

template <typename T>
cvector<T>::~cvector() {
	if (ptr != nullptr) {
		delete[] ptr;
		ptr = nullptr;
	}
	sz = 0;
	capacity = 0;
}

template <typename T>
cvector<T>::cvector(const cvector<T>& v) {
	sz = v.sz;
	capacity = v.capacity;
	ptr = new T[capacity]();
	for (int i = 0; i < sz; i++) {
		ptr[i] = v.ptr[i];
	}
}

template <typename T>
T& cvector<T>::operator[](int n) {
	assert(ptr != nullptr && n < capacity);
	return ptr[n];
}

template <typename T>
T cvector<T>::operator[](int n) const {
	assert(ptr != nullptr && n < capacity);
	return ptr[n];
}

template <typename T>
int cvector<T>::size() const {
	return sz;
}

template <typename T>
int cvector<T>::getCapacity() const {
	return capacity;
}

template <typename T>
void cvector<T>::reserve(int newalloc) {
	if (newalloc <= capacity)
		return;
	T* temp = ptr;
	capacity = newalloc;
	ptr = new T[capacity]();
	if (temp) {
		for (int i = 0; i < sz; i++) {
			ptr[i] = temp[i];
		}
		delete[] temp;
		temp = nullptr;
	}
}

template <typename T>
void cvector<T>::push_back(const T& elem) {
	if (sz + 1 > capacity) {
		reserve(capacity + 1);
	}
	ptr[sz++] = elem;
}


template <typename T>
void cvector<T>::print() const {
	if (ptr == nullptr) {
		cout << "there's no one at all!" << endl;
	}

	for (int i = 0; i < sz; i++) {
		cout << ptr[i] << " ";
	}

	cout << endl;
}

template <typename T>
void cvector<T>::resize(int newsize) {
	if (newsize == capacity) {
		sz = capacity;
		return;
	}
	if (newsize <= 0) {
		if (ptr != nullptr) {
			delete[] ptr;
			ptr = nullptr;
		}
		sz = 0;
		capacity = 0;
		return;
	}

	if (newsize > capacity) {
		reserve(newsize);
	}
	sz = newsize;
}

template <typename T>
cvector<T>& cvector<T>::operator=(const cvector<T>& v) {
	if (this == &v)
		return *this;

	if (ptr != nullptr) {
		delete[] ptr;
		ptr = nullptr;
	}

	sz = v.sz;
	capacity = v.capacity;
	ptr = new T[capacity]();
	for (int i = 0; i < sz; i++) {
		ptr[i] = v.ptr[i];
	}

	return *this;
}

template <typename T>
bool cvector<T>::is_increase() const {
	for (int i = 0; i < sz - 1; i++) {
		if (ptr[i] > ptr[i + 1])
			return false;
	}
	return true;
}

template <typename T>
void cvector<T>::sort(bool asc) {
	for (int i = 0; i < sz - 1; i++) {
		for (int j = 0; j < sz - i - 1; j++) {
			if (asc && ptr[j] > ptr[j + 1]) {
				T temp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = temp;
			}
			else if (asc == false && ptr[j] < ptr[j + 1]) {
				T temp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = temp;
			}
		}
	}
}

// qlsinhvien
//
QLSinhVien::QLSinhVien(const cvector<SinhVien>& ds) {
	this->ds = ds;
}
bool docFile(const String& ten_file, QLSinhVien& qlsv) {
	ifstream fin(ten_file.c_str());
	if (!fin)  
		return false;

	/* int slsv = 0; */
	/* fin >> slsv; */

	String hoten, maso, ngaysinh;
	double diem[3];
	while (fin.eof() == false) {
		fin >> hoten;
		// dòng trống thì kết thúc đọc file
		if (hoten.is_empty() == true) 
			return true;
		fin >> maso;
		fin >> ngaysinh;
		fin >> diem[0] >> diem[1] >> diem[2];
		fin.ignore(10000, '\n');
		qlsv.ds.push_back(SinhVien(hoten, maso, ngaysinh, diem[0], diem[1], diem[2]));
	}

	fin.close();
	return true;
}

bool ghiFile(const String& ten_file, const QLSinhVien& qlsv) {
	ofstream fout(ten_file.c_str());
	if (!fout)
		return false;

	/* fout << qlsv.ds.size() << endl; */
	for (int i = 0; i < qlsv.ds.size(); i++) {
		fout << qlsv.ds[i].layTen() << endl;
		fout << qlsv.ds[i].layMaSo() << endl;
		fout << qlsv.ds[i].layNgaySinh() << endl;
		fout << qlsv.ds[i].layDBT() << " " << qlsv.ds[i].layDGK() << " " << qlsv.ds[i].layDCK() << endl;
	}
	return true;
}


void QLSinhVien::print() {
	cout << "So luong sinh vien trong danh sach: " << ds.size() << endl;
	for (int i = 0; i < ds.size(); i++) {
		cout << "Sinh vien thu " << i << endl;
		ds[i].print();
	}
}

double QLSinhVien::tinhDiemTB() {
	double tb = 0;
	int n = ds.size();
	for (int i = 0; i < n; i++) {
		tb += ds[i].tinhDiemTB() / n;
	}
	return tb;
}

cvector<SinhVien> QLSinhVien::timThapHonTB() {
	double tb = tinhDiemTB();
	cvector<SinhVien> ketqua;
	for (int i = 0; i < ds.size(); i++) {
		if (ds[i].tinhDiemTB() < tb) {
			ketqua.push_back((const SinhVien)ds[i]);
		}
	}
	return ketqua;
}

bool QLSinhVien::ghiThapHonTBFile(const String& ten_file) {
	cvector<SinhVien> kq = timThapHonTB();
	return ghiFile(ten_file, QLSinhVien(kq));
}


bool QLSinhVien::themVaoDSTang(const SinhVien& sv) {
	if (ds.is_increase() == false)
		return false;
	
	ds.push_back(sv);
	return true;
}

bool QLSinhVien::ghiTangVaoFile(const String& ten_file, const SinhVien& sv) {
	if (themVaoDSTang(sv)) {
		ofstream fout(ten_file.c_str(), ios::app);
		fout << sv.layTen() << endl;
		fout << sv.layMaSo() << endl;
		fout << sv.layNgaySinh() << endl;
		fout << sv.layDBT() << " " << sv.layDGK() << " " << sv.layDCK() << endl;
	}
	return false;
}

bool QLSinhVien::ghiXepLoaiFile(const String& ten_file) {
	ofstream fout(ten_file.c_str());
	if (!fout)
		return false;

	/* fout << ds.size() << endl; */
	for (int i = 0; i < ds.size(); i++) {
		fout << ds[i].layTen() << endl;
		fout << ds[i].layMaSo() << endl;
		fout << ds[i].layNgaySinh() << endl;
		fout << ds[i].layDBT() << " " << ds[i].layDGK() << " " << ds[i].layDCK() << endl;
		fout << ds[i].xepLoai() << endl;
	}
	return true;
}

int main() {
	QLSinhVien ql;
	String danhsach = "danhsach.txt";
	String output = "output.txt";
	String tb = "trungbinh.txt";
	String xl = "xeploai.txt";
	// đọc danh sách sinh viên từ file
	if (docFile(danhsach, ql)) {
		cout << "Danh sach sinh vien doc len tu file" << endl;
		ql.print();

		// thêm sinh viên vào danh sách tăng và ghi lại vào file danhsach.txt
		SinhVien sv("Bui Anh Tuan", "104", "1/1/2000", 5, 5, 5);
		if (ql.ghiTangVaoFile(danhsach, sv)) {
			cout << "Da them sinh vien thanh cong" << endl;
			sv.print();
		}

		// ghi toàn bộ thông tin sinh viên vừa rồi (tính cả vừa thêm nếu thành công) ra file khác
		if (ghiFile(output, ql)) {
			cout << "Ghi thong tin danh sach moi vao file " << output << endl;
			cout << "Thong tin cac sinh vien trong danh sach hien tai" << endl;
			ql.print();
		}

		// ghi danh sách sinh viên có có điểm thấp hơn điểm trung bình vào file
		if (ql.ghiThapHonTBFile(tb)) {
			cout << "Da ghi thong tin sinh vien co diem thap hon diem trung binh " << ql.tinhDiemTB() << " vao file " << tb << " thanh cong." << endl;
		}

		// ghi danh sách sinh viên và xếp loại của sinh viên đó
		if (ql.ghiXepLoaiFile(xl)) {
			cout << "Da ghi thong tin va xep loai cua danh sach vao file " << xl << " thanh cong." << endl;
		}
	}
	else {
		cout << "Doc File khong thanh cong." << endl;
	}
	return 0;
}
