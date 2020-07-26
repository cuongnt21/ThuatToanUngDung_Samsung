#include <bits/stdc++.h>
#include <string>
using namespace std;
 
bool isMatch(char a, char b){
	return ((a == b+1) || (a == b+2));
}
 
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int len = s.length();
		stack<char> sta;
		bool c = 1;
		for (int i=0; i<len; i++){
			char a = s[i];
			if (a == '(' || a == '[' || a == '{'){
				sta.push(a);
			} else {
				if (sta.size() == 0){
					c = 0; break;
				} else {
					char b = sta.top();
					if (isMatch(a, b)){
						sta.pop();
					} else {
						c = 0; break;
					}
				}
			}
		}
		if (sta.size() == 0){
			cout << c << endl;
		} else {
			cout << 0 << endl;
		}
	}
}
