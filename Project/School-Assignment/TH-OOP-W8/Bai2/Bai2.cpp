#include "Bai2.h"

NhanVien::NhanVien() {
	maNV = "";
	hoTen = "";
	ngSinh = {};
	diaChi = "";
}

NhanVien::NhanVien(string manv, string hoten, NGSINH ngsinh, string diachi) {
	maNV = manv;
	hoTen = hoten;
	ngSinh = ngsinh;
	diaChi = diachi;
}

NhanVien::NhanVien(const NhanVien& nv) {
	maNV = nv.maNV;
	hoTen = nv.hoTen;
	ngSinh = nv.ngSinh;
	diaChi = nv.diaChi;
}


string NhanVien::layMANV() {
	return maNV;
}

string NhanVien::layHoTen() {
	return hoTen;
}

string NhanVien::layNGSINH() {
	string ngsinh = to_string(ngSinh.ngay) + "/" + to_string(ngSinh.thang) + "/" + to_string(ngSinh.nam);
	return ngsinh;
}

int NhanVien::layThangSinh() {
	return ngSinh.thang;
}

string NhanVien::layDC() {
	return diaChi;
}


void NhanVien::nhapThongTinCoBan() {
	cout << "Nhap maso: ";
	getline(cin, maNV);
	cout << "Nhap ho ten: ";
	getline(cin, hoTen);
	cout << "Nhap sinh nhat" << endl;
	cout << "Nhap ngay: ";
	cin >> ngSinh.ngay;
	cout << "Nhap thang: ";
	cin >> ngSinh.thang;
	cout << "Nhap nam: ";
	cin >> ngSinh.nam;
	cin.ignore(10000, '\n');
	cin.clear();
	cout << "Nhap dia chi: ";
	getline(cin, diaChi);
}

void NhanVien::xuatThongTinCoBan() {
	cout << "MANV: " << layMANV() << endl;
	cout << "Ho Ten: " << layHoTen() << endl;
	cout << "Ngay sinh: " << layNGSINH() << endl;
	cout << "Dia chi: " << layDC() << endl;
}

NVSanXuat::NVSanXuat() : NhanVien() {
	soSP = 0;
}

NVSanXuat::NVSanXuat(string manv, string hoten, NGSINH ngsinh, string diachi, long long sosp)
	: NhanVien(manv, hoten, ngsinh, diachi)
{
	soSP = sosp;
}

NVSanXuat::NVSanXuat(const NVSanXuat& nv)
	: NhanVien(nv) {
	soSP = nv.soSP;
}

long long NVSanXuat::tinhLuong() {
	return soSP * 20000;
}

void NVSanXuat::nhapThongTin() {
	nhapThongTinCoBan();
	cout << "Nhap so Sp: ";
	cin >> soSP;
	cin.clear();
	cin.ignore(10000, '\n');
}

void NVSanXuat::xuatThongTin() {
	xuatThongTinCoBan();
	cout << "So san pham: " << soSP << endl;
	cout << "Luong: " << tinhLuong() << endl;
}

NhanVien* NVSanXuat::saoChep() {
	NVSanXuat* p = new NVSanXuat(*this);
	return p;
}


NVCongNhat::NVCongNhat() : NhanVien() {
	soNgay = 0;
}

NVCongNhat::NVCongNhat(string manv, string hoten, NGSINH ngsinh, string diachi, long long songay)
	: NhanVien(manv, hoten, ngsinh, diachi)
{
	soNgay = songay;
}

NVCongNhat::NVCongNhat(const NVCongNhat& nv)
	: NhanVien(nv) {
	soNgay = nv.soNgay;
}

long long NVCongNhat::tinhLuong() {
	return soNgay * 300000;
}

void NVCongNhat::nhapThongTin() {
	nhapThongTinCoBan();
	cout << "Nhap so ngay: ";
	cin >> soNgay;
	cin.clear();
	cin.ignore(10000, '\n');
}

void NVCongNhat::xuatThongTin() {
	xuatThongTinCoBan();
	cout << "So Ngay cong: " << soNgay << endl;
	cout << "Luong: " << tinhLuong() << endl;
}

NhanVien* NVCongNhat::saoChep() {
	NVCongNhat* p = new NVCongNhat(*this);
	return p;
}

CongTy::CongTy() {
	ds = NULL;
	sl = 0;
}



