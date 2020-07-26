#include <bits/stdc++.h>
using namespace std;
#define inf 10001
int n, m;
int X[inf], Y[inf];
int ma [inf][inf];
 
int lcs(int i, int j){
	if ((i == 0) || (j==0)){
		return 0;
	}
	if (ma[i][j] != -1) return ma[i][j];
	int res = 0;
	if (X[i] == Y[j]){
		res = lcs(i-1, j-1) + 1;
	} else {
		res =  max(lcs(i, j-1), lcs(i-1, j));
	}
	ma[i][j] = res;
	return res;
}
 
int main(){
	cin>> n >> m;
	for (int i=1; i<=n; i++){
		cin >> X[i];
	}
	for (int i=1; i<=m; i++){
		cin >> Y[i];
	}
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			ma[i][j] = -1;
		}
	}
	cout << lcs(n, m);
}
