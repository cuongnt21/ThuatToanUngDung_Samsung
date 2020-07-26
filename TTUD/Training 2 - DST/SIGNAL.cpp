#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n, b;
	cin >> n >> b;
	int a[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	int maxPre[n];
	maxPre[0] = a[0];
	int maxSuf[n];
	maxSuf[n-1]=a[n-1];
	for(int i=1; i<n-1; i++){
		maxPre[i] = max(a[i],maxPre[i-1]);
	}
	for(int i=n-2; i>-1; i--){
		maxSuf[i] = max(a[i],maxSuf[i+1]);
	}
	int res = -1;
	for (int i=1; i<n-1; i++){
		if (((maxPre[i-1] - a[i]) >= b) && ((maxSuf[i+1] - a[i])>= b)){
			int temp = maxPre[i-1] - a[i] + maxSuf[i+1] - a[i];
			res = max(res,temp);
		}
	}
	cout << res;
}
