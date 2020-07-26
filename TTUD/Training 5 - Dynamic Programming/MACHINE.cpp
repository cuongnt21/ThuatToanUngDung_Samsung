#include <bits/stdc++.h>
using namespace std;
#define MT 2000006
 
struct m{
	int s;
	int t;
	int len;
} x[2000001];
int n;
int maxTime[2000001];
 
int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	memset(maxTime,-1,sizeof(maxTime));
	for(int i=1; i<=n; i++){
		cin >> x[i].s >> x[i].t;
		x[i].len = x[i].t - x[i].s;
		maxTime[x[i].t] = max(maxTime[x[i].t], x[i].len);
	}
	maxTime[0] = 0;
	for(int i=1; i<=MT; i++){
		maxTime[i] = max(maxTime[i], maxTime[i-1]);
	}
	int ans = 0;
	for (int i=1; i<=n; i++){
		ans = max(ans, maxTime[x[i].s-1] + x[i].len);
	}
	cout << ans << endl;
}
