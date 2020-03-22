#include<stdio.h>
#include<vector>
#include<cmath>

using namespace std;

struct node{
	vector<int> child;
}nodes[100010];

int N;
double P, r;

int max_depth = 0, num = 0;
void DFS(int index, int depth){
	int size = nodes[index].child.size();
	if(size != 0){
		for(int i = 0; i < size; i++){
			DFS(nodes[index].child[i], depth + 1);
		}
	}else{
		if(depth > max_depth){
			max_depth = depth;
			num = 1;
		}else if(depth == max_depth){
			num++;
		}
	}
}

int main(){
	scanf("%d%lf%lf", &N, &P, &r);
	r /= 100;
	int father, root;
	for(int i = 0; i < N; i++){
		scanf("%d", &father);
		if(father != -1){
			nodes[father].child.push_back(i);
		}else{
			root = i; 
		}
	}

	DFS(root, 0);

	printf("%.2lf %d", P * pow(1 + r, max_depth), num);

	return 0;
}