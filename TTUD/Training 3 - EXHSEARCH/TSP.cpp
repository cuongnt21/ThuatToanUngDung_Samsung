#include <bits/stdc++.h>
using namespace std;
#define INF 1e8
int n, m;
int path[21][21];
int minStep = INF;
int record = INF;
bool visited[21];
int teta = 0;
int x[21];
 
void Try(int k){
	for (int i=2; i<=n; i++){
		if (!visited[i] && (path[x[k-1]][i] != INF)){
			visited[i] = true;
			x[k] = i;
			teta += path[x[k-1]][x[k]];
			if (k==n){
				record = min(teta + path[x[n]][1],record);
			} else if (teta + minStep*(n-k+1) < record){
				Try(k+1);
			}
			visited[i] = false;
			teta -= path[x[k-1]][x[k]];
		}
	}
}
 
int main(){
	cin >> n >> m; 
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			if (i==j) path[i][j] = 0;
			else path[i][j] = INF;
		}
	}
	for (int t=0; t<m; t++){
		int i, j;
		cin >> i >> j;
		cin >> path[i][j];
		if( i!=j && path[i][j] < minStep){
			minStep = path[i][j];
		}
	}
	x[1] = 1;
	visited[1] = true;
	Try(2);
	cout << record;
}
