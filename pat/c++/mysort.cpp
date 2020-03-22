#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>

using namespace std;

#define LEN 10


struct Person {
	int weight;
};

// 把 mysort 想象成 c++ 内置的 sort 函数
void mysort(Person *s, Person *e, func compare) {
	for(int i = 0; i < LEN; i++){
		int k = i;
		for(int j = i; j <= LEN; j++){
			if(compare(a[j], a[k])){ // structi.age < structj.age
				k = j;
			}
		}
		int t;
		t = a[i];
		a[i] = a[k];
		a[k] = 
	}
}

// --------------------------------------


bool cmp(Person a, Person b) {
	return a.age > b.age;
}

int main(){
	Person a[LEN];
	for(int i=0; i<LEN; i++) {
		Person tmp;
		tmp.age = i;
		a[i] = tmp;
	}

	sort(a, a+LEN, cmp); // sort(start pointer, end pointer, compare callback)

	for(int j = 0; j < LEN; j++){
		printf("%d ", a[j]);
	}
	
	return 0;
}
