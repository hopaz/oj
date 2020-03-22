#include<stdio.h>

const int MAX = 110;

int gcd(int a, int b){
	return !b ? a : gcd(b, a % b);
}

int main(){
	int N, M, num[MAX];
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; i++){
		scanf("%d", &num[i]);
	}

	int d = gcd(N, M);

	M = M % N; //修正M
	int pos, tmp, next;
	if(M != 0){ //右移位数非零
		for(int i = N - M; i < N - M + d; i++){
			tmp = num[i];
			pos = i;
			do{
				next = (pos - M + N) % N; //pos-m后小于0，加n可将i转成正确的位置
				if(next != i){
					num[pos] = num[next];
				}else{
					num[pos] = tmp;
				}
				pos = next;
			}while(pos != i);
		}

	}


	for(int j = 0; j < N; j++){
		if(j < N - 1){
			printf("%d ", num[j]);
		}else{
			printf("%d", num[j]);
		}
	}

	return 0;
}