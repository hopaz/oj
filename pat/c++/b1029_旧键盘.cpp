#include<stdio.h>
#include<string.h>


int main(){
  char exp[100], act[100];
  bool hashMap[128] = {false};
  scanf("%s\n%s", exp, act);
  
  for(int i = 0; i < strlen(exp); i++){
    int j;
    char c1 = exp[i];
    //大小写转换
    if(c1 >= 'a' && c1 <= 'z'){ c1 -= 32;}
    for(j = 0; j < strlen(act); j++){
      char c2 = act[j];
      if(c2>= 'a' && c2 <= 'z'){ c2 -= 32;}
      if(c1 == c2){ break; }
    }
    //字符串2全部结束，且字符未输出过
    if(j == strlen(act) && hashMap[c1] == false){
      printf("%c", c1);
      hashMap[c1] = true;
    }
  }
  
  return 0;
}




#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

using namespace std;

char toupper(char c) {
  if (c >= 'a' && c <= 'z') {
    return c - ('a' - 'A');
  }
  return c;
}

int main(){
  map< char, bool > mkey;
  map< char, bool > ckey;
  
  //两行字符串的输入
  char expect[1000000], input[1000000];
  scanf("%s\n%s", expect, input);
  
  {
    for (int i=0; i < 1000000 && input[i] != '\n'; i++) {
      char k = toupper(input[i]);
      mkey[k] = true;
    }
  }
  
  {
    for (int i=0; i < 1000000 && expect[i] != '\n'; i++) {
      char k = toupper(expect[i]);
      if (!mkey[k] && !ckey[k]) {
        printf("%c", k);
      }
      ckey[k] = true;
    }
  }
  
  return 0;
}