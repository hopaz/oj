#include<stdio.h>
#include<algorithm>

using namespace std;

struct mooncake{
	double amount;
	double account;
	double price;
}cake[1010];

//cmp 函数要有返回值
bool cmp(mooncake a, mooncake b){
	return a.price > b.price;
}

int main(){
	//读输入，初始化结构体
	int N;
	double D;
	scanf("%d%lf", &N, &D);

	for(int i = 0; i < N; i++){
		scanf("%lf", &cake[i].amount);
	}

	for(int j = 0; j < N; j++){
		scanf("%lf", &cake[j].account);
		cake[j].price = cake[j].account / cake[j].amount;
	}	
	
	//结构体按单价降序排列,结构体的个数是N个，所以加N，不是加1010
	sort(cake, cake + N, cmp);

	//选方案
	double profit = 0;
	//结束条件应该是p的表达式，不能是其他变量的表达式（D!=0）
	for(int p = 0; p < N; p++){
		if(D >= cake[p].amount){
			profit = profit + cake[p].account;
			D = D - cake[p].amount;
		}else{
			profit = profit + cake[p].price * D;
			break; //满足所有需求量后，结束循环
		}
	}

	//输出格式要求保留2位小数
	printf("%.2lf\n", profit);

	return 0;
}