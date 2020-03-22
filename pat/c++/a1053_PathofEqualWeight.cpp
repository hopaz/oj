#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct Node{
	int weight;
	vector<int> child;
}nodes[110];

int N, M, S, path[110] = {-1};

void DFS(int index, int num_node, int sum){ //当前节点index，num_node当前path节点个数，sum当前节点权和
	if(sum > S){ return;} //当前超过S，直接返回
	if(sum == S){
		if(nodes[index].child.size() != 0){ return;} //非叶节点，返回
		for(int i = 0; i < num_node; i++){//叶节点，打印
			printf("%d", nodes[path[i]].weight);
			if(i < num_node - 1){
				printf(" ");
			}else{
				printf("\n");	
			}
		}
		return; //打印结束，返回
	}

	for(int i = 0; i < nodes[index].child.size(); i++){
		int child_id = nodes[index].child[i];
		path[num_node] = child_id;
		DFS(child_id, num_node + 1, sum + nodes[child_id].weight);
	}
}

bool cmp(int a, int b){
	return nodes[a].weight > nodes[b].weight;
}

int main(){
	scanf("%d%d%d", &N, &M, &S);
	
	//输入数据
	for(int i = 0; i < N; i++){
		scanf("%d", &nodes[i].weight);
		printf("%", &nodes[i].weight);
	}
	int id, child_count, child;
	for(int i2 = 0; i2 < M; i2++){
		scanf("%d%d", &id, &child_count);
		for(int j = 0; j < child_count; j++){
			scanf("%d", &child);   //nodes数组下标当做节点id
			nodes[id].child.push_back(child);
		}
		sort(nodes[id].child.begin(), nodes[id].child.end(), cmp); //降序遍历，满足输出要求
	}
	path[0] = 0; //路径第一个节点为0

	DFS(0, 1, nodes[0].weight);

	return 0;
}