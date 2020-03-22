#include<stdio.h>
#include<algorithm>

using namespace std;
const int MAXN = 100010;

struct node{
	int address, key, next;
	bool flag;             //true为有效节点，即数组中非空的节点
}nodes[MAXN];

bool cmp(node a, node b){
	if(a.flag == false || b.flag == false){
		return a.flag > b.flag;          //有效节点在前，无效节点在后
	}else{
		return a.key < b.key;            //都是有效节点，升序排列
	}
}

int main(){
	for(int k = 0; k < MAXN; k++){
		nodes[k].flag = false; //所有节点都是无效节点，即不在链表上
	}

	int n, start;
	scanf("%d %05d", &n, &start);
	int address, key, next;
	for(int i = 0; i < n; i++){
		scanf("%05d %d %05d", &address, &key, &next);
		nodes[address].address = address; //初始化读入数据要记得处理结构体中每一个属性
		nodes[address].key = key;
		nodes[address].next = next;
	}

	int p = start, count = 0;
	while(p != -1){
		nodes[p].flag = true;
		count++;                    //统计有效节点个数，打印的循环里用来控制输出次数
		p = nodes[p].next;          //通过next串下来所有在链表上的节点
	}

	if(count == 0){
		printf("0 -1");
	}else{
		sort(nodes, nodes + MAXN, cmp);
		printf("%d %05d\n", count, nodes[0].address);
		for(int j = 0; j < count; j++){
			if(j != count - 1){
				printf("%05d %d %05d\n", nodes[j].address, nodes[j].key, nodes[j+1].address); //第三个是i+1的address,不是i的next
			}else{
				printf("%05d %d -1\n", nodes[j].address, nodes[j].key);
			}
		}
	}

	return 0;
}
