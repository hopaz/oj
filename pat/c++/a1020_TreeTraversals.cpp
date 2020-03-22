#include<stdio.h>
#include<queue>

using namespace std;

struct node{
	int data;
	node* lchild;
	node* rchild;
};

int n, post[33], in[33];

node* create(int postL, int postR, int inL, int inR){
	if(postL > postR){//后序长度为0时，直接返回
		return NULL;
	}

	node* root = new node; //根节点
	root->data = post[postR];
	
	int k;
	for(k = inL; k <= inR; k++){
		if(in[k] == post[postR]){break;}//找中序遍历根节点
	}

	int numLeft = k - inL;

	root->lchild = create(postL, postL + numLeft -1, inL, k -1);//左子树
	root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);//右子树

	return root;

}

int num = 0;
void layer(node* root){
	queue<node*> q;
	q.push(root);

	while(!q.empty()){
		node* now = q.front();
		q.pop();
		printf("%d", now->data);
		num++;
		if(num < n){printf(" ");}
		if(now->lchild != NULL){q.push(now->lchild);}
		if(now->rchild != NULL){q.push(now->rchild);}
	}
}

int main(){
	//输入数据
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &post[i]);
	}
	for(int j = 0; j < n; j++){
		scanf("%d", &in[j]);
	}

	node* root = create(0, n - 1, 0, n - 1);//组建树

	layer(root);//层次遍历
	
	return 0;
}