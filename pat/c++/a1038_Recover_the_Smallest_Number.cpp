#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>

using namespace std;

const int LEN = 10010;

bool cmp(string a, string b){
	return a + b < b + a;
}

int main(){
	string str[LEN];
	int N;
	cin >> N; //cin/cout不能与scanf/printf在同一个文件中使用
	for(int i = 0; i < N; i++){
		cin >> str[i];
	}
	
	sort(str, str + N, cmp);

	string ans;
	for(int j = 0; j < N; j++){
		ans += str[j];
	}
	
	while(ans.size() != 0 && ans[0] == '0'){
		ans.erase(ans.begin()); //去除前导0
	}

	if(ans.size() == 0){
		cout << 0;
	}else{
		cout << ans;
	}

	return 0;
}