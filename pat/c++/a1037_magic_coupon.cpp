#include<stdio.h>
#include<algorithm>

using namespace std;


int main(){
	int NC, NP, NC_v[100010], NP_v[100010];
	scanf("%d", &NC);
	for(int i = 0; i < NC; i++){
		scanf("%d", &NC_v[i]);
	}

	scanf("%d", &NP);
	for(int j = 0; j < NP; j++){
		scanf("%d", &NP_v[j]);
	}

	//从小到大排序
	sort(NC_v, NC_v + NC);
	sort(NP_v, NP_v + NP);

	//负数从小到大方向
	int ans = 0, m = 0; //从负数向0方向，下标是一致的
	//NC_v[],NP_v[]全是负数时，最后一次循环会导致数组越界，加上m < NC && n < NP
	while(NC_v[m] < 0 && NP_v[m] < 0 && m < NC && m < NP){
		ans = ans + NC_v[m] * NP_v[m];
		m++;
	}

	//正数从大到小方向
	int p = NC - 1, q = NP - 1;
	//NC_v[],NP_v[]全是正数时，最后一次循环会导致数组越界，p >= 0 && q >= 0
	while(NC_v[p] > 0 && NP_v[q] >0 && p >= 0 && q >= 0){
		ans = ans + NC_v[p] * NP_v[q];
		p--;
		q--;
	}

	printf("%d", ans);

	return 0;
}