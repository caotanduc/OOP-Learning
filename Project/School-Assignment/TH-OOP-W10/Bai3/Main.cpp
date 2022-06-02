#include "CongTy.h"

void menu() {
    CongTy ct;
    int ch, item, index;
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
