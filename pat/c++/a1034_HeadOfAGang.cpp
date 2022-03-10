#include <iostream>
#include <stdio.h>
#include <map>
#include <string>

using namespace std;

const int MAXV = 2010; //通话记录不超过1000条，通话人数不超过2000

map<string, int> strToInt;
map<int, string> intToStr;
map<string, int> gang;

int weight[MAXV] = {0};
bool vis[MAXV] = {false};   //定义访问数组
int G[MAXV][MAXV] = {0};
int N, K;  //n个人，最大总权值K

int numPerson = 1;  //是map的key，也可以用来记录总人数;从1开始计数比从0开始计数好理解
int str_to_int(string s){
	if(strToInt[s] == 0){ //不在map中，加入map，返回index
		strToInt[s] = numPerson;
		intToStr[numPerson] = s;
		return numPerson++;
	}else{
		return strToInt[s];//在map中，返回对应的编号index
	}
}

void dfs(int nowVisit, int& head, int& numGangMember, int& totalValue){ //需要修改head，numGangMember,totalValue，所以用&
	numGangMember++;
	vis[nowVisit] = true;
	if(weight[nowVisit] > weight[head]){
		head = nowVisit;   //更新head
	}
	for(int j = 1; j < numPerson; j++){
		if(G[nowVisit][j] > 0){   //如果nowVisit可以到达
			totalValue = totalValue + G[nowVisit][j];
			G[nowVisit][j] = G[j][nowVisit] = 0; //遍历过的边权值置零，防止反向的时候多加一遍
			if(vis[j] == false){   //如果i没有被访问
				dfs(j, head, numGangMember, totalValue);
			}
		}
	}
}

void dfsTrave(){
	for(int i = 1; i < numPerson; i++){
		if(vis[i] == false){
			int head = i, numGangMember = 0, totalValue = 0;  //head记录最高通信量的人
			dfs(i, head, numGangMember, totalValue);
			if(numGangMember > 2 && totalValue > K){   //totalValue是一个gang的总通信量
				gang[intToStr[head]] = numGangMember;  //head是int，通过intToStr[]反向查询到str，作为gang的key
			}
		}
	}
}

int main(){
	scanf("%d%d", &N, &K);

	string s1, s2;
	int w;
	for(int i = 0; i < N; i++){
		cin >> s1 >> s2 >> w;   //涉及string的输入，用cin
		int u = str_to_int(s1);
		int v = str_to_int(s2);
		weight[u] += w;  //初始化weight数组
		weight[v] += w;
		G[u][v] += w;	//初始化图
		G[v][u] += w;
	}

	dfsTrave();

	//打印map时用迭代器
	cout << gang.size() << endl;
	for(map<string, int>::iterator it = gang.begin(); it != gang.end(); it++){
		cout << it->first << " " << it->second << endl;
	}

	return 0;
}