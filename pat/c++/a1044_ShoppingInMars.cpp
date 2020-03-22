#include<stdio.h>

const int MAX = 100010;
int N, S, sum[MAX], near_s = 1000010;

int upper_bound(int L, int R, int x){
	int left = L, right = R, mid;
	while(left < right){
		mid = (left + right) / 2;
		if(sum[mid] > x){
			right = mid;
		}else{
			left = mid + 1;
		}
	}

	return left;
}

int main(){
	scanf("%d%d", &N, &S);

	sum[0] = 0;
	for(int i = 1; i <= N; i++){
		scanf("%d", &sum[i]);
		sum[i] += sum[i-1];
	}

	//找到恰好等于s的位置或最小的大于s的位置
	for(int j = 1; j <= N; j++){
		int k = upper_bound(j, N + 1, sum[j - 1] + S);
		if(sum[k -1] - sum[j - 1] == S){
			near_s = S;
			break;
		}else if(k <= N && sum[k] - sum[j - 1] < near_s){
			near_s = sum[k] - sum[j - 1];
		}
	}

	for(int m = 1; m <= N; m++){
		int p = upper_bound(m, N + 1, sum[m - 1] + near_s);
		if(sum[p - 1] - sum[m - 1] == near_s){ //是p - 1，因为p是第一个大于near_s的位置
			printf("%d-%d\n", m, p - 1);
		}
	}

	return 0;
}