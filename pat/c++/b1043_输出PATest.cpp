#include<stdio.h>
#include<string.h>
#include<map>

using namespace std;

const int MAXN = 10010;
int main(){
	map<char, int> mp;
	char str[MAXN];
	scanf("%s", str);

	//初始化map
	for(int i = 0; i < strlen(str); i++){
		if(str[i] == 'P'){
			mp['P'] += 1;
		}else if(str[i] == 'A'){
			mp['A'] += 1;
		}else if(str[i] == 'T'){
			mp['T'] += 1;
		}else if(str[i] == 'e'){
			mp['e'] += 1;
		}else if(str[i] == 's'){
			mp['s'] += 1;
		}else if(str[i] == 't'){
			mp['t'] += 1;
		}else{
			continue;
		}
	}

	//找出循环次数
	int max = 0;
	for(map<char, int>::iterator it = mp.begin(); it != mp.end(); it++){
		if(it -> second > max){
			max = it -> second;
		}
	}

	//打印结果
	for(int k = 0; k <= max; k++){
		if(mp['P'] != 0){
			printf("P");
			mp['P']--;
		}
		if(mp['A'] != 0){
			printf("A");
			mp['A']--;
		}
		if(mp['T'] != 0){
			printf("T");
			mp['T']--;
		}
		if(mp['e'] != 0){
			printf("e");
			mp['e']--;
		}
		if(mp['s'] != 0){
			printf("s");
			mp['s']--;
		}
		if(mp['t'] != 0){
			printf("t");
			mp['t']--;
		}
	}

	return 0;
}