#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_null.h>
#define ERROR 0
#define OK 1
typedef struct LNode {
  
  int data ;
  
  struct LNode *next;
  
} LNode, *LinkList;
//Linklist为结构指针型变量,typedef  struct LNode{}*  LinkList

int GetElem_L(LinkList L , int i , int *e) {
//L为带头结点的单链表的头指针
//函数功能：当第i个元素存在时，将其值赋给e并返回OK，否则返回ERROR
  
  LinkList p = L ->next ;//p为指向第一个结点的指针
  
  int j = 1;//起到计数器的作用
  
  while(p && j<i) {

    p = p->next;
    j++;
    
  }
  
  if(!p||j>i) {
    
    return ERROR;
  
  } else {

    *e = p->data;
    return OK;
  }

}

int ListInsert_L(LinkList *L , int i , int e){
  //函数功能：在带有头结点的单链线性表L中第i个位置之前插入元素e
  LinkList p = *L;
  int j = 0;

  while( p && j < i - 1 ) {//寻找第i-1个结点

    p = p -> next;

    j++;
  
  }

  if( !p || j > i-1 ) {

    return ERROR;
  
  } else {

    LinkList s = (LinkList)malloc(sizeof(LNode));

    s->data = e;

    s->next = p->next;
    p->next = s;

    return OK;
  
  }
 
}

int ListDelete_L(LinkList *L , int i , int *e){
//函数功能：在带有头结点的单链线性表L中，删除第i个元素，并由e返回其值
  LinkList p = *L;
  int j = 0;

  while( p->next && j < i-1 ) {
    
    p = p->next;
    j++;
  
  }

  if(!(p->next)||j>i-1){
    
    return ERROR;
  
  } else {

    LinkList q = p->next;
    
    p->next = q->next;  
  
    *e = q->data;

    free(q); //通常删除完后要释放内存
  
    return OK;
  
  }

}

void CreateList_L(LinkList *L , int n) {
  //函数功能：逆位序输入n个元素的值，建立带表头结点的单链线性表L

  *L = (LinkList)malloc(sizeof(LNode));

  (*L) -> next = NULL;

  for(int i = n ; i > 0 ; i--) {

    LinkList p = (LinkList)malloc(sizeof(LNode));

    scanf("%d",&(p->data));

    p->next = (*L)->next;
    (*L)->next = p;
  
  }  
  
}

void MergeList_L(LinkList *La , LinkList *Lb , LinkList *Lc) {
  //已知单链线性表La和Lb的元素按值非递减排列
  //归并La和Lb得到新的单链线性表Lc，其中的元素也按值非递减排列
  LinkList pa = (*La)->next;
  LinkList pb = (*Lb)->next;
  LinkList pc = *La = *Lc;

  while(pa&&pb){

    if(pa->data <= pb->data){
        
      pc->next = pa ;
      pc = pa;
      pa = pa->next;
    
    } else {

      pc->next = pb;
      pc = pb;
      pb = pb->next;
      
    }
  }

  pc->next = pa ? pa : pb;

  free(Lb);
}
