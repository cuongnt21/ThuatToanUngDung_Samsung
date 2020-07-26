#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> PoI;
 
int main(){
	int n, k;
	cin >> n >> k;
	priority_queue <PoI> road_pos;
	priority_queue <PoI> road_neg;
	long long x, m;
	for (int i=0; i<n; i++){
		cin >> x >> m;
		if (x < 0){
			road_neg.push(make_pair(abs(x),m));
		} else{
			road_pos.push(make_pair(x,m));
		}
	}
	// tong thoi gian can tinh
	long long time = 0;
	// Khoang cach va so luong goi, va so lan toi thieu de di
	long long distance, packet, step;
	// so goi mang thua ra
	long long carry = 0;	
	while(!road_pos.empty()){
		PoI a;
		a = road_pos.top();
		distance = a.first; packet = a.second;
		road_pos.pop();
		if (packet > carry){
			packet = packet - carry;
			step = ceil(packet*1.0/k);
			carry = step*k - packet;
			time += step*distance*2;
		} else {
			carry = carry - packet;
		}
	}
	carry = 0;
	while(!road_neg.empty()){
		PoI a;
		a = road_neg.top();
		distance = a.first; packet = a.second;
		road_neg.pop();
		if (packet > carry){
			packet = packet - carry;
			step = ceil(packet*1.0/k);
			carry = step*k - packet;
			time += step*distance*2;
		} else {
			carry = carry - packet;
		}
	}
	cout << time;
}
