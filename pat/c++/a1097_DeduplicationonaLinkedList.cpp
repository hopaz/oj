#include<stdio.h>
#include<map>

using namespace std;

const int MAXN = 100010;
struct node{
	int address, data, next;
}nodes[MAXN], nodes_target1[MAXN], nodes_target2[MAXN];

map<int, int> map_key_count;

int main(){
	int start, n, address;
	scanf("%05d %d", &start, &n);
	for(int i = 0; i < n; i++){
		scanf("%05d", &address);
		scanf("%d %05d", &nodes[address].data, &nodes[address].next);
	}

	int target1 = 0, target2 = 0, p = start;
	while(p != -1){    //不在链表上的点不会进入循环
		int ab_value = nodes[p].data > 0 ? nodes[p].data : -nodes[p].data;  //data为负数，化为绝对值放进map
		map_key_count[ab_value] += 1;
		if(map_key_count[ab_value] == 1){      //第一次出现，放入nodes_target1
			nodes_target1[target1].address = p;  //p是address
			nodes_target1[target1].data = nodes[p].data;
			target1++;
		}else if(map_key_count[ab_value] > 1){ //第二次出现，放入nodes_target2
			nodes_target2[target2].address = p;
			nodes_target2[target2].data = nodes[p].data;
			target2++;
		}
		p = nodes[p].next;
	}
	
	//打印2个链表
	for(int k = 0; k < target1; k++){
		if(k < target1 - 1){
			nodes_target1[k].next = nodes_target1[k+1].address;
			printf("%05d %d %05d\n", nodes_target1[k].address, nodes_target1[k].data, nodes_target1[k].next);
		}else{
			nodes_target1[k].next = -1;
			printf("%05d %d -1\n", nodes_target1[k].address, nodes_target1[k].data);
		}
	}
	
	for(int m = 0; m < target2; m++){
		if(m < target2 - 1){
			nodes_target2[m].next = nodes_target2[m+1].address;
			printf("%05d %d %05d\n", nodes_target2[m].address, nodes_target2[m].data, nodes_target2[m].next);
		}else{
			nodes_target2[m].next = -1;
			printf("%05d %d -1\n", nodes_target2[m].address, nodes_target2[m].data);
		}
	}

	return 0;
}