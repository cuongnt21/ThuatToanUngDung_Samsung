#include <bits/stdc++.h>
using namespace std;
int n;
int g[23][23];
bool visited[23] = {false};
int c[12][12] = {0};
int minStep = 2147483647;
int record = 2147483647;
int teta = 0;
int x[12] = {0};
 
void Try(int k){
	for (int i=1; i<=n; i++){
		if (!visited[i]){
			visited[i] = true;
			x[k] = i;
			teta += c[x[k-1]][x[k]];
			if (k==n){
				record = min(teta + c[x[k]][0],record);
			} else if (teta + minStep*(n-k+1) < record){
				Try(k+1);
			}
			visited[i] = false;
			teta -= c[x[k-1]][x[k]];
		}
	}
}
 
 
int main(){
	cin >> n;
	for (int i=0; i<=2*n ; i++){
		for (int j=0; j<=2*n; j++){
			cin >> g[i][j];
			if (g[i][j] != 0){
				minStep = min(minStep,g[i][j]);
			}
		}
	}
	int temp = 0;
	for (int i=0; i<=n; i++){
		for (int j=0; j<=n; j++){
			if (i == 0){
				c[i][j] = g[0][j];
			} else if (i==j){
				temp += g[i][i+n];
			} else {
				c[i][j] = g[i+n][j];
			}
		}
	}
	visited[0] = true;
	Try(1);
	cout << record + temp;
}
