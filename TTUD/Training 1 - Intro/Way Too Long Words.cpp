#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	string s;
	char c[101];
	while(n--){
		cin >> s;
		int len = s.size();
		if(len > 10){
			cout << s[0] << len - 2 << s[len-1] << endl;;
		} else {
			cout << s << endl;
		}
	}
}
