#include <bits/stdc++.h>
using namespace std;
#define inf 1000001
int n;
int a[inf] ={0};
int na[inf] ={0};
 
int main(){
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> a[i];
	}
	na[1] = 1;
	int maxNa = 1;
	for (int i=2; i<=n; i++){
		int t = 0;
		int trace = 0;
		for(int j=i-1; j>0; j--){
			if (a[i] > a[j]){
				if (na[j] > trace)
				t = j;
				trace = na[t];
			} 
		}
		if (t == 0){
			na[i] = 1;
		} else {
			na[i] = na[t] + 1;
		}
		maxNa = max(maxNa, na[i]);
	}
	cout << maxNa << endl;
}
