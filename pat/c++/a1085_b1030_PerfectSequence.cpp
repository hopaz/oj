#include<stdio.h>
#include<algorithm>

using namespace std;

const int MAXN=100010;

int main(){

	int N, p;
	scanf("%d%d", &N, &p);

	int num[MAXN];
	for(int i = 0; i < N; i++){
		scanf("%d", &num[i]);
	}

	sort(num, num + N);

	//num[]中挨个找m到mp之间的数字，记录个数
	int ans = 1; //最大长度至少为1
	for(int j = 0; j < N; j++){
		//在num[j+1],num[n-1]中查找第一个大于num[j]*p的数字的位置
		int k = upper_bound(num + j + 1, num + N, (long long)num[j] * p) - num; //upper_bound参数是[first, last),所以last是num+n,而不是num+n-1
		ans = max(ans, k - j);
	}

	printf("%d", ans);

	return 0;
}


===============
vc6


#include<stdio.h>
#include<algorithm>

using namespace std;

const int MAXN=100010;

int main(){

	int N, p;
	scanf("%d%d", &N, &p);

	int num[MAXN];
	for(int i = 0; i < N; i++){
		scanf("%d", &num[i]);
	}

	sort(num, num + N);

	//num[]中挨个找m到mp之间的数字，记录个数
	int ans = 1; //最大长度至少为1
	for(int j = 0; j < N; j++){
		//在num[j+1],num[n-1]中查找第一个大于num[j]*p的数字的位置
		int k = lower_bound(num + j +1, num + N, (__int64)num[j] * p) - num; //upper_bound参数是[first, last),所以last是num+n,而不是num+n-1
		ans = __max(ans, k - j); //vc6中用__max()才能编译通过
	}

	printf("%d", ans);

	return 0;
}


==========
双指针
#include<stdio.h>
#include<algorithm>

using namespace std;
const int MAX = 100010;

int main(){
	int n, p, a[MAX];
	scanf("%d%d", &n, &p);

	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	sort(a, a + n);

	int j = 0, k = 0, count = 1;
	while(j < n && k < n){
		while(k < n && a[k] <= (long long) a[j] * p){
			count = max(count, k - j + 1);
			k++;
		}
		j++;
	}

	printf("%d\n", count);
	return 0;
}