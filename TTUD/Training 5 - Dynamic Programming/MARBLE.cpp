#include <bits/stdc++.h>
using namespace std;
int W, H, N;
struct p{
	int a;
	int b;
} x[201];
int dp[601][601];
 
int opt(int w, int h){
	if ((w==0) || (h==0)) return 0;
	if (dp[w][h] != -1) return dp[w][h];
	int res = INT_MAX;
	for(int i=1; i<=N; i++){
		if ((w<x[i].a) || (h<x[i].b)){
			res = min(res, w*h);
		} else {
			int temp = min(opt(x[i].a, h-x[i].b) + opt(w-x[i].a, h), opt(w-x[i].a, x[i].b) + opt(w, h-x[i].b));
			res = min(res, temp);
		}
	}
	dp[w][h] = res;
	return res;
}
 
int main(){
	cin >> W >> H;
	cin >> N;
	for (int i=1; i<=N; i++){
		cin >> x[i].a >> x[i].b;
	}
	memset(dp, -1, sizeof(dp));
	cout << opt(W, H);
}
