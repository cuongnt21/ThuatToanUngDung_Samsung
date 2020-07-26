#include <bits/stdc++.h>
using namespace std;
#define maxi 1000001
long long n, m;
int h[maxi] = {0};
int hmax = 0;
 
long long f(long long mid){
	long long count = 0;
	for (int i=n; i>=1; i--){
		if (mid >= h[i]) break;
		else count += h[i] - mid;
	}
	return count;
}
 
int main(){
	scanf("%d %d",&n,&m);
	for (int i=1; i<=n; i++){
		scanf("%d",&h[i]);
//		cin >> h[i];
		hmax = max(hmax, h[i]);
	}
	sort(h+1,h+1+n);
	long long low = 0;
	long long high = hmax;
	while (high - low > 1){
		long long mid = (high + low)/2;
		if (f(mid) >= m){
			low = mid;
		} else {
			high = mid;
		}
	}
	printf("%d", low);
}
