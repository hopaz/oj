#include<stdio.h>
#include<map>
#include<vector>

using namespace std;

void input1(){
	//100 200 300
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%d %d %d", a, b, c);
}

void input2(){
	//abcdefg g
	char str[99], c;
	scanf("%s", str);
	getchar();
	c = getchar();
	printf("%s ", str);
	putchar(c);
}

/*
     o
   o o o
     o
*/

void input3(){
	//输入行数+坐标
	//3 10 10
	//lines[0][0]=10  lines[0][1]=11
	// lines[10][11] =1/0
	//10 10
	//10 30
	int line_count, lines[99][2], i;
	scanf("%d", &line_count);
	for(i=0; i < line_count; i++){
		scanf("%d %d", &lines[i][0], &lines[i][1]);
	}
	printf("%d\n", line_count);
	for(i=0; i < line_count; i++){
		printf("%d %d\n", lines[i][0], lines[i][1]);
	}
}


struct person_grade{
	char name[20];
	char sub1[5];
	double math_g;
	char sub2[5];
	double eng_g;
}pg[1000];

void input4(){
	/*
	输入4，行数+成绩单
	3
	alice math 97.0 eng 90.5
	bob math 98.9 eng 80.5
	cindy math 87.5 eng 90.0
	*/
	//所有变量声明在所有可执行语句的前面
	int lc, i;
	scanf("%d", &lc);
	for(i=0; i < lc; i++){
		scanf("%s%s%f%s%f", &pg[i].name, &pg[i].sub1, &pg[i].math_g, &pg[i].sub2, &pg[i].eng_g);
	}
	for(i=0; i < lc; i++){
		printf("%s %s %.4f %s %.4f\n", pg[i].name, pg[i].sub1, pg[i].math_g, pg[i].sub2, pg[i].eng_g);
	}
}

void input5(){
	vector<int> v;
	int lines;
	scanf("%d", &lines);
	for(int i = 0; i < lines; i++){
		int input;
		//使用变量存储scanf的数据，在保存到vector里
		scanf("%d", &input);
		v.push_back(input);
	}
	for(int j = 0; j < lines; j++){
		printf("%d ", v[j]);
	}
}

input_1029(){
  //两行字符串的输入
  char expect[1000000], input[1000000];
  scanf("%s\n%s", expect, input);
}


input_1042(){
	char str[MAXN];
	//读取带空格的字符串
	//gets(str); gets()的替代函数fgets(); https://www.cnblogs.com/qingergege/p/5925811.html
	fgets(str, MAXN, stdin);

	//读取带空格的字符串,或者这样写
	char str[1000];
	int len = 0;
	while(true){
		str[len++] = getchar();
		if(str[len - 1] == '\n'){break;}
	}
}

input_1047(){
	//特殊格式的输入
	for(int j = 0; j < N; j++){
		scanf("%d-%d %d", &team, &mn, &score);
		team_score[team] = team_score[team] + score;
	}
}


input_b1020(){
	//输出格式要求保留2位小数
	printf("%.2lf\n", profit);
}

int main(){
	return 0;
}
