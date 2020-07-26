#include <bits/stdc++.h>
#include <fstream>
using namespace std;
 
int main(){
	int n;
	cin >> n;
	if (n < 600000){
		float a[n];
		for (int i=0; i<n; i++) scanf("%f", &a[i]);
		
		sort(a,a+n);
		
		for (int i=0; i<n; i++) printf("%.2f ", a[i]);
	} else {
		int m1 = 2*n/5;
		int m2 = n - m1;
		
		// Luu phan it hon vao file
		FILE *open;
		open = fopen("1.tmp", "w");
		float a[m2];
		for(int i=0; i<m1; i++) scanf("%f", &a[i]);
		sort(a, a+m1);
		for(int i=0; i<m1; i++) fprintf(open, "%.2f ", a[i]);
		fclose(open);
		
		// Scan phan con lai
		for(int i=0; i<m2; i++) scanf("%f", &a[i]);
		sort(a, a+m2);
		
		FILE *in;
		in = fopen("1.tmp", "r");
		float b1, b2;
		int i = 0,	j = 0;
		fscanf(in, "%f", &b1);
		b2 = a[0];
		while(i < m1 && j < m2){
			if (b1 < b2){
				i++;
				printf("%.2f ", b1);
				if (i < m1)
					fscanf(in, "%f", &b1);
			} else{
				j++;
				printf("%.2f ", b2);
				if (j < m2)
					b2 = a[j];
			}
		}
		while(i++ < m1){
			printf("%.2f ", b1);
			fscanf(in, "%f", &b1);
		}
		while(j++ < m2){
			printf("%.2f ", b2);
			b2 = a[j];
		}
	}
	
	return 0;
}
