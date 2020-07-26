#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000001];
 
int main(){
	cin >> n;
	for (int i=0; i<n;i++){
		cin >> a[i];
	}
	int maxR = a[0];
	// 
	int b = a[0];
	for (int i=1; i<n; i++){
		b = max(b + a[i], a[i]);
		maxR = max(maxR, b);
	}
	cout << maxR;
}
