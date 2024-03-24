#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE    8  
#define LISTINCREMENT    10

typedef struct{
  int *elem;
  int length;
  int listsize;
  
} Sqlist;


void create(Sqlist *L){
  (*L).elem = (int*)malloc(LIST_INIT_SIZE*sizeof(int));
  (*L).length = 0;
  (*L).listsize = LIST_INIT_SIZE;
  for(int i = 0 ; i < LIST_INIT_SIZE ; i++) {
    printf("请输入第%d个元素：",i+1);
      scanf("%d",&(*L).elem[i]);    
  }
  printf("\n输入完成\n");
  for(int j = 0 ; j < LIST_INIT_SIZE ; j++) {
    printf(" %d",(*L).elem[j]);
  }
  printf("\n打印完成\n");
}

void delete_the_same(Sqlist *L){
  int i = 0 ;
  int length_replace = LIST_INIT_SIZE;
  
  while(i+1 < length_replace){
    
    if((*L).elem[i] != (*L).elem[i+1]) {
      
      i++;
    
    } else {
      
      for(int j = i ;j<length_replace-1;j++){
        
        (*L).elem[j] = (*L).elem[j+1];
      
      }
      length_replace--;
    }
  
  }
  
  for(int j = 0 ; j < length_replace ; j++) {
  
    printf(" %d",(*L).elem[j]);
  
  }
  printf("\n");  

}

void delete_0(Sqlist *L){
  int i = 0 ;
  int length_replace = LIST_INIT_SIZE;

  while(i < length_replace){

    if((*L).elem[i] != 0 ) {
      
      i++;
    
    } else {
      
      for(int j = i ; j < length_replace-1 ; j++) {
        
        (*L).elem[j] = (*L).elem[j+1];
      
      }
      length_replace--;
    }
  }
  
  for(int j = 0 ; j < length_replace ; j++){
    
    printf(" %d" , (*L).elem[j]);
  
  }
  
  printf("\n");

}
void bubble_sort(Sqlist *L) {
  for(int i = 0 ; i < LIST_INIT_SIZE - 1 ; i++ ){
    
    for(int j = 0 ; j < LIST_INIT_SIZE - i - 1 ; j++ ) {
      
      if((*L).elem[j] > (*L).elem[j+1]) {
        
        int tmp = (*L).elem[j];
        (*L).elem[j] = (*L).elem[j+1];
        (*L).elem[j+1] = tmp;
      
      }
    }
  }
  
  for(int k = 0 ; k < LIST_INIT_SIZE ; k++) {
    
    printf(" %d", (*L).elem[k]);
  
  }
  printf("\n");
}

void insert_list (Sqlist *L) {
  int pos,data;
  printf("当前线性表的长度为%d\n",LIST_INIT_SIZE);
  
  printf("请输入代插入元素的位置:");
  scanf("%d",&pos);
  
  printf("请输入代插入元素的值:");  
  scanf("%d",&data);
  
  int *newbase = (int *)realloc((*L).elem,((*L).listsize+1)*sizeof(int)) ;    
  (*L).elem = newbase;
  (*L).listsize += 1;
  
  for(int i = (*L).listsize-1 ; i >= pos ; i--) {
    (*L).elem[i] = (*L).elem[i-1];
  }
  (*L).elem[pos-1] = data;
  
  for(int j = 0 ; j < (*L).listsize ; j++ ) {
    printf(" %d",(*L).elem[j]);
  }
  
  printf("\n");

}

void select_sort(Sqlist *L) {
  for(int i = 0 ; i < LIST_INIT_SIZE-1 ; i++ ) {
    int min = i;
    for(int j = i + 1 ; j < LIST_INIT_SIZE ; j++) {
      if((*L).elem[j]<=(*L).elem[min]){
        min = j;
      }
    }
    int tmp = (*L).elem[min];
    (*L).elem[min] = (*L).elem[i];
    (*L).elem[i] = tmp;
  }
  for(int k = 0 ; k < LIST_INIT_SIZE ; k++ ) {
    printf(" %d",(*L).elem[k]);
  }
  printf("\n");
}


void insert_sort(Sqlist *L) {
  for(int i = 1 ; i < LIST_INIT_SIZE ; i++) {
    int key = (*L).elem[i];
    int j = i-1;
    while( (j>=0) && (key<(*L).elem[j]) ){
      (*L).elem[j+1] = (*L).elem[j];
      j--;
    }
    (*L).elem[j+1] = key; 
  }  
  for(int k = 0 ; k < LIST_INIT_SIZE ; k++){    
    printf(" %d", (*L).elem[k]);
  }
  printf("\n");
}

void pattern_match(Sqlist *L){
  int len; 
  int *s;
  printf("请输入待匹配子串的长度:");
  scanf("%d", &len);
  for(int i = 0 ; i < len ; i++){
    printf("请输入第%d个元素:",i+1);
    scanf("%d",s+i);
  }
  for(int i = 0 ; i < len ; i++){
    printf(" %d",*(s+i));
  }
  printf("\n");
  for(int i = 0 ; i < LIST_INIT_SIZE ; i++) {
    int j = 0 ;
    int k = i ;
    while(((*L).elem[k] == *(s+j))&&(k<LIST_INIT_SIZE)&&(j<=2)){
      k++ , j++;
    }
    if(j == 3) {
      printf("从第%d个位置到第%d个位置\n", i+1 , i+j);
    }
  } 
  printf("\n");
}
int main(){
  Sqlist L;
  create(&L);
//  delete_the_same(&L);
//  delete_0(&L);
//  bubble_sort(&L);
//  insert_list(&L);
//  select_sort(&L);
//  insert_sort(&L);
  pattern_match(&L);
}
