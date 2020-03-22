#include<stdio.h>
#include<cmath>
#include<algorithm>

using namespace std;

const int MAXN = 1010;

struct node{
	int data;
	node* lchild;
	node* rchild;
}nodes[MAXN];

int N, list[MAXN], CBT[MAXN];
int index = 0;
void inOrder(int root){
	if(root > N){return;}

	inOrder(root * 2);
	CBT[root] = list[index++];
	inOrder(root * 2 + 1);
}


int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){ //根节点编号为1时，完全二叉树节点x，左子树2x，右子树2x+1
		scanf("%d", &list[i]);
	}
	
	sort(list, list + N);

	inOrder(1);

	for(int j = 1; j <= N; j++){
		printf("%d", CBT[j]);
		if(j < N){
			printf(" ");
		}
	}

	return 0;
}