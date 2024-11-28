#include <iostream>
#include <iomanip>
#include <cstring> // Sử dụng cho strcpy

#define MAX 8

using namespace std;

// Định nghĩa cấu trúc SinhVien
struct SinhVien {
    int STT;
    int maSV;
    char hoDem[30];
    char ten[10];
    char gioiTinh[10];
    int namSinh;
    double diemTK;
};

// Định nghĩa cấu trúc list
struct list {
    int count;
    SinhVien e[MAX];
};

// Hàm tạo danh sách
void create(list &L) {
    L.count = -1;
}

// Hàm kiểm tra danh sách rỗng
bool empty(list L) {
    return L.count == -1;
}

// Hàm kiểm tra danh sách đầy
bool full(list L) {
    return L.count == MAX - 1;
}

// Hàm thêm sinh viên vào danh sách
bool add(list &L, SinhVien sv) {
    if (full(L)) {
        return false;
    }
    L.count++;
    L.e[L.count] = sv;
    return true;
}

// Hàm tạo một sinh viên
SinhVien taosv(int msv, const char *hd, const char *ten, const char *gt, int ns, double diem) {
    SinhVien sv;
    sv.maSV = msv;
    strcpy(sv.hoDem, hd);
    strcpy(sv.ten, ten);
    strcpy(sv.gioiTinh, gt);
    sv.namSinh = ns;
    sv.diemTK = diem;
    return sv;
}

// Hàm hiển thị thông tin một sinh viên
void hienthiSV(SinhVien sv) {
    cout << fixed;
    cout << setw(5) << right << sv.maSV << " "
         << setw(12) << left << sv.hoDem
         << setw(7) << left << sv.ten
         << setw(7) << left << sv.gioiTinh
         << setw(5) << left << sv.namSinh
         << setw(8) << right << setprecision(1) << sv.diemTK << endl;
}

// Hàm hiển thị danh sách sinh viên
void hienthiDs(list L) {
    if (empty(L)) {
        cout << "Danh sach rong!" << endl;
        return;
    }
    cout << setw(6) << left << "MSV"
         << setw(12) << left << "Ho dem"
         << setw(6) << left << "Ten"
         << setw(9) << left << "G. Tinh"
         << setw(8) << left << "N.Sinh"
         << setw(10) << left << "Diem TK" << endl;
    for (int i = 0; i <= L.count; i++) {
        hienthiSV(L.e[i]);
    }
}

// Hàm nhập danh sách sinh viên
void input(list &L) {
    add(L, taosv(1001, "Tran Van", "Thanh", "Nam", 1997, 7.5));
    add(L, taosv(1002, "Nguyen Thi", "Huong", "Nu", 1998, 7.2));
    add(L, taosv(1003, "Nguyen Van", "Binh", "Nam", 1996, 6.4));
    add(L, taosv(1004, "Bui Thi", "Hong", "Nu", 1998, 8.6));
    add(L, taosv(1005, "Duong Van", "Giang", "Nam", 1997, 6.8));
}

// Hàm xóa sinh viên đầu tiên trong danh sách
void xoaSVdau(list &L) {
    if (empty(L)) {
        cout << "\nDanh sach rong" << endl;
        return;
    }
    for (int i = 0; i < L.count; i++) {
        L.e[i] = L.e[i + 1];
    }
    L.count--;
}

// Hàm chèn sinh viên vào vị trí k trong danh sách
bool insert(list &L, int k, SinhVien X) {
    if (k <= L.count + 1 && k > 0 && !full(L)) {
        for (int i = L.count; i >= k - 1; i--) {
            L.e[i + 1] = L.e[i];
        }
        L.e[k - 1] = X;
        L.count++;
        return true;
    } else {
        return false;
    }
}

// Hàm chèn sinh viên vào vị trí thứ 3 trong danh sách
void chenSVvaovt3(list &L) {
    SinhVien sv = taosv(1006, "Le Thi", "Doan", "Nu", 1998, 7.6);
    if (insert(L, 3, sv)) {
        cout << "\nChen thanh cong!" << endl;
        cout << "\n\nDanh sach sau khi chen: " << endl;
        hienthiDs(L);
    } else {
        cout << "\nChen khong thanh cong" << endl;
    }
}

// Hàm sắp xếp danh sách sinh viên theo tên
void SXTheoTen(list &L) {
    int m;
    SinhVien tg;
    for (int i = 0; i <= L.count; i++) {
        m = i;
        for (int j = i + 1; j <= L.count; j++) {
            if (strcmp(L.e[j].ten, L.e[m].ten) < 0) {
                m = j;
            }
        }
        tg = L.e[i];
        L.e[i] = L.e[m];
        L.e[m] = tg;
    }
}

// Hàm sửa thông tin sinh viên dựa trên mã sinh viên
bool suaSV(list &L, int maSV, SinhVien svMoi) {
    for (int i = 0; i <= L.count; i++) {
        if (L.e[i].maSV == maSV) {
            L.e[i] = svMoi;
            return true;
        }
    }
    return false;
}

int main() {
    list L;
    create(L);
    input(L);
    cout << "Danh sach sinh vien:\n";
    hienthiDs(L);

    cout << "\nXoa sinh vien dau tien:\n";
    xoaSVdau(L);
    hienthiDs(L);

    cout << "\nChen sinh vien vao vi tri thu 3:\n";
    chenSVvaovt3(L);

    cout << "\nDanh sach sau khi sap xep theo ten:\n";
    SXTheoTen(L);
    hienthiDs(L);

    // Sửa thông tin sinh viên
    SinhVien svMoi = taosv(1003, "Nguyen Van", "Anh", "Nam", 1996, 7.0);
    if (suaSV(L, 1003, svMoi)) {
        cout << "\nSua thanh cong sinh vien co maSV 1003!\n";
    } else {
        cout << "\nKhong tim thay sinh vien co maSV 1003!\n";
    }
    hienthiDs(L);

    return 0;
}
