#include<stdio.h>
#include<algorithm>

using namespace std;

const int N = 110; 

int n, origin[N], temp_ori[N], changed[N];

bool is_same(int A[], int B[]){
	for(int i = 0; i < n; i++){
		if(A[i] != B[i]){
			return false;
		}
	}
	
	return true;
}

bool insert_sort(){
	bool flag = false; //记录排序过程中是否有和tar相同的结果
	for(int i = 1; i < n; i++){
		if(i != 1 && is_same(temp_ori, changed)){
			flag = true;
		}
		
		//插入排序
		int temp = temp_ori[i], j = i;
		while(j > 0 && temp_ori[j - 1] > temp){
			temp_ori[j] = temp_ori[j - 1];
			j--;
		}
		temp_ori[j] = temp;
		if(flag == true){
			return true;
		}	
	}
	return false;
}

void show_array(int a[]){
	for(int i = 0; i < n; i++){
		if(i < n - 1){
			printf("%d ", a[i]);
		}else{
			printf("%d\n", a[i]);
		}
	}
}

void merge_sort(){
	bool flag = false;
	//归并排序
	for(int step = 2; step / 2 <= n; step *= 2){
		if(step != 2 && is_same(temp_ori, changed)){
			flag = true;
		}
		for(int i = 0; i < n; i += step){
			sort(temp_ori + i, temp_ori + __min(i + step, n));
		}
		if(flag == true){
			show_array(temp_ori);
			return;
		}
	} 
}

int main(){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &origin[i]);
		temp_ori[i] = origin[i];
	}

	for(int j = 0; j < n; j++){
		scanf("%d", &changed[j]);
	}

	//insert排序，检查是否一致
	if(insert_sort()){
		printf("Insertion Sort\n");
		show_array(temp_ori);
	}else{
	//不一致则为merge排序
		printf("Merge Sort\n");
		for(int i = 0; i < n; i++){
			temp_ori[i] = origin[i]; 
		} 
		merge_sort();
	}

	return 0;

}