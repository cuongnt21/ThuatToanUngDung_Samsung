#include <bits/stdc++.h>
using namespace std;
#define eps 1e-6
const double pi = acos(-1);
int n, f;
double S[100001];
 
// Tra ve so ban, t dien tich 1 mieng banh
bool chia_banh(double t){
	if (t == 0) return 0;
	int count = 0;;
	for (int i=1; i<=n; i++){
		count += S[i]/t;
	}
	if (count >= f+1) return true;
	else return false;
}
 
double pie(double low, double high, int f){
	if(high - low >= eps){
		double mid = (low + high)/2;
		if (chia_banh(mid)){
			return pie(mid, high, f);
		} else {
			return pie(low, mid, f);
		}
	} else return low;
}
 
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> f;
		int temp;
		for (int i=1; i<=n; i++){
			cin >> temp;
			S[i] = temp*temp*pi;
		}
		sort(S+1, S+1+n);
		std::cout.setf(ios::fixed,ios::floatfield);
		cout.precision(6);
		cout << pie(0, S[n], f) << endl;
	}
}
