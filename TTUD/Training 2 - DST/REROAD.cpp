#include <bits/stdc++.h>
using namespace std;
int N;
 
int main(){
	cin >> N;
	int a[N];
	int c[N]={0};
	for (int i=0; i<N; i++){
		cin >> a[i];
	}
	int dem=1;
	for (int i=1; i<N; i++){
		if (a[i] != a[i-1]){
			c[i] = 1;
			dem++;
		}
	}
	int t;
	cin >> t;
	int p, b;
	while(t--){
		cin >> p >> b;
		a[p-1] = b;
		if (N == 1){
			cout << dem << endl;
		} else {
			int check;
			if (p==N){
				check = (a[p-1] != a[p-2]);
				dem += check - c[p-1];
				c[p-1] = check;
			} else if (p==1){
				check = (a[p] != a[p-1]);
				dem += check - c[p];
				c[p] = check;
			} else {
				check = (a[p-1] != a[p-2]);
				dem += check - c[p-1];
				c[p-1] = check;
				
				check = (a[p] != a[p-1]);
				dem += check - c[p];
				c[p] = check;
			}
			cout << dem << endl;
		}
		
	}
}
