#include "CongTy.h"

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
	while (p != m_DanhSach.m_tail) {
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
