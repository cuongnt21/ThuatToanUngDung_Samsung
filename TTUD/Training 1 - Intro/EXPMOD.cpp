
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
const long long c = 1000000007;
 
long long mod(long long a, long long b){
	if (b == 1)
		return a;
	else{
		long long k = mod(a,b/2);
		if (b%2){
			return (((k*k) % c)*a) % c;
		} else {
			return (k*k) % c;
		}
	}
}
 
int main(){
	long long a,b;
	cin >> a >> b;
	cout << mod(a,b);
}
