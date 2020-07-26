#include <bits/stdc++.h>
#include <math.h>
using namespace std;
const long long C = 1000000007;
 
int main(){
	int n;
	cin >> n;
	long long S=0;
	long long a;
	for (int i=0; i<n; i++){
		cin >> a;
		S += a;
	}
	cout << S%C;
}
