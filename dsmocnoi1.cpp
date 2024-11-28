#include <bits/stdc++.h>

using namespace std;

struct SinhVien {
    int masv;
    char hoten[30];
    int namsinh;
    double diemTK;
};

struct Node {
    SinhVien infor;
    Node* next;
};

typedef Node* Tro;

bool empty(Tro L) {
    return L == nullptr;
}

void create(Tro &L) {
    L = nullptr;
}

SinhVien taosv(int masv, const char* hoten, int namsinh, double diemTK) {
    SinhVien sv;
    sv.masv = masv;
    strcpy(sv.hoten, hoten);
    sv.namsinh = namsinh;
    sv.diemTK = diemTK;
    return sv;
}

void add(Tro &L, SinhVien sv) {
	Tro Q = L,
	P = new Node;
	P->infor = sv;
	P->next = nullptr;
	if(empty(L)){
		L = P;
	}
	else {
		while(Q->next!=nullptr){
			Q = Q->next; 
		}
		Q->next = P;
	}
}

void hienthisv(SinhVien sv) {
    cout << fixed;
    cout << setw(5) << right << sv.masv << " "
         << setw(30) << left << sv.hoten
         << setw(5) << left << sv.namsinh
         << setw(8) << right << setprecision(1) << sv.diemTK << endl;
}

void hienthidanhsach(Tro L) {
    if (empty(L)) {
        cout << "Danh sach rong!" << endl;
        return;
    }
    cout << "MSV   " << setw(30) << left << "Ho ten"
         << setw(5) << left << "N.Sinh   "
         << setw(10) << left << "Diem TK" << endl;
    Node* p = L;
    while (p != nullptr) {
        hienthisv(p->infor);
        p = p->next;
    }
}

int chieudai(Tro L){
	if(empty(L)){
		return 0;
	}
	int length = 0;
	Tro Q = L;
	while( Q != nullptr ){
		length++;
		Q = Q->next;
	}
	return length;
}
void taodanhsach(Tro &L){
	add(L, taosv(1001, "Tran Van Thanh", 1997, 7.5));
    add(L, taosv(1002, "Nguyen Thi Huong", 1998, 7.2));
    add(L, taosv(1003, "Nguyen Van Binh", 1996, 6.4));
    add(L, taosv(1004, "Bui Thi Hong", 1998, 8.6));
    add(L, taosv(1005, "Duong Van Giang", 1997, 6.8));
}

void timsvtheoma(Tro L, int masv) {
    if (empty(L)) {
        cout << "Danh sach rong!\n";
        return;
    }
    Tro Q = L;
    bool flag = false;
    while (Q != nullptr) {
        if (Q->infor.masv == masv) {
            hienthisv(Q->infor);
            flag = true;
            break;
        }
        Q = Q->next;
    }
    if (!flag) {
        cout << "Khong tim thay sinh vien!\n";
    }
}

int main() {
    Tro L;
    create(L);
	taodanhsach(L);
    cout << "Danh sach sinh vien:" << endl;
    hienthidanhsach(L);

    cout << "\nChieu dai danh sach: " << chieudai(L) << endl;
	cout<<"\nTim sv co ma 1001 cho ket qua: \n";
	timsvtheoma(L,1001);
//    int masvTimKiem = 1003;
//    SinhVien* sv = timkiemsv(L, masvTimKiem);
//    if (sv != nullptr) {
//        cout << "\nThong tin sinh vien co ma " << masvTimKiem << ":" << endl;
//        hienthisv(*sv);
//    } else {
//        cout << "\nKhong tim thay sinh vien co ma " << masvTimKiem << endl;
//    }

    return 0;
}
