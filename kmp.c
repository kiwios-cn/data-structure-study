#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void kmp (char *s , char *t , int* next){
  int s_len = strlen(s);
  int t_len = strlen(t);
  int j = 0;
  for(int i = 0 ; i < s_len ; i++) {
    if(s[i] == t[j]){
      j++;
    } else {
      if (j == 0) {
        j = next[0];
      } else {
        j = next[j-1];
      }
    }
    if(j == t_len){
      printf("%d~%d\n",i-j+1,i+1);
      break;
    } 
  }
  if(j != t_len){
    printf("失败");
  }  
}

int * get_next(char *source){
  int *next = (int*)malloc(sizeof(int)*10);
  for (int i = 0; i < strlen(source); i++) {
    if (i == 0) {
      next[0] = 0;
    } else {
      if (next[i-1] == 0&&source[0] == source[i]) {
        next[i] = 1;
      } else if(next[i-1] == 0 && source[0] != source [i]) {
        next[i] = 0;
      } else if(next[i-1] != 0 && source[i] == source[next[i-1]]) {
        next[i] = next[i-1] + 1;
      } else if(next[i-1] != 0 && source[i] != source[next[i-1]]){
        next[i] = 0;
      }
      
    }
  }
  for(int i = 0 ; i < 10 ; i++){
    printf(" %d",next[i]);
  }  
  return next;  
}

int main(){
  char s[14] = "ababcabcacbab";
  char t[6] = "abcac";
  
  int *next = get_next(t);

  kmp(s, t, next);



  free(next);
  return 0;
}
