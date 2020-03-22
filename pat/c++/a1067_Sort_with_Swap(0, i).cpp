#include<stdio.h>
#include<algorithm>

using namespace std;

const int LEN = 100010;

int main(){
	int N, num, pos[LEN], ans = 0;
	scanf("%d", &N);
	int left = N-1;
	for(int i = 0; i < N; i++){
		scanf("%d", &num);
		pos[num] = i;
		if(num == i && num != 0){
			left--;		
		}
	}

	int k = 1;
	while(left > 0){
		//数字0所在的位置是0号位,但还未排序结束
		// 1. 每次从0号元素开始遍历，会超时
		// 2. 记录位置编号最小的，不在自己位置的数字k
		if(pos[0] == 0){
			while(k < N){
				if(pos[k] != k){
					swap(pos[0], pos[k]);
					ans++;
					break; //退出循环
				}
				k++;
			}
		}		

		//数字0所在的位置不是0号位
		while(pos[0] != 0){ 
			swap(pos[0], pos[pos[0]]);
			ans++;
			left--;
		}
	}

	printf("%d\n", ans);

	return 0;
}