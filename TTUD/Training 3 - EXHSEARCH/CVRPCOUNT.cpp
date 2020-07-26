#include <bits/stdc++.h>
using namespace std;
const long long inf = 1000000007;
int n, K, Q;
int d[11];
bool visited[11];
long long dem = 0;
// capacity cua tung xe
int c[6];
// number of client each truck visit
int a[6];
// xe x[i] cho hang den client i
int x[11]; 
// 
int maxU = 1;
// so luong truck rong
int remain;
 
// tra ve hoan vi cua a
long long hoanVi(int a){
	long long kq = 1;
	for (int i=2; i<=a; i++){
		kq = (kq*i)%inf;
	}
	return kq;
}
 
// xe thu i, clinent k
bool UCV(int i, int k){
	if (remain == n-k+1 && c[i] != 0 && remain != 0){
		return false;
	} else if ((!visited[k])&& (c[i] + d[k] <= Q)){
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
			int g = (c[i] == 0)?1:0;
			remain -= g; 
			maxU = min(K, maxU + g);
			c[i] += d[k];
			a[i] += 1;
			if (k==n){
				long long temp = 1;
				for(int j=1; j<=K; j++){
					temp *= hoanVi(a[j]);
				}
				dem += temp; 
			} else {
				Try(k+1);
			}
			a[i] -= 1;
			c[i] -= d[k];
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
	remain = K;
	Try(1);
	cout << dem;
}
