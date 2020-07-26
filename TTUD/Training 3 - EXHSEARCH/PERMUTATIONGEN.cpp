#include <bits/stdc++.h>
using namespace std;
int n;
int a[10001];
int t[10001];
bool check = false;
bool check2 = false;
 
// Kiem tra j co phu hop vi tri k
bool UCV(int j, int k){
	if (check2) return false;
	if (check){
		for(int i=1; i<k; i++){
			if(a[i] == j){
				return false;
			}
		}
	return true;
	} else {
		if(t[k] == j){
			return true;
		} else {
			return false;
		}
	}
}
 
void Inra(){
		for(int i=1; i<=n; i++){
			cout << a[i] << " ";
		}
	cout << endl;
}
 
void Try(int k){
	for(int j=1; j<=n; j++){
		if (UCV(j, k)){
			a[k] = j;
			if(k == n){
				if(!check){
					check = true;
				} else {
					Inra();
					check2 = true;
				}
			} else {
				Try(k+1);
			}
		}
	}
}
 
int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> t[i];
	}
	Try(1);
	if(!check2){
		cout << -1;
	}
}
