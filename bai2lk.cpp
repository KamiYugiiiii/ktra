#include <bits/stdc++.h>

#define MAX 10

using namespace std;

struct HangHoa{
	int mahang;
	char tenhang[10];
	char dvtinh[10];
	int dongia;
	int soluong;
	int thanhtien;
};

struct List{
	int count;
	HangHoa h[MAX];
};

bool empty(List L){
	return L.count == -1;
}

void create(List L){
	L.count = -1;
}

bool full(List L){
	return L.count == MAX -1;
}

bool add(List &L, HangHoa hh){
	if(full(L)){
		cout<<"Danh sach da day!";
		return false;
	}
	L.h[L.count] = hh;
	L.count++;
	return true;
}
HangHoa taohanghoa(int mahang, const char *th,const char *dvt, int dg, int sl, int tt){
	HangHoa hh;
	hh.mahang = mahang;
	strcpy(hh.tenhang,th);
	strcpy(hh.dvtinh,dvt);
	hh.dongia = dg;
	hh.soluong = sl;
	hh.thanhtien = tt;
	return hh;
}

void hienhang(HangHoa hh){
	cout<<fixed;
	cout<<""<<hh.mahang
		<<"     "<<hh.tenhang
		<<"     "<<hh.dvtinh
		<<"     "<<hh.dongia
		<<"     "<<hh.soluong
		<<"     "<<hh.thanhtien;
}

void hiendanhsach(List L){
	if(empty(L)){
		cout<<"Danh sach rong!";
		return;
	}
	cout<<"STT "<<"Ten Hang"<< "DvTinh"<<"DonGia"<<"SoLuong"<<"ThanhTien";
	for(int i = 0; i < L.count ; i++){
		cout<<" "<<i+1<<" ";
		hienhang(L.h[i]);
		cout<<endl;
	}
}

void input(List  &L){
	add(L, taohanghoa(2001,"Vo","Quyen",5000,20,100000));
	add(L, taohanghoa(2004,"Tay","Cai",10000,20,200000));
	add(L, taohanghoa(2005,"Vo","Lo",12000,5,60000));
	add(L, taohanghoa(2002,"But Chi","Cai",8000,50,400000));		
}
int main(){
	List L;
	create(L);
	input(L);
	hiendanhsach(L);
}