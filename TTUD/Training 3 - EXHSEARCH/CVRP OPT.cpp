#include <bits/stdc++.h>
using namespace std;
const long long inf = 1000000007;
int n, K, Q;
int d[13];
int c[13][13];
bool visited[13];
//long long dem = 0;
// capacity cua tung xe
int cap[6];
// number of client each truck visit
int a[6];
// xe x[i] cho hang den client i
int x[13]; 
// 
int maxU = 1;
// so luong truck rong
int remain;
///
int opt = inf;
bool subv[13];
int teta;
int record;
int minStep = inf;
int sx[13];
 
void sTry(int k, int t){
	for (int i=1; i<=n; i++){
		if (!subv[i] && x[i] == t){
			subv[i] = true;
			sx[k] = i;
			teta += c[sx[k-1]][sx[k]];
			if (k==a[t]){
				record = min(teta + c[sx[k]][0],record);
			} else if (teta + minStep*(a[t]-k+1) < record){
				sTry(k+1, t);
			}
			subv[i] = false;
			teta -= c[sx[k-1]][sx[k]];
		}
	}
}
 
// Branch and Bound xe t
int BaB(int t){
	for (int i=1; i<=n; i++){
		subv[t]=false;
	}
	teta = 0;
	record = inf;
	subv[0] = true;
	sTry(1, t);
	return record;
}
 
// xe thu i, clinent k
bool UCV(int i, int k){
	if (remain == n-k+1 && c[i] != 0 && remain != 0){
		return false;
	} else if ((!visited[k])&& (cap[i] + d[k] <= Q)){
		return true;
	} else return false;
}
 
// client k se do xe thu i nao cho den
void Try(int k){
	int U = maxU;
	for(int i=1; i<=U; i++){
		if(UCV(i,k)){
			x[k] = i;
			visited[k] = true;
			int temp1 = maxU;
			int g = (cap[i] == 0)?1:0;
			remain -= g; 
			maxU = min(K, maxU + g);
			cap[i] += d[k];
			a[i] += 1;
			if (k==n){
				int temp = 0;
				for (int t=1; t<=K; t++){
					temp += BaB(t);
					if (temp >= opt) break;
				}
				opt = min(temp, opt);
			} else {
				Try(k+1);
			}
			a[i] -= 1;
			cap[i] -= d[k];
			maxU = temp1;
			remain += g;
			visited[k] = false;
		}
	}
}
 
 
int main(){
	cin >> n >> K >> Q;
	for (int i=1; i<=n; i++){
		cin >> d[i];
	}
	for (int i=0; i<=n; i++){
		for (int j=0; j<=n; j++){
			cin >> c[i][j];
			if (c[i][j] != 0){
				minStep = min(minStep,c[i][j]);
			}
		}
	}
	remain = K;
	Try(1);
	cout << opt;
}
