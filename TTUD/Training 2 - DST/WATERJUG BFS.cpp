#include <bits/stdc++.h>
using namespace std;
 
int gcd(int a, int b){
	if (a == 0) 
       return b;
	    
    if (b == 0) 
       return a; 
    if (a == b) 
        return a;
        
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
}
 
int pour(int a,int b, int c){
	//Buoc 1 do day binh a
	int step=1;
	int from = a;
	int to = 0;
	int gap;
	while ((from != c) && (to != c)){
		gap = min(from, b-to);
		from -= gap;
		to += gap;
		step++;
		if ((from == c) || (to == c)){
			break;
		}
		if (from == 0){
			from = a;
			step++;
		}
		if (to == b){
			to = 0;
			step++;
		}
	}
	return step;
}
 
int main(){
	int a, b, c;
	cin >> a >> b >> c;
	if (c %gcd(a,b) != 0){
		cout << -1;
	} else{
		int a1 = pour(a,b,c);
		int a2 = pour(b,a,c);
		cout << min(a1,a2);
	}
}

