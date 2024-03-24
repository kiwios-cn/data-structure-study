#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
  int data;
  struct LNode *next;
}LNode , *LinkList ;

void create_List(LinkList *L, int n) {
  
  *L = (LinkList)malloc(sizeof(LNode));
  (*L)->next = NULL;
  LinkList rnode = *L;
  for(int i = 0 ; i < n ; i++) {
    
    LinkList p = (LinkList)malloc(sizeof(LNode));
    printf("请输入第%d个元素:",i+1);
    scanf("%d",&p->data);

    p->next = NULL;
    rnode->next = p;
    rnode = p;     
  
  }
}
void show (LinkList *L,int n ){
  LinkList replace = *L;
  for(int i = 0 ; i < n+1 ; i++) {
    printf(" %d",replace->data);
    replace = replace->next;
  }
  printf("\n");
}
void reverse_method1(LinkList *L) {
  //头插法
  LinkList p = (*L)->next;
  (*L)->next = NULL;
  while(p){
    LinkList q = p;
    p = p->next;
    q->next = (*L)->next;
    (*L)->next = q;
  }
}
void reverse_method2(LinkList *L) {
  //就地逆置
}
int main() {
  LinkList L;
  create_List(&L,8);
  show(&L,8 );
  reverse_method1(&L);
  show(&L , 8);
}
