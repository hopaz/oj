#include<stdio.h>
#include<vector>
#include<cmath>

using namespace std;
const int MAXN = 1000010;

struct node{
	vector<int> child;
}nodes[MAXN];

int min_level = 1000000, num = 0; 
// min_level要设置的足够大，例如N=100000，每层只有一个节点，那么level就是100000
void DFS(int index, int level){
	int size = nodes[index].child.size();
	if(size == 0){
		if(level < min_level){
			min_level = level;
			num = 1;
		}else if(level == min_level){
			num++;
		}
		return;
	}
	for(int i = 0; i < size; i++){
		DFS(nodes[index].child[i], level + 1);
	}
}

int N;
double P, r;
int main(){
	scanf("%d%lf%lf", &N, &P, &r);
	r /= 100;
	int child_count, child;
	for(int i = 0; i < N; i++){
		scanf("%d", &child_count);
		if(child_count != 0){
			for(int j = 0; j < child_count; j++){
				scanf("%d", &child);
				nodes[i].child.push_back(child);
			}
		}
	}

	DFS(0, 0);
	printf("%.4lf %d", P * pow(1 + r, min_level), num);

	return 0;
}