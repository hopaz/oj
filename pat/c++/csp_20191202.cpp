#include<stdio.h>
#include<map>
using namespace std;

bool is_valid(map<pair<int, int>, int> mp, pair<int, int> p){
	int s = 
		mp[make_pair(p.first, p.second + 1)] + 
		mp[make_pair(p.first, p.second - 1)] + 
		mp[make_pair(p.first - 1, p.second)] + 
		mp[make_pair(p.first + 1, p.second)];
	return s==4;
}

int get_score(map<pair<int, int>, int> mp, pair<int, int> p){
	//垂直对齐相似代码，避免符号错误
	return 
		mp[make_pair(p.first + 1, p.second + 1)] + 
		mp[make_pair(p.first + 1, p.second - 1)] + 
		mp[make_pair(p.first - 1, p.second + 1)] + 
		mp[make_pair(p.first - 1, p.second - 1)];
}

int main(){
	map <pair<int, int> , int> mp;
	int line_count, s_result[5];
	scanf("%d", &line_count);
	for(int i=0; i < line_count; i++){
		pair<int,int> temp_p;
		scanf("%d %d", temp_p.first, temp_p.second);
		mp[temp_p] = 1;
	}
	
	//map的遍历
	for(map<pair<int, int>, int>::iterator it = mp.begin(); it != mp.end(); it++){
		if(is_valid(mp, it -> first)){
			//switch结构中case值和语句中数组下标一致，switch可省写
			s_result[get_score(mp, it -> first)]++;
		}
	}
	
	//用for循环打印数组
	for(int j = 0; j < 5; j++){
		printf("%d\n", s_result[j]);
	}

	return 0;
}



# version 2
#include<stdio.h>
#include<map>
#include<vector>

using namespace std;

vector<int> mk_vec(int x, int y){
	vector<int> vi;
	vi.push_back(x);
	vi.push_back(y);
	return vi;
}

bool is_valid(map<vector<int>, int> mp, vector<int> vi){
	int s = 
		mp[mk_vec(vi[0], vi[1] + 1)] + 
		mp[mk_vec(vi[0], vi[1] - 1)] + 
		mp[mk_vec(vi[0] - 1, vi[1])] + 
		mp[mk_vec(vi[0] + 1, vi[1])];
	return s==4;
}

int get_score(map<vector<int>, int> mp, vector<int> vi){
	//垂直对齐相似代码，避免符号错误
	return 
		mp[mk_vec(vi[0] + 1, vi[1] + 1)] + 
		mp[mk_vec(vi[0] + 1, vi[1] - 1)] + 
		mp[mk_vec(vi[0] - 1, vi[1] + 1)] + 
		mp[mk_vec(vi[0] - 1, vi[1] - 1)];
}

int main(){
	map <vector<int>, int> mp;
	int line_count; 
	// 这里，数组 s_result 没有初始化，所以 s[0]...s[4] 都是非 0 值，printf 出来就是一个乱七八糟的数字
	// 如果想解决这个问题，可以使用下面的语法代替
	// vector<int> s_result(5, 0); // 意思是，初始长度为5，每个元素的默认值为0
	vector<int> s_result(5, 0);
	scanf("%d", &line_count);
	for(int i=0; i < line_count; i++){
		int x, y;
		scanf("%d %d", &x, &y); // scanf 的参数前要加 &
		mp[mk_vec(x, y)] = 1;
	}
	
	//map的遍历
	for(map<vector<int>, int>::iterator it = mp.begin(); it != mp.end(); it++){
		if(is_valid(mp, it -> first)){
			//switch结构中case值和语句中数组下标一致，switch可省写
			s_result[get_score(mp, it -> first)]++;
		}
	}
	
	//用for循环打印数组
	for(int j = 0; j < 5; j++){
		printf("%d\n", s_result[j]);
	}

	return 0;
}
