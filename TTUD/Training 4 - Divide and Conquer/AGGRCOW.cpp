#include <bits/stdc++.h>
using namespace std;
int n, c;
int x[100001];
 
bool dk(int gap){
	int i=1;
	int count = 1;
	for (int j=2; j<=n; j++){
		if(x[j]-x[i] >= gap){
			i=j;
			count++;
		}
		if (count >= c){
			return true;
		}
	}
	return false;
}
 
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &c);
		for (int i=1; i<=n; i++){
			scanf("%d", &x[i]);
		}
		sort(x+1,x+1+n);
		int low = 1;
		int high = x[n] - x[1] + 1;
		while(high-low > 1){
			int mid=(high+low)/2;
			if(dk(mid)) low=mid;
			else high = mid;
		}
		printf("%d\n", low);
	}
}
