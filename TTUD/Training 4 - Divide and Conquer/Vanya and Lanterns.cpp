#include <bits/stdc++.h>
using namespace std;
#define eps 1e-9
int n, l;
int a[1001];
 
bool f(double r){
	double bot = 0;
	for(int i=1; i<=n; i++){
		if (a[i] - r <= bot){
			bot = a[i] + r;
		} else {
			return false;
		}
	}
	if (bot>=l) return true;
	return false;
}
 
int main(){
	cin >> n >> l;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	double low = 0;
	double high = l;
	while(high-low >= eps){
		double mid = (high+low)/2;
		if(f(mid)){
			high = mid;
		} else {
			low = mid;
		}
	}
	std::cout.setf(ios::fixed,ios::floatfield);
	cout.precision(9);
	cout << high << endl;
}
