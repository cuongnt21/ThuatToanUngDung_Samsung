#include <bits/stdc++.h>
using namespace std;
int n;
// gia tri toi uu cua cai tui
int record = 0;
// gia tri hien tai cua cai tui
int sigma = 0;
// can nang con lai cua cai tui
int w;
struct item{
	// weight
	int a;
	// cost
	int c;
} x[31];
 
bool comp(item a, item b){
	return (float) a.c/a.a > (float) b.c/b.a;
}
 
void Try(int k){
	//chon mon do thu k chinh la mon do thu k trong danh ssach duoc sap xep
	int U = (w/x[k].a != 0)?1:0;
	for (int i=U; i>=0; i--){
		sigma += x[k].c * i;
		w -= x[k].a * i;
		if (k==n){
			record = max(record, sigma);
		} else {
			float g = sigma + (float) w * x[k+1].c/x[k+1].a;
			if (g > record){
				Try(k+1);
			}
		}
		w += x[k].a * i;
		sigma -= x[k].c * i;
	}
}
 
int main(){
	cin >> n >> w;
	for (int i=1; i<=n; i++){
		cin >> x[i].a >> x[i].c;
	}
	sort(x+1, x+1+n, comp);
	Try(1);
	cout << record;
}
