#include <bits/stdc++.h>
using namespace std;
int N, K;
int a[3001], c[3001];
int dp[3001][102];
 
int main(){
	cin >> N >> K;
	for(int i=1; i<=N; i++){
		cin >> c[i];
	}
	for(int i=1; i<=N; i++){
		cin >> a[i];
	}
	memset(dp, 0, sizeof(dp));
	dp[1][1] = c[1];
	for(int i=1; i<=N; i++){
		for(int j=1; j<=K; j++){
			for(int s=i+1; s<=min(N, i+a[i]); s++){
				if(dp[i][j] != 0){
					dp[s][j+1] = max(dp[s][j+1], dp[i][j] + c[s]);
				}
				
			}
		}
	}
	int ans = 0;
	for(int i=1; i<= K+1; i++){
		ans = max(ans, dp[N][i]);
	}
	if(ans==0) cout << -1;
	else cout << ans;
}
