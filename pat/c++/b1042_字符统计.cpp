#include "stdio.h"
#include<string.h>
#include<map>

using namespace std;

const int MAXN = 1010;
int main(){
	map<char, int> mp;
	char str[MAXN];
	//读取带空格的字符串
	//gets(str); gets()的替代函数fgets(); https://www.cnblogs.com/qingergege/p/5925811.html
	fgets(str, MAXN, stdin);

	//字母大小写转换，初始化map
	for(int i = 0; i < strlen(str); i++){
		if(str[i] >= 'A' && str[i]<= 'Z'){
			str[i] = str[i] - 'A' + 'a'; //大写转小写
			mp[str[i]] += 1;
		}else if(str[i] >= 'a' && str[i]<= 'z'){
			mp[str[i]] += 1;
		}else{
			continue;
		}
	}

	//map里筛选最大次数
	int max = 0;
	char key;
	for(map<char, int>::iterator it = mp.begin(); it != mp.end(); it++){
		if(it -> second > max){
			max = it -> second;
			key = it -> first;
		}
	}

	//打印结果
	printf("%c %d", key, max);

	return 0;
}