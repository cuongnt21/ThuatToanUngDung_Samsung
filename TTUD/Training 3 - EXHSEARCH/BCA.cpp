#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
int n, m, k;
//gv vec[i] co the day cac mon trong vector
vector <int> vec[11];
// conflict matrix
bool A[31][31];
// Luu tru weight cua cac giao vien
int w[11] = {0};
// x[i] day mon hoc thu i
int x[31] = {0};
//
int result = INF;
 
// giao vien i, mon hoc t
bool conflict(int i, int t){
	for (int j=1; j<t; j++){
		if (x[j] == i){
			if (A[j][t]){
				return false;
			}
		}
	}
	return true;
}
 
bool isTeach(int i, int t){
	for (int j=0; j<vec[i].size(); j++){
		if (vec[i][j] == t){
			return true;
		}
	}
	return false;
}
 
 
// Ham tim UCV: giao vien i, mon hoc t
bool UCV(int i, int t){
	if ( (isTeach(i,t)) && conflict(i,t) ){
		return true;
	} else {
		return false;
	}
}
 
// Tim nguoi cho mon hoc thu t
void Try(int t){
	for (int i=1; i<=m; i++){
		if (UCV(i,t)){
			x[t] = i;
			w[i] += 1;
			int g = *max_element(w,w+m+1);
			if (t==n){
				result = min(result,g);
			} else if (g < result) {
				Try(t+1);
			}
			w[i] -= 1;
		}
	}
}
 
int main(){
	cin >> m >> n;
	for (int i=1; i<=m; i++){
		cin >> k;
		for (int j=1; j<=k; j++){
			int a;
			cin >> a;
			vec[i].push_back(a);
		}
	}
	cin >> k;
	for (int i=0; i<k; i++){
		int a, b;
		cin >> a >> b;
		A[a][b] = 1;
		A[b][a] = 1;
	}
	Try(1);
	if (result == INF){
		cout << -1;
	} else {
		cout << result;
	}
}
