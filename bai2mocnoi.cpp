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

bool empty(Tro L){
	return L == nullptr;
}

void create(Tro &L){
	L = nullptr;
}

void hienthisv(SinhVien sv){
	cout<<fixed;
	cout<<setw(10)<<left<<sv.masv
		<<setw(10)<<left<<sv.hoten
		<<setw(10)<<left<<sv.namsinh
		<<setw(10)<<left<<sv.diemTK<<endl;
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

SinhVien taosv(int masv,const char *hoten, int namsinh, double diemTK){
	SinhVien sv;
	sv.masv = masv;
	strcpy(sv.hoten,hoten);
	sv.namsinh = namsinh;
	sv.diemTK = diemTK;
	return sv;
}

void hienthids(Tro L){
	if(empty(L)){
		cout<<"Danh sach rong!";
		return;
	}
	Tro Q = L;
	while(Q!=nullptr){
		hienthisv(Q->infor);
		Q = Q->next;
	}
	
}

void nhapds(int n, Tro &L) {
    Tro Q = L;
    for (int i = 0; i < n; i++) {
        Tro P = new Node;
        SinhVien sv;
        
        // Input student information
        cout << "Sinh vien so " << i + 1 << endl;
        cout << "Ma sv: "; cin >> sv.masv;
        cin.ignore(); // ignore the leftover newline character
        cout << "Ho ten: "; cin.getline(sv.hoten, 30);
        cout << "Nam sinh: "; cin >> sv.namsinh;
        cout << "diemTK: "; cin >> sv.diemTK;
        
        // Assign student info to node
        P->infor = sv;
        P->next = nullptr;
        
        // Link the node into the list
        if (Q == nullptr) {
            L = P;
        } else {
            Q->next = P;
        }
        Q = P;
    }
}

void timdiemcao(Tro L){
	if(empty(L)){
		cout<<"Danh sach rong!";
		return;
	}
	Tro Q = L;
	while(Q!=nullptr){
		if(Q->infor.diemTK > 6.5){
			hienthisv(Q->infor);
		}
		Q = Q->next;
	}
}
void chensv(int k,Tro &L, SinhVien sv){
	Tro P = new Node, Q = L;
	P->infor = sv;
	P->next = nullptr;
	if(empty(L)){
		L = P;
		return;
	}
	for(int i=0  ; i < k-1 ; i++){
		Q = Q->next;
	}
	P->next = Q->next;
	Q->next = P;
}
int main(){
	Tro L;
	create(L);
	int n;
//	do{
//		cout<<"Nhap so luong them moi(trong khoang tu 1 den 5): ";
//		cin>>n;
//	} while (n < 0 || n > 5);
	add(L,taosv(1,"aaa",22,9));
	add(L,taosv(2,"bbb",22,0));
	add(L,taosv(3,"abc",99,10));
	hienthids(L);
	cout<<"Danh sach cac sv diemTk> 6.5: \n";
	timdiemcao(L);
}