#include <bits/stdc++.h>
using namespace std;
int N, M;
int c[17] = {0};
int A[17][17] = {0};
int result = 2147483647;
//Luu tru mon thu i se hoc tai ky nao
int x[17] = {2147483647};
// Luu tru load cua cac period
int load[6] = {0};
//upper branhc
int upper[17] = {0};
// lower branch
int lower[17] = {0};
 
//// kiem tra UCV cho ky i mon hoc k
bool UCV(int i, int k){
	for (int j=1; j<k; j++){
		if ((A[j][k] == 1) && ( i <= x[j]) ){
			return false;
		}
		if ((A[k][j] == 1) && ( i >= x[j]  )){
			return false;
		}
	}
	return true;
}

void Try(int k){
	int L = 1 + lower[k];
	int U = M - upper[k];
	for (int i=L; i<=U; i++){
		if (UCV(i,k)){
			x[k] = i;
			load[i] += c[k];
			if (k==N){
				result = min(result, *max_element(load, load+M+1));
			} else {
				Try(k+1);
			}
			load[i] -= c[k];
		}
	}
}
 
int main(){
	cin >> N >> M;
	for (int i=1; i<=N; i++){
		cin >> c[i];
	}
	for (int i=1; i<=N; i++){
		for (int j=1; j<=N; j++){
			cin >> A[i][j];
			if (A[i][j] == 1){
				upper[i] = 1;
				lower[j] = 1;
			}
		}
	}
	Try(1);
	cout << result;
}
