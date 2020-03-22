#include<stdio.h>
#include<algorithm>

using namespace std;

int n, num[5];

void to_array(int a, int b[]){
	for(int i = 0; i < 4; i++){
		b[i] = a % 10;
		a = a / 10;
	}
}

int to_number(int b[]){
	int number = 0;
	for(int i = 0; i < 4; i++){
		number = number * 10 + b[i];
	}

	return number;
}

bool cmp(int a, int b){
	return a > b;
}

int main(){
	scanf("%d", &n);
	int MIN, MAX;
	while(true){
		//读数，转化成数组升序排列，转化成数字MIN；
		to_array(n, num);
		sort(num, num + 4);
		MIN = to_number(num);

		//数组降序排列，转化成数字MAX
		sort(num, num + 4, cmp);
		MAX = to_number(num);

		//下一个数
		n = MAX - MIN;

		//打印结果，注意换行和格式
		printf("%04d - %04d = %04d\n", MAX, MIN, n); 

		//结束条件
		if(n == 0 || n == 6174){
			break;
		}
	}

	return 0;

}