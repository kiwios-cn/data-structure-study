
#include<stdio.h>
#include<stdlib.h>
#define  LIST_INIT_SIZE 10
typedef struct node
{
    char data;
    struct node *next;
} node ;

typedef node *LinkList;

typedef struct{
    int *elem;
    int length;
    int listsize;
}SqList ;

SqList* build_S(SqList *L, int n)
{
    (*L).length = n;
    (*L).elem = (int *)malloc(LIST_INIT_SIZE*sizeof(int));
    printf("请输入线性表的数据：");
    for(int i = 0 ; i < n ; i++) {
        scanf("%d",&(*L).elem[i]);
    }
    return L; 
}
void display_S(SqList L,int n ){
    for(int i = 0 ; i < n ; i++) {
        printf(" %d",L.elem[i]);
    }
    printf("\n");
}
LinkList build_T(int n)   //µ•¡¥±ÌŒ≤≤Â∑®
{
    node *p,*head;
    int i;
    head=(LinkList)malloc(sizeof(node));
    p=head;
    for( i=1; i<=n; i++)
    {
        p->next=(LinkList)malloc(sizeof(node));
        p->next->data=i+'a'-1;
        p=p->next;
    }
    p->next=NULL;
    return(head);
}

LinkList build_H(int n)   //µ•¡¥±ÌŒ≤≤Â∑®
{
    node *p;
    LinkList  head;
    int i;
    head=(LinkList)malloc(sizeof(node));
    head->next=NULL;
    for( i=1; i<=n; i++)
    {
        p=(LinkList)malloc(sizeof(node));
        p->data=i+'a'-1;
        p->next=head->next;
        head->next=p;
    }
    return(head);
}


void display(LinkList L)
{
    node *p;
    p=L->next;
    while (p!=NULL)
    {
        printf("%c  ",p->data);
        p=p->next;
    }
    printf("\n");
}

void reverse1(LinkList *L)
{
    node *p,*q,*r;
    p=(*L)->next;
    if(p==NULL)
    {printf("No reverse needed!\n");
        return;
    }
    q=p->next;
    p->next=NULL;
    while(q!=NULL)
    {
        r=q->next;
        q->next=p;
        p=q;
        q=r;
    }
    (*L)->next=p;
}

void reverse2(LinkList *L)
{
    node *p,*q,*r;
    p=(*L)->next;
    if(p==NULL||p->next==NULL)
    {printf("No reverse needed!\n");
        return;
    }
    q=p->next;
    p->next=NULL;
    while(q!=NULL)
    {
        r=q->next;
        q->next=(*L)->next;
        (*L)->next=q;
        q=r;
    }
}

void reverse3(SqList L , int n) {
    for(int i = 0 ; i < n/2 ; i++) {
        int temp = L.elem[i];
        L.elem[i] = L.elem[n-i-1];
        L.elem[n-i-1] = temp;        
    }
}

void delete_element(LinkList L)
{
    LinkList pre = L, p = L->next ,r;
    char mink = 'd' , maxk = 'x';
    while ( p ) {
        if(p->data > mink && p->data < maxk) {
            r = p->next;
            pre->next = p->next;
            free(p);
            p = r;
        } else {
            pre = p;
            p = p -> next;
        }
    }
    
}

void combine_L(LinkList *La , LinkList *Lb,LinkList *Lc){
    LinkList pa = (*La)->next;
    LinkList pb = (*Lb)->next;
    LinkList pc;
    *Lc = pc = *La;
    while(pa&&pb){
        if(pa->data <= pb->data) {
            pc->next = pa; 
            pc = pa ;
            pa = pa->next; 
        } else {
            pc->next = pb;
            pc = pb ;
            pb = pb->next;
        }
    }
    pc->next = pa?pa:pb;
    
}
/*void delete_same(SqList *La , SqList *Lb , SqList *Lc , int length_La , int length_Lb , int length_Lc) {
    int i = 0 , j = 0 , k = 0;
    for( i = 0 ; i < length_La ; i++){
        while((*La).elem[i] != (*Lb).elem[j] && (*La).elem[i] != (*Lc).elem[k]){
            j++;k++;
            if(j == length_Lb||k == length_Lc){
                break;
            }
        }
        while((*La).elem[i] != (*Lb).elem[j] && (*La).elem[i] == (*Lc).elem[k]){
            j++;
            if(j == length_Lb){
                break;
            }
        }
        while((*La).elem[i] == (*Lb).elem[j] && (*La).elem[i] != (*Lc).elem[k]){
            k++;
            if(k == length_Lc){
                break;
            }
        }
        if((*La).elem[i] == (*Lb).elem[j] && (*La).elem[i] == (*Lc).elem[k]){
            while((i+1)<length_La){
                (*La).elem[i] = (*La).elem[i+1];                
            }
        }    
    }
}*/
void delete_list(SqList *L, int e){
    int *p , *q;
    for(int i = 0 ; i < (*L).length ; i++ ){
        if((*L).elem[i]==e){
            p = &(*L).elem[i];
            q = (*L).length+(*L).elem-1;
            for(++p;p <= q ; ++p) {
                *(p-1) = *p;
            }
            (*L).length--;
        }
    }
}
void searchlist(SqList *La , SqList Lb , SqList Lc){
    int i = 0 , j = 0 ;
    for(i = 0 ; i<Lb.length ; i++){
        for(j = 0 ; j < Lc.length ; j++){
            if(Lb.elem[i]==Lc.elem[j]){
                delete_list(La,Lb.elem[i]);
            }
        }
    }


}
void ListMinus(LinkList *A , LinkList *B , LinkList *C){
    LinkList pa , pb , pc , temp;
    pa = (*A)->next ;
    pb = (*B)->next ;
    pc = (*C)->next ;
    temp = *A;
    while(pa&&pa&&pc){
        if(pa->data == pc->data){
            while(pa){
                if(pa->data < pb->data) {
                    temp = temp->next;
                    pa = pa->next;
                } else if(pa->data == pb->data) {
                    temp -> next = pa->next;
                    free(pa);
                    pa = temp -> next;
                    pb = pb->next;
                    pc = pc->next;
                    break;
                }else if(pa->data > pb->data) {
                    pb = pb->next;
                    pc = pc->next;
                    break;
                }
            }
        } else if (pb->data < pc->data) {
            pb = pb->next;
        } else {
            pc = pc->next;
        }
    }
} 




    
int main(){
    LinkList L1,La,Lb,Lc;
    Lc = (LinkList)malloc(sizeof(node));
    SqList L2,L3,L4;
    L1 = build_H(26);
    La = build_H(10);
    Lb = build_H(20);
    /*build_S(&L2,8);
    build_S(&L3,4);
    build_S(&L4,10);
    printf("L1:");
    display(L1);
    reverse1(&L1);
    printf("L1:");
    display(L1);
    delete_element(L1);
    printf("L1:");
    display(L1);*/
    /*reverse1(&La);
    reverse1(&Lb);*/
    //display_S(L2,8);
    /*reverse3(L2, 8);
    display_S(L2,8);
    display(La);
    display(Lb);
    combine_L(&La, &Lb ,&Lc);
    reverse1(&Lc);
    display(Lc);
    display_S( L3,4 );
    display_S(L4,10 );
    searchlist( &L2 , L3 , L4 );
    display_S( L2 , 4 );*/
    reverse1(&L1);
    reverse1(&La);
    reverse1(&Lb);
    display(L1);
    display(La);
    display(Lb);
    ListMinus( &L1, &La , &Lb);
    display(L1);
}
