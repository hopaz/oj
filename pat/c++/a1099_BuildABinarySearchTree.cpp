#include<stdio.h>
#include<algorithm>
#include<queue>

using namespace std;

const int MAXN = 110;


struct node{
	int data;
	int lchild;
	int rchild;
}nodes[MAXN];

int N, index = 0, list[MAXN];
void inOrder(int root){
	if(root == -1){  //叶子节点，返回
		return;
	}
	inOrder(nodes[root].lchild);
	nodes[root].data = list[index++];
	inOrder(nodes[root].rchild);
}

void BFS(int root){
	queue<int> q;  //队列里存地址
	q.push(root);
	int count = 0;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		printf("%d", nodes[now].data);
		count++;
		if(count < N){ //取完所有元素后，count = N + 1
			printf(" ");
		}
		if(nodes[now].lchild != -1){
			q.push(nodes[now].lchild);
		}
		if(nodes[now].rchild != -1){
			q.push(nodes[now].rchild);
		}
	}
}

int main(){
	scanf("%d", &N);
	int l, r;
	for(int i = 0; i < N; i++){
		scanf("%d%d", &nodes[i].lchild, &nodes[i].rchild);
	}
	for(int j = 0; j < N; j++){
		scanf("%d", &list[j]);
	}
	sort(list, list + N);

	inOrder(0);

	BFS(0);

	return 0;
}
