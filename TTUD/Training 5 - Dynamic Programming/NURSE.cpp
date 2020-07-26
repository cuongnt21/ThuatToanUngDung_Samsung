#include <bits/stdc++.h>
using namespace std;
int N, K1, K2;
int dp[2][1001];
 
 
int main(){
	cin >> N >> K1 >> K2;
	dp[0][0] = dp[1][0] = 1;
	for (int i=1; i<=N;i++){
		dp[0][i] = dp[1][i-1];
		for(int d = i-K1; d>= max(0, i-K2); d--){
			dp[1][i] += dp[0][d];
		} 
	}
	
	cout << dp[0][N] + dp[1][N]%1000000007;	
}
