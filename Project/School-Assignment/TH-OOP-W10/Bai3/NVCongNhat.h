#ifndef NHAN_VIEN_CONG_NHAT_H
#define NHAN_VIEN_CONG_NHAT_H

#include "NhanVien.h"

class NVCongNhat : public NhanVien {
private:
	long long m_SoNgay;
public:
	NVCongNhat();
	NVCongNhat(NumberString, String, String, Date, String, long long);

	long long tinhLuong();
	void nhapThongTin();
	void xuatThongTin();
};

#endif // NHAN_VIEN_CONG_NHAT_H
