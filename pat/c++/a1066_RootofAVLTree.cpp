#include<stdio.h>
#include<algorithm> //max函数在algorithm库中

using namespace std;

struct node{
	int v, height;
	node *lchild, *rchild; //同时定义2个指针，*写在变量名前面，不写在类型后面
}*root;

node* newNode(int v){
	node* Node = new node;//new对象时，不需要加括号，new node()是错误的
	Node ->v = v;
	Node ->height = 1;
	Node ->lchild = Node ->rchild = NULL;
	return Node;
}

int getHeight(node* root){
	if(root == NULL){ 
		return 0;
	}
	return root->height;
}

void updateHeight(node* &root){ //updateHeight用root，不用&root
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1; //vc6中max要用__max但是PTA上要用max
}

int getBF(node* root){
	return getHeight(root->lchild) - getHeight(root->rchild);
}

void R(node* &root){   //旋转要用&root
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void L(node* &root){
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void insert(node* &root, int x){
	if(root == NULL){
		root = newNode(x);
		return;
	}
	if(x < root->v){
		insert(root->lchild, x);
		updateHeight(root);
		if(getBF(root) == 2){
			if(getBF(root->lchild) == 1){
				R(root);
			}else if(getBF(root->lchild) == -1){
				L(root->lchild);
				R(root);
			}
		}
	}else if(x > root->v){
		insert(root->rchild, x);
		updateHeight(root);
		if(getBF(root) == -2){
			if(getBF(root->rchild) == -1){
				L(root);
			}else if(getBF(root->rchild) == 1){
				R(root->rchild);
				L(root);
			}
		}
	}
}

int main(){
	int N, data;
	scanf("%d", &N);
	//node* root = NULL; //insert的root是一个node节点，不是NULL
	//node* root; //root得是各种操作函数可以访问的节点指针，所以应该定义在main同一层；
	for(int i = 0; i < N; i++){
		scanf("%d", &data);
		//node* new_node = newNode(data); //插入的数据是int，不需要新建node
		//insert(root, new_node->v);
		insert(root, data);
	}

	printf("%d\n", root->v);

	return 0;
}