#include <math.h>
#include<stdio.h>
#include <stdlib.h>
#define OK 1 
#define ERROR 0;
#define LIST_INIT_SIZE  100
#define LISTINCREMENT    10

typedef struct {
  int *elem;
  int length;
  int listsize;
} SqList ;

int InitList_Sq ( SqList *L) {
  L->elem = (int *)malloc( LIST_INIT_SIZE * sizeof(int) ); 
  if( ! L->elem) {
    exit(OVERFLOW); 
  }
  L -> length = 0;
  L -> listsize = LIST_INIT_SIZE;
  return OK;

}

int ListInsert_Sq ( SqList *L  , int i , int e) {
  if(i < 1 || i > L->length + 1) {
    return ERROR;
  }
  if(L->length >= L->listsize) {
    int *newbase = (int *)realloc(L->elem , (L->listsize + LISTINCREMENT) * sizeof(int));
    if(! newbase) {
      exit(OVERFLOW);
    }
    L->elem = newbase;
    L->listsize += LISTINCREMENT;
  }
  int *q = &(L->elem[i-1]);
  for (int *p = &(L->elem[L->length-1]); p >= q ; --p) {
    *(p+1) = *p;
  }
  *q = e;
  ++L->length;
  return OK;
  
}//插入函数

int ListDelete_Sq (SqList *L , int i , int *e) {
  if(i < 1 || i > L->length) {
    return ERROR;
  }
  int *p = &(L->elem[i-1]);
  *e = *p;
  int *q = L->elem + L->length -1 ;
  for( ++p ; p <= q ; ++p) {
    *(p-1) = *p;
  } 
  --L->length;
  return OK;

}//删除函数

int LocateElem_Sq( SqList *L , int e , int (*compare)(int ,int)) {
  int i = 1;
  int *p = L->elem;
  while ( i <= L->length && !( * compare)(*p++ , e)) {
    ++i;
  }
  if( i <= L->length) {
    return i;
  } else {
    return 0;
  }
}//定位函数

void MergeList_Sq(SqList La , SqList Lb , SqList *Lc) {
  int *pa = La.elem;
  int *pb = Lb.elem;
  Lc->listsize = Lc->length = La.length + Lb.length;
  int *pc = Lc->elem = (int *)malloc(Lc->listsize*sizeof(int));
  if(!Lc->elem) {
    exit(OVERFLOW);
  }
  int *pa_last = La.elem + La.length - 1;
  int *pb_last = Lb.elem + Lb.length - 1;
  while (pa <= pa_last && pb <= pb_last) {
    if(*pa <= *pb) {
      *pc++ = *pa++;//先取值，再对指针自增
    } else {
      *pc++ = *pb++;
    }
  }
  while (pa <= pa_last) {
    *pc++ = *pa++; 
  }
  while (pb <= pb_last) {
    *pc++ = *pb++;
  }

}//顺序表的合并
