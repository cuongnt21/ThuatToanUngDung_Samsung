#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[23][23];
bool visited[23] = {false};
int minStep = 2147483647;
int record = 2147483647;
int teta = 0;
int x[23] = {0};
// so luong hanh khach trong bus
int hk = 0;
// cac dia diem duoc den
bool traKhach[12] = {0};
 
// Ham tra ve xem diem den co phu hop khong
bool des(int i){
	if ( (n+1  <= i) && (i <= 2*n) && (traKhach[i-n]) ){
		return true;
	} else {
		return false;
	}
}
 
// Ham kiem ta UCV cua node thu i
bool UCV(int i){
	if (visited[i]){
		return false;
	} else {
		if ( (hk == 0) &&  (1 <= i) && (i <= n) ){
			return true;
		} else if ( (hk == k) && (des(i)) ){
			return true;
		} else if ( (0 < hk) && (hk < k) && ( ( (1 <= i) && (i <= n) ) || des(i) ) ){
			return true;
		} else {
			return false;
		}
	}
}
 
void Try(int k){
	for (int i=1; i<=2*n; i++){
		if (UCV(i)){
			visited[i] = true;
			x[k] = i;
			teta += c[x[k-1]][x[k]];
			if ((1 <= i) && (i <= n)){
				// di don khach
				hk += 1;
				traKhach[i] = true;
			} else {
				// the thi la di dua khach 
				hk -= 1;
				traKhach[i] = false;
			}
			
			if (k==2*n){
				record = min(teta + c[x[k]][0],record);
			} else if (teta + minStep*(2*n-k+1) < record){
				Try(k+1);
			}
			
			visited[i] = false;
			teta -= c[x[k-1]][x[k]];
			if ((1 <= i) && (i <= n)){
				// di don khach
				hk -= 1;
				traKhach[i] = false;
			} else {
				// the thi la di dua khach 
				hk += 1;
				traKhach[i] = true;
			}
		}
	}
}
 
int main(){
	cin >> n >> k;
	for (int i=0; i<=2*n ; i++){
		for (int j=0; j<=2*n; j++){
			cin >> c[i][j];
			if (c[i][j] != 0){
				minStep = min(minStep,c[i][j]);
			}
		}
	}
	visited[0] = true;
	Try(1);
	cout << record;
}
