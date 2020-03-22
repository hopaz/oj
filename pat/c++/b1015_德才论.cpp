#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

//每条数据超过2个信息时，用结构体
struct student{
	int id;
	int de, cai, sum;
	int flag;
};


bool cmp(student s1, student s2){
	if(s1.flag != s2.flag){return s1.flag < s2.flag;}//类别小的在前
	else if(s1.sum != s2.sum){return s1.sum > s2.sum;}//类别相同，总分降序
	else if(s1.de != s2.de){return s1.de > s2.de;}//总分相同，德分降序   
	else{return s1.id < s2.id;}//德分相同，准考证号升序
}

int main(){
	int n, L, H;
	scanf("%d%d%d", &n, &L, &H);
	int m = n; //及格人数
	for(int i = 0; i < n; i++){
		//读成绩并计算总分
		scanf("%d%d%d", &stu[i].id, &stu[i].de, &stu[i].cai);
		stu[i].sum = stu[i].de + stu[i].cai;

		//分类
		if(stu[i].de < L || stu[i].cai < L){
 			stu[i].flag = 5;
			m--;
		}else if(stu[i].de >= H && stu[i].cai >= H){
			stu[i].flag = 1;
		}else if(stu[i].de >= H && stu[i].cai < H){
			stu[i].flag = 2;
		}else if(stu[i].de >= stu[i].cai && stu[i].de < H && stu[i].cai < H){
			stu[i].flag = 3;
		}else{
			stu[i].flag = 4;
		}
	}

	sort(stu, stu + n, cmp);

	//打印结果
	printf("%d\n", m);
	//for循环中终止条件控制了输出的行数，前m个位及格的人，剩余不及格，不打印
	for(int j = 0; j < m; j++){
		printf("%d %d %d\n", stu[j].id, stu[j].de, stu[j].cai);
	}

	//有三个case没过
	return 0;
}





#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

//每条数据超过2个信息时，用结构体
struct student{
 int id;
 int de, cai, sum;
 int flag;
};


bool cmp(student s1, student s2){
 if(s1.flag != s2.flag)return s1.flag < s2.flag; //类别小的在前
 if(s1.sum != s2.sum)return s1.sum > s2.sum;//类别相同，总分降序
 if(s1.de != s2.de)return s1.de > s2.de;//总分相同，德分降序
 return s1.id < s2.id;//德分相同，准考证号升序
}

int main(){
 int n, L, H;
 scanf("%d%d%d", &n, &L, &H);
 vector<student> stus;
 for(int i = 0; i < n; i++){
  //读成绩并计算总分
        student s;
  scanf("%d %d %d", &s.id, &s.de, &s.cai);
  s.sum = s.de + s.cai;
  //分类
  if(s.de < L || s.cai < L){
            continue;
  }else if(s.de >= H && s.cai >= H){
   s.flag = 1;
  }else if(s.de >= H && s.cai < H){
   s.flag = 2;
  }else if(s.de < H && s.cai < H && s.de >= s.cai){
   s.flag = 3;
  }else{
   s.flag = 4;
  }
        stus.push_back(s);
 }

 sort(stus.begin(), stus.end(), cmp);

 //打印结果
 printf("%d\n", stus.size());
 for(int j = 0; j < stus.size(); j++){
  printf("%d %d %d\n", stus[j].id, stus[j].de, stus[j].cai);
 }

 return 0;
}