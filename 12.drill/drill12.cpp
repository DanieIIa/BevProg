#include "std_lib_facilities.h"

int ga[10]{1,2,4,8,16,32,64,128,256,512};

vector<int> gv{1,2,4,8,16,32,64,128,256,512};

void f(vector<int> &v){
	vector<int> lv;
	for(int i = 0; i < v.size(); i++){
		lv.push_back(v[i]);
		cout << lv[i] << " ";
	}
	cout << endl;
	vector<int> lv2 = lv;

}
void f(int *a, int n){
	int la[10];
	for(int i = 0; i < n; i++){
		la[i] = a[i];
		cout << la[i] << " ";
	}
	cout << endl;
	int *p =  new int[10];
	p = la;
	for(int i = 0; i < n; i++){
		cout << p[i] << " ";
	}
	cout << endl;
}

int main(){

	f(ga, 10);
	int aa[10];
	for(int i = 0; i < 10; i++){
		aa[i] = 1;
		for(int j = 2; j <= i+1; j++){
			aa[i] *= j;	
		}
	}
	f(aa, 10);
	f(gv);
	vector<int> vv;
	for(int i = 0; i < 10; i++){
		vv.push_back(1);
		for(int j = 2; j <= i+1; j++){
			vv[i] *= j;	
		}
	}
	f(vv);
	return 0;
}