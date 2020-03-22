#include<stdio.h>
#include<vector>

using namespace std;
const int MAXN = 110;

struct node{
	vector<int> child;
}nodes[MAXN];

int level_leafs[MAXN] = {0}, max_level = 1;
void DFS(int index, int level){
	if(level > max_level){
		max_level = level;
	}

	int size = nodes[index].child.size();
	if(size == 0){
		level_leafs[level]++;
	}else{
		for(int i = 0; i < size; i++){
			DFS(nodes[index].child[i], level + 1);
		}
	}

}


int N, M;
int main(){
	scanf("%d%d", &N, &M);
	int id, child_count, child_id;
	for(int i = 0; i < M; i++){
		scanf("%d%d", &id, &child_count);
		for(int j = 0; j < child_count; j++){
			scanf("%d", &child_id);
			nodes[id].child.push_back(child_id);
		}
	}

	DFS(1, 1);

	for(int k = 1; k <= max_level; k++){
		printf("%d", level_leafs[k]);
		if(k < max_level){
			printf(" ");
		}
	}
	
	return 0;
}