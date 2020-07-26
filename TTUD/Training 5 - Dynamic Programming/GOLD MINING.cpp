#include <bits/stdc++.h>
using namespace std;
#define inf 100001
int n, L1, L2;
int a[inf];
int dp[inf];
 
int gm(int i){
	if (dp[i] != -1) return dp[i];
	int temp = 0;
	for (int j=L1; j <= L2; j++){
		if (i+j <= n){
			temp = max(temp, gm(i+j));
		}
	}
	dp[i] = temp + a[i];
	return dp[i];
}
 
int main(){
	cin >> n;
	cin >> L1 >> L2;
	for (int i=1; i<=n; i++){
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));
	int res = 0;
	for(int i=1; i<=n; i++){
		res = max(res, gm(i));
	}
	cout << res;
}
