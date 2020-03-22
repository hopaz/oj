#include<stdio.h>

const int MAX = 1000;

int main(){
	int n, floor[MAX], sum = 0;
	scanf("%d", &n);

	floor[0] = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &floor[i]);
	}

	for(int i = 1; i <= n; i++){
		if(floor[i] - floor[i - 1] > 0){
			sum = sum + (floor[i] - floor[i - 1]) * 6 + 5;
		}else{
			sum = sum + (floor[i - 1] - floor[i]) * 4 + 5;
		}
	}

	printf("%d", sum);

	return 0;
}

==============
#include<stdio.h>

int main(){
	int n, total = 0, now = 0, to;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		//边读边计算，一个for循环解决
		scanf("%d", &to);
		if(to > now){
			total += ((to - now) * 6);
		}else{
			total += ((now - to) * 4);
		}
		total += 5;
		now = to;
	}

	printf("%d", total);
	return 0;
}