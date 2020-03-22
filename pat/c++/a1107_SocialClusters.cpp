#include<stdio.h>
#include<algorithm>

using namespace std;

const int MAXN = 1010;

int father[MAXN], isRoot[MAXN]= {0}, course[MAXN] = {0};


int findFather(int x){
	int a = x;
	while(x != father[x]){
		x = father[x];
	}

	//路径压缩
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}

	return x;
}

void Union(int a, int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB){
		father[faA] = faB;
	}
}

void init(int n){
	for(int i = 1; i <= n; i++){
		father[i] = i;  //father数组需要初始化
		isRoot[i] = 0;  //isRoot初始化可以在定义处，也可以在这里
	}
}

bool cmp(int a, int b){
	return a > b;
}

int main(){
	int n, count, h;
	scanf("%d", &n);
	init(n);
	for(int i = 1; i <= n; i++){ //人编号从1到n
		scanf("%d:", &count);
		for(int j = 0; j < count; j++){
			scanf("%d", &h);
			if(course[h] == 0){ //爱好h的i是第一个人
				course[h] = i;
			}
			Union(i, findFather(course[h])); //当前i号人喜欢h，与曾经第一个喜欢h的人的根节点合并		
		}
	}

	for(int k = 1; k <= n; k++){
		isRoot[findFather(k)]++;     //根节点次数即为该cluster的人数
	}

	int ans = 0;
	for(int j = 1; j <= n; j++){
		if(isRoot[j] != 0){
			ans++;
		}
	}

	sort(isRoot + 1, isRoot + n + 1, cmp);
	printf("%d\n", ans);
	for(int m = 1; m <= ans; m++){
		printf("%d", isRoot[m]);
		if(m < ans){
			printf(" ");
		}
	}
	
	return 0;
}