#include<stdio.h>
#include<string.h>


int main(){
	//分数是1-100，hash_map的个数要大于100，至少101
	int hash_map[101], N, K, q;
	memset(hash_map, 0, sizeof(hash_map));
	//初始化还可以这样写，int hash_map[101] = {0}; 
	
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		int score;
		scanf("%d", &score);
		hash_map[score] += 1;
	}

	scanf("%d", &K);
	for(int j = 0; j < K; j++){
		scanf("%d", &q);
		if(j != K - 1){
			printf("%d ", hash_map[q]);
		}else{
			printf("%d", hash_map[q]);
		}
	}

	return 0;
}