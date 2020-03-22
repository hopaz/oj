#include<stdio.h>

const int MAXN = 100010;

struct node{
	char data;
	int next;
	int flag;
}nodes[MAXN];

int main(){
	int n, start1, start2; 
	scanf("%d%d%d", &start1, &start2, &n);
	int a, b;
	char c;
	for(int i = 0; i < n; i++){
		scanf("%05d %c %05d", &a, &c, &b);
		nodes[a].data = c;
		nodes[a].next = b;
	}

	int point = start1;
	while(point != -1){             //遍历第一个链表，标记拥有的字符
		nodes[point].flag = 1;
		point = nodes[point].next;
	}

	point = start2;
	while(point != -1){				//遍历第二个链表，第一个flag为1的字符即为答案
		if(nodes[point].flag == 1){
			break;
		}else{
			point = nodes[point].next;
		}
	}

	if(point != -1){
		printf("%05d", point);
	}else{
		printf("-1");
	}

	return 0;
}