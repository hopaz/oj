#include<stdio.h>
#include<vector>

using namespace std;

const int MAXN = 100010;

struct node{
	vector<int> child;
	int count;
}nodes[MAXN];

int N;
double P, r;
double sum = 0.0;

void DFS(int index, float price){
	int size = nodes[index].child.size();
	if(size != 0){
		for(int i = 0; i < size; i++){
			DFS(nodes[index].child[i], price * ( 1.00 + r));
		}
	}else{
		sum = sum + nodes[index].count * price;
		return;
	}
}

int main(){
	scanf("%d%lf%lf", &N, &P, &r);
	r /= 100; //转化成百分比

	int child_count, child_id;
	for(int i = 0; i < N; i++){
		scanf("%d", &child_count);
		if(child_count != 0){ //孩子个数不为0，保存孩子节点编号
			for(int j = 0; j < child_count; j++){
				scanf("%d", &child_id);
				//保存子节点id，要用vector的push_back()方法，不能直接scanf("%d", &nodes[i].child[j]);
				nodes[i].child.push_back(child_id); 
			}
		}else{
			scanf("%d", &nodes[i].count); //孩子个数为0，保存产品个数
		}
	}

	DFS(0, P);

	printf("%.1f", sum);
	return 0;

}