#include <bits/stdc++.h>
using namespace std;
int N, T, D;
int a[1001];
int t[1001];
int dp[1001][101];
 
int main(){
	cin >> N >> T >> D;
	for(int i=1; i<=N; i++){
		cin >> a[i];
	}
	for(int i=1; i<=N; i++){
		cin >> t[i];
	}
	int ans = 0;
	for (int i=1; i<=N; i++){
		for(int j=t[i]; j<=T; j++){
			for (int s=i-1; s>=max(i-D, 0); s--){
				dp[i][j] = max(dp[i][j], dp[s][j-t[i]] + a[i]);
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
}
