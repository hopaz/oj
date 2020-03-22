#include<stdio.h>
#include<algorithm>

using namespace std;

const int MAX = 100010;

int N, M, a[MAX];

int binary_search(int L, int R, int x){
	int left = L, right = R, mid;
	while(left <= right){
		mid = (left + right) / 2;
		if(a[mid] == x){
			return mid;
		}else if(a[mid] > x){
			right = mid -1;
		}else{
			left = mid +1;
		}
	}

	return -1;
}

int main(){
	scanf("%d%d", &N, &M);

	for(int i = 0; i < N; i++){
		scanf("%d", &a[i]);
	}

	sort(a, a+N);

	int j;
	for(j = 0; j < N; j++){
		int k = binary_search(0, N - 1, M - a[j]);
		if(k != -1 && j != k){
			printf("%d %d", a[j], a[k]);
			break;
		}
	}

	if(j == N){
		printf("No Solution\n");
	}

	return 0;
}