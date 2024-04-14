#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
  int data;
  struct LNode *next;
}LNode , *LinkList ;

LinkList  new_node(int data) {
  
  LinkList  node = (LinkList) malloc(sizeof(LNode)); 
  node->data = data;
  node->next = NULL; 

  return node;
}//创建新结点

void create_single_List(LinkList *L, int n) {
  
  int *num = (int *)malloc(n * sizeof(int));
  for(int i = 0 ; i < n ; i++) {
    printf("请输入第%d个元素:",i+1);
    scanf("%d",&num[i]);
    
    LinkList node = new_node(num[i]);
    
    if (*L == NULL) {
      *L = node;
    } else {
      LinkList p = *L;
      while(p->next != NULL){
        p = p->next;
      }
      p->next = node;
      node->next = NULL;
    }  
  }

  // while((*L) != NULL) {
  //   printf("--->%d\n", (*L)->data);
  //   *L = (*L)-> next;
  // }
}//创建单链表

void reverse_method1(LinkList *head) {
  LinkList p = (*head)->next;
  (*head)->next = NULL;
  while(p){
    LinkList q = p;
    p = p->next;
    q->next = (*head)->next;
    (*head)->next = q;
  }
  LinkList q = (*head)->next;
  while(q){
    printf(" %d",q->data);
    q = q->next;
  }
  printf("\n");
}//头插法逆置

void reverse_method2(LinkList *head) {
  LinkList p = NULL;
  LinkList q = *head;
  LinkList r;
  while(q){
    r = q;
    q = q->next;
    r->next = p;
    p = r;
  }
  LinkList s = r;
  while(s->next){
    printf(" %d",s->data);
    s = s->next;
  }
  printf("\n");
}//就地逆置

void search_middle(LinkList *head){
  LinkList fast = (*head);
  LinkList slow = (*head);
  while(fast && fast->next){
    fast = fast->next->next;
    slow = slow->next;
  }
  printf("%d\n",slow->data);
}//快慢指针法找中点

void search_k_node(LinkList *head, int k){
  LinkList fast = *head;
  LinkList slow = *head;

  for(int i = 0 ; i < k ; i++){
    fast = fast->next;
  }
  while (fast) {
    fast = fast->next;
    slow = slow->next;
  }
  printf("%d\n",slow->data);
}//快慢指针法找倒数第k个点

void delete_k_node(LinkList *head, int k){
  LinkList fast = *head;
  LinkList slow = *head;

  for(int i = 0 ; i < k ; i++){
    fast = fast->next;
  }
  while (fast) {
    fast = fast->next;
    slow = slow->next;
  }
  slow = slow -> next;
  printf("%d\n",slow->data);
}//删除倒数第k个结点


void create_single_List_with_cycle(LinkList *L, int n) {
  
  int *num = (int *)malloc(n * sizeof(int));
  for(int i = 0 ; i < n ; i++) {
    printf("请输入第%d个元素:",i+1);
    scanf("%d",&num[i]);
    
    LinkList node = new_node(num[i]);
    
    if (*L == NULL) {
      *L = node;
    } else {
      LinkList p = *L;
      while(p->next != NULL){
        p = p->next;
      }
      p->next = node;
      node->next = NULL;
      if(i == n-1){
        LinkList q = *L;
        int k = 0;
        while(k < n/2) {
          q = q->next;
          k++;
        }
        node->next = q;
      }
    }  
  }

}//创建有环单链表
void judge_the_cycle_and_entrance(LinkList *head){
  LinkList fast = *head;
  LinkList slow = *head;
  do {
    
    fast = fast->next->next;
    slow = slow->next;
    if(fast == NULL || slow == NULL){
      printf("无环");
      break;
    }
  } while(fast != slow); 
  
  fast = *head;
  int num = 0;
  while(fast!=slow){
    fast = fast -> next;
    slow = slow -> next;
    num++;
  }
  printf("环的入口是第%d个结点\n",num);
}//判断是否有环及环的入口

void create_intersect_linklist(LinkList *head1 , LinkList *head2 , int length1 ){
  LinkList p = *head1;
  LinkList q = *head2;
  while(q->next){
    q = q->next;
  }
  int i = 0; 
  while(i<length1/2){
    p = p->next;
    i++;
  }
  q->next = p;
}//创建相交的两条单链表
void judge_intersect_node(LinkList *head1 , LinkList *head2){
  LinkList q = *head1;
  while(q->next){
    q = q->next;
  }
  q->next = (*head2)->next;
  judge_the_cycle_and_entrance(head1);
  printf("环的结点即为链表的交点\n");
}
void delete_same_noleft(LinkList *head){
  
  LinkList pre = NULL;
  LinkList cur = *head;
  LinkList next = (*head)->next;

  while (next) {
    
    if(cur->data != next->data){
      
      pre = cur;
      cur = next;
      next = next->next;
    
    } else {
      
      while (next && cur->data == next->data) {
        
        next = next->next;      
      
      }
      
      if(pre){
        
        pre->next = next;
      
      } else {
        
        *head = next;
      
      }   
      
      cur = next;

      if(next){
        
        next = next->next;
      
      }    
    }
  }
  LinkList p = (*head)->next;
  
  while (p) {
    printf(" %d",p->data);
    p = p->next;
  }
  printf("\n");






  
}












void joseph_problem(LinkList *L , int n) {

}
int main() {
  LinkList head1 = (LinkList) malloc(sizeof(LNode));
  LinkList head2 = (LinkList) malloc(sizeof(LNode));
  
  head1->data = 0;
  head2->data = 0;
  
  int num1 = 0 ;
  int num2 = 0 ;
  
  int k = 0;
  
  LinkList L1 = NULL;
  printf("请输入单链表存储数据的个数:");
  scanf("%d",&num1);
  create_single_List(&L1,num1);
  // create_single_List_with_cycle(&L,num);
  
  LinkList L2 = NULL;
  printf("请输入单链表存储数据的个数:");
  scanf("%d",&num2);
  create_single_List(&L2,num2);
  
  head1->next = L1;
  head2->next = L2;
  delete_same_noleft(&head1);
  // create_intersect_linklist(&head1,&head2,num1);
  // judge_intersect_node(&head1,&head2);
  //reverse_method2(&head);
  // search_middle(&head);
  // printf("请输入要查找倒数第几个节点:");
  // scanf("%d",&k);
  // search_k_node(&head, k);
  //judge_the_cycle_and_entrance(&head);
}
