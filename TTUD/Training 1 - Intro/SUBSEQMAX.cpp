#include <bits/stdc++.h>
using namespace std;
 
int Max(int a, int b){
	return (a>b)?a:b;
}
 
int main()
{
	int n, ei, maxSum;
	cin >> n;
	int s[n];
	for (int i=0; i<n; i++)
	{
		cin >> s[i];
	}
	maxSum = s[0];
	ei = s[0];
	for (int i=1; i<n; i++)
	{
		ei = Max(s[i], s[i] + ei);
		maxSum = Max(ei, maxSum);
	}
		cout << maxSum;
}