CongTy::CongTy(const CongTy& ct) {
	sl = ct.sl;
	ds = new NhanVien * [sl];
	for (int i = 0; i < sl; i++) {
		ds[i] = ct.ds[i]->saoChep();
	}
}

CongTy::~CongTy() {
	if (ds != NULL) {
		for (int i = 0; i < sl; i++) {
			if (ds[i] != NULL) {
				delete ds[i];
				ds[i] = NULL;
			}
		}
		delete[] ds;
		ds = NULL;
	}
}

void CongTy::nhapDanhSach() {
	if (ds != NULL) {
		for (int i = 0; i < sl; i++) {
			if (ds[i] != NULL) {
				delete ds[i];
				ds[i] = NULL;
			}
		}
		delete[] ds;
		ds = NULL;
	}
	cout << "Nhap So luong: ";
	cin >> sl;
	cout << "Nhap 1: NVSanXuat, 2: NVCongNhat" << endl;
	ds = new NhanVien * [sl];
	int ty;
	for (int i = 0; i < sl; i++) {
		cout << "Nhap loai: ";
		cin >> ty;
		cin.ignore(10000, '\n');
		cin.clear();
		if (ty == 1) {
			ds[i] = new NVSanXuat;
		}
		else {
			ds[i] = new NVCongNhat;
		}
		ds[i]->nhapThongTin();
	}
}

void CongTy::xuatDanhSach() {
	if (sl == 0) {
		cout << "Cong ty chua co nhan vien" << endl;
		return;
	}

	cout << "Danh sach nhan vien" << endl;
	for (int i = 0; i < sl; i++) {
		cout << i << endl;
		ds[i]->xuatThongTin();
	}
}


long long CongTy::tongLuong() {
	long long kq = 0;
	for (int i = 0; i < sl; i++) {
		kq += ds[i]->tinhLuong();
	}
	return kq;
}


void CongTy::NVMaxLuong() {
	NhanVien* kq = NULL;
	long long luong = 0;
	for (int i = 0; i < sl; i++) {
		if (ds[i]->tinhLuong() > luong) {
			luong = ds[i]->tinhLuong();
			kq = ds[i];
		}
	}
	if (kq == NULL) {
		cout << "khong co nhan vien co luong lon nhat" << endl;
		return;
	}
	cout << "Thong tin nhan vien co luong lon nhat: " << endl;
	kq->xuatThongTin();
}


long long CongTy::tinhLuongTB() {
	return tongLuong() / sl;
}

void CongTy::timNhanVienTheoMa() {
	string ma = "";
	cout << "Nhap ma NV can tim: ";
	getline(cin, ma);
	for (int i = 0; i < sl; i++) {
		if (ds[i]->layMANV() == ma) {
			cout << "Thong tin nhan vien co ma " << ma << endl;
			ds[i]->xuatThongTin();
			return;
		}
	}

	cout << "Khong co nhan vien co ma " << ma << endl;
}

void CongTy::timNhanVienTheoTen() {
	string ten = "";
	cout << "Nhap ten nhan vien can tim kiem: ";
	getline(cin, ten);

	bool check = false;
	for (int i = 0; i < sl; i++) {
		if (ds[i]->layHoTen() == ten) {
			ds[i]->xuatThongTin();
			check = true;
		}
	}

	if (!check) {
		cout << "Khong co nhan vien co ten " << ten << " trong cong ty" << endl;
	}
}

int CongTy::nhanVienSinhTrongThang5() {
	int kq = 0;
	for (int i = 0; i < sl; i++) {
		if (ds[i]->layThangSinh() == 5) {
			kq += 1;
		}
	}
	return kq;
}


// test
int main() {
	CongTy ct;
	cout << endl << endl;
	cout << "Nhap thong tin nhan vien." << endl;
	ct.nhapDanhSach();

	cout << endl << endl;
	ct.xuatDanhSach();

	cout << "Tong luong: " << ct.tongLuong() << endl << endl;

	cout << "Luong trung binh: " << ct.tinhLuongTB() << endl << endl;

	cout << "So luong nhan vien sinh trong thang 5: " << ct.nhanVienSinhTrongThang5() << endl << endl;

	cout << "Nhan Vien co luong lon nhat" << endl;
	ct.NVMaxLuong();
	cout << endl << endl;

	cout << "Tim Nhan vien theo ma" << endl;
	ct.timNhanVienTheoMa();
	cout << endl << endl;

	cout << "Tim Nhan vien theo ten" << endl;
	ct.timNhanVienTheoTen();
	cout << endl;
	return 0;
}
