#include<stdio.h>
#include<stack>
#include<algorithm>

using namespace std;
const int MAXN = 100010;

struct node{
	int address, data, next;
	int order;    //记录元素的原始位置
}nodes[MAXN];

bool cmp(node a, node b){
	return a.order < b.order; //order从小到大排序
}

stack<node> s;   //装node的栈

int main(){
	for(int m = 0; m < MAXN; m++){
		nodes[m].order = MAXN;
	}
	int start, n, K;
	scanf("%05d %d %d", &start, &n, &K);
	int address;
	for(int i = 0; i < n; i++){
		scanf("%05d", &address);
		scanf("%d %05d", &nodes[address].data, &nodes[address].next);
		nodes[address].address = address;
	}

	int p = start, count = 0;
	while(p != -1){                 //统计有效节点
		nodes[p].order = count++;
		p = nodes[p].next;
	}

	sort(nodes, nodes + MAXN, cmp);  //按order排序
	
	int point = 0, target = 0;
	while(point < (count / K) * K){ //前count/K组，先压栈，在出栈
		int k = 0;
		while(k < K){
			s.push(nodes[point]);
			point++;
			k++;
		}
		int print_k = 0;
		while(print_k < K){
			node print_node = s.top();
			s.pop();
			nodes[target] = print_node;  //每K个元素进出栈的前后占用的nodes位置是固定的K位
			target++;
			print_k++;
		}
	}
	while(point < count){  //最后一组不满K个的元素
		target = point;
		point++;
	}
	
	for(int final_i = 0; final_i < count; final_i++){ //更新反转后的next值，并输出
		if(final_i < count - 1){
			nodes[final_i].next = nodes[final_i + 1].address; 
			printf("%05d %d %05d\n", nodes[final_i].address, nodes[final_i].data, nodes[final_i].next);
		}else{
			nodes[final_i].next = -1;
			printf("%05d %d -1\n", nodes[final_i].address, nodes[final_i].data);
		}
	}

	return 0;
}