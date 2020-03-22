#include<stdio.h>
#include<algorithm>

using namespace std;


int main(){
	int num[10], num_sum = 0;
	fill(num, num + 10, 0);
	for(int i = 0; i < 10; i++){
		scanf("%d", &num[i]);
		num_sum += num[i];	
	}

	//确定第一位数字
	for(int j = 1; j < 10; j++){
		if(num[j] != 0){
			printf("%d", j);
			num[j]--;
			break;
		}
	}

	//确定后续数字
	int p = 0, q = 1;
	while(q < num_sum){
		if(num[p] != 0){
			printf("%d", p);
			num[p]--;
			q++;
		}else{
			p++;
		}
	}

	return 0;
}