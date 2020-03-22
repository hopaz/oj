#include<stdio.h>

const int MAX = 100010;

int main(){
	int n;
	double num[MAX], sum = 0;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%lf", &num[i]);
		sum = sum + num[i] * (n - i + 1) * i;
	}

	printf("%.2f", sum);
	
	return 0;
}