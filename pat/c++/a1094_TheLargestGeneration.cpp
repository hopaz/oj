#include<stdio.h>
#include<vector>

using namespace std;

const int MAX_N = 110;

int N, M, pop_count[10] = {0};

struct node{
	vector<int> child;
}nodes[MAX_N];

void DFS(int index, int level){
	pop_count[level] += 1;
	if(nodes[index].child.size() != 0){
		for(int i = 0; i < nodes[index].child.size(); i++){
			DFS(nodes[index].child[i], level + 1);
		}
	}
}

int main(){
	scanf("%d%d", &N, &M);
	int id, child_count, child;
	for(int i = 0; i < M; i++){
		scanf("%d%d", &id, &child_count);
		for(int j = 0; j < child_count; j++){
			scanf("%d", &child);
			nodes[id].child.push_back(child);
		}
	}

	DFS(1, 1);
	
	int max_population = 0, max_level = 1;
	for(int k = 1; k < 10; k++){
		if(pop_count[k] > max_population){
			max_population = pop_count[k];
			max_level = k;
		}
	}
	printf("%d %d", max_population, max_level);

	return 0;

}