#include<stdio.h>
#include<map>
#include<algorithm>

using namespace std;

const int MAX = 100010;

int main(){
	int N, input[MAX], num[MAX], i;
	fill(num, num + MAX, 0);   //int数组要初始化为0，否则默认值根据编译器不同，值不同
	scanf("%d", &N);

	for(int i = 1; i <= N; i++){
		int key;
		scanf("%d", &key);
		input[i] = key;
		num[key] += 1;
	}

	for(i = 1; i <= N; i++){
		if(num[input[i]] == 1){
			break;
		}	
	}

	if(i <= N){
		printf("%d", input[i]);
	}else{
		printf("None");
	}

	return 0;
}