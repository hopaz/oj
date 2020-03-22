#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>

using namespace std;

//每条数据超过2个信息时，用结构体
struct student{
	int id;
	int grade[4];
}stu[2010];


int now; //当前排序科目
int Rank[10000000][4] = {0}; //各科排名为0
char course[4] = {'A', 'C', 'M', 'E'};

bool cmp(student a, student b){
	return a.grade[now] > b.grade[now];
}

double round(double r)
{
    return (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d%d%d%d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
		//四舍五入的表达方式,C++中没有round函数，需要自己手写
		stu[i].grade[0] = round((stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3.0) + 0.5;
	}
	
	//计算各科排名
	for(now = 0; now < 4; now++){ //A，C, M, E轮流排序
		//以结构体为单位排序
		sort(stu, stu + n, cmp);
		//rank的行是stu[i].id
		Rank[stu[0].id][now] = 1;
		for(int k = 1; k < n; k ++){
			//若与前一位考生分数相同
			if(Rank[stu[k].id][now] == Rank[stu[k-1].id][now]) {
				Rank[stu[k].id][now] = Rank[stu[k-1].id][now];
			}else{
				Rank[stu[k].id][now] = k + 1;
			}
		}
	}

	//查询最优排名
	int q;
	for(int p = 0; p < m; p ++){
		if(Rank[q][0] == 0){	//考生id不存在
			printf("N/A\n");
		}else{
			int s = 0;
			for(int r = 0; r < 4; r++){
				if(Rank[q][r] < Rank[q][s]){
					s = r;
				}
			}
			printf("%d%s", Rank[q][s], course[s]);
		}	
	}
	
	return 0;
}












#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>

using namespace std;

struct student {
	int id,c,m,e,a;
};

struct score {
	int rank; // 1 2 3 4 5
	int type; // 0->A 1->C 2->M 3->E
};

bool cmpa(student a, student b) { return a.a > b.a; }
bool cmpc(student a, student b) { return a.c > b.c; }
bool cmpm(student a, student b) { return a.m > b.m; }
bool cmpe(student a, student b) { return a.e > b.e; }
bool cmps(score a, score b) {
	if (a.rank != b.rank) return a.rank < b.rank;
	return a.type < b.type;
}

int main(){
	vector<student> sa,sc,sm,se;
	map< int, int > ma,mc,mm,me;
	vector<int> chk_list;

	int N,M;
	scanf("%d%d", &N, &M);

	{
		for (int i=0; i<N; i++) {
			student s;
			scanf("%d %d %d %d", &s.id, &s.c, &s.m, &s.e);
			s.a = (s.c + s.m + s.e) / 3;
			sa.push_back(s);
			sc.push_back(s);
			sm.push_back(s);
			se.push_back(s);
		}
	}
	
	{
		for (int i=0; i<M; i++) {
			int id;
			scanf("%d", &id);
			chk_list.push_back(id);
		}
	}

	//vector排序时，起点和终点用begin和end
	sort(sa.begin(), sa.end(), cmpa);
	sort(sc.begin(), sc.end(), cmpc);
	sort(sm.begin(), sm.end(), cmpm);
	sort(se.begin(), se.end(), cmpe);

	{
		for (int i=0; i<N; i++) {
            int idx;

            for (idx=i; idx > 0 && sa[idx-1].a == sa[idx].a; idx--);
			ma[sa[i].id] = idx+1;

            for (idx=i; idx > 0 && sc[idx-1].c == sc[idx].c; idx--);
			mc[sc[i].id] = idx+1;

            for (idx=i; idx > 0 && sm[idx-1].m == sm[idx].m; idx--);
			mm[sm[i].id] = idx+1;

            for (idx=i; idx > 0 && se[idx-1].a == se[idx].e; idx--);
			me[se[i].id] = idx+1;
		}
	}

	{
		for (int i=0; i<M; i++) {
			int id = chk_list[i];
			// map声明时，如果value类型是int，默认值是0
			// 如果 map.find(key) == map.end() 说明 key 不存在
			if (ma.find(id) == ma.end()) {
				printf("N/A\n");
				continue;
			}

			//排名和科目名称绑定在一起为score结构体，用于四个分数的最有计算
			score s0,s1,s2,s3;
			s0.rank = ma[id]; s0.type = 0;
			s1.rank = mc[id]; s1.type = 1;
			s2.rank = mm[id]; s2.type = 2;
			s3.rank = me[id]; s3.type = 3;

			score scores[4];
			scores[0] = s0;
			scores[1] = s1;
			scores[2] = s2;
			scores[3] = s3;

			sort(scores, scores+4, cmps);

			//科目映射为数字，最后输出数字对应的科目
			map<int, char> typem;
			typem[0] = 'A';
			typem[1] = 'C';
			typem[2] = 'M';
			typem[3] = 'E';
			printf("%d %c\n", scores[0].rank, typem[scores[0].type]);
		}
	}
	
	return 0;
}
