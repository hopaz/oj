#include<stdio.h>
#include<string.h>
#include<map>
#include<vector>

using namespace std;

const int MAXN = 1010;
int main(){
	map<char, int> mp_prvd, mp_want;
	char c_prvd[MAXN], c_want[MAXN];

	scanf("%s\n%s", c_prvd, c_want);
	
	for(int i = 0; i < strlen(c_prvd); i++){
		mp_prvd[c_prvd[i]] += 1;
	}

	for(int j = 0; j < strlen(c_want); j++){
		mp_want[c_want[j]] +=1;
	}

	int fail = 0;
	//遍历map用it， 且it->first是key，可以用于另外一个map的查询条件
	for(map<char, int>::iterator it = mp_want.begin(); it != mp_want.end(); it++){
		if(mp_want[it -> first] <= mp_prvd[it -> first]){
			continue;
		}else{
			fail = fail + (mp_want[it -> first] - mp_prvd[it -> first]);
		}
	}

	if(fail == 0){
		printf("Yes %d",  strlen(c_prvd) - strlen(c_want));
	}else{
		printf("No %d", fail);
	}

	return 0;
}