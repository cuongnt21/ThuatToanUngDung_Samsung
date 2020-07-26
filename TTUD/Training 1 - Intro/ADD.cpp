#include<iostream>
#include<string>
using namespace std;
int main()
{
	int r, nho = 0;
	string a ,b, kq="";
	cin >> a;
	cin >> b;
	
 
	while (a.length() > b.length())
	{
		b = "0" + b;
	}
	while (a.length() < b.length())
	{
		a = "0" + a;
	}
	for (int i=a.length()-1; i > -1; i--)
	{
		r = (int)a[i] - 48 + (int)b[i] - 48 + nho;
		kq = (char)((r % 10)+48) + kq;
		nho = r/10;
	}
	
	if (nho)
	{
		kq = (char)(nho+48) + kq;
	}
 
	cout << kq;
	return 0;
}
