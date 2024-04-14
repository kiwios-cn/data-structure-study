#include <stdio.h>
void test(int *sum){
  int x;
  *sum = 0;
  do{
    scanf("%d",&x);
    *sum+=x;
  }while(x);
  printf("%d",*sum);
}


int main()
{
    SqStack Astack;
    InitStack(&Astack);
    char c;
    printf("请输入括号字符,回车结束");
    do
    {
        scanf("%c",&c);
        if(c=='('||c==')'||c=='{'||c=='}'||c=='['||c==']')
        {
            Push(&Astack,c);
      		 while((Astack.top)!=(Astack.base)&&(Astack.top-1)!=(Astack.base)
            &&*(Astack.top-1)-*(Astack.top-2)>0
            &&*(Astack.top-1)-*(Astack.top-2)<3)
            {
                Pop(&Astack,&c);Pop(&Astack,&c);
            }
        }
    }while(c!='\n');
    
  if(Astack.top==Astack.base)
    {
        printf("括号字符合法");
    }
    else
    {
        printf("括号字符不合法");
    }
}

int orderDetermination(char e)
{
    switch (e)
    {
        case '+':return 1;
        case '-':return 1;
        case '*':return 2;
        case '/':return 2;
        default :return 0;
    }
}

int main()
{
    SqStack operationalMode;
    SqStack outPut;
    InitStack(&operationalMode);InitStack(&outPut);
    char e,c;
    printf("请输入正确表达式,回车结束:");
    while(1)
    {
        scanf("%c",&e);
        if(e=='\n')
        {
            break;
        }
        if((e>='a'&&e<='z')||(e>='A'&&e<='Z'))
        {
            Push(&outPut,e);
        }
        else
        {
            while(operationalMode.top!=operationalMode.base&&
orderDetermination(*(operationalMode.top-1))>=orderDetermination(e)&&
orderDetermination(e))
            {
                Pop(&operationalMode,&c);Push(&outPut,c);
            }
            Push(&operationalMode,e);
            if(operationalMode.top!=operationalMode.base&&
*(operationalMode.top-1)==')')
            {
                Pop(&operationalMode,&c);
                while(operationalMode.top!=operationalMode.base&&
*(operationalMode.top-1)!='(')
                {
                    Pop(&operationalMode,&c);Push(&outPut,c);
                }
                Pop(&operationalMode,&c);
            }
        }
    }
    while(operationalMode.top!=operationalMode.base)
    {
        Pop(&operationalMode,&c);Push(&outPut,c);
    }
    ShowStack(&outPut);
}

 
void initQueue(Queue *q) {
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
}

int enqueue(Queue *q, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        return 0;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (q->tail == NULL) {
        q->head = newNode;
        q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
    q->size++;

    return 1;
}
int dequeue(Queue *q, int *data) {
    if (q->tail == NULL) {
        return 0;
    }
    Node *temp = q->head;
    *data = temp->data;

    q->head = q->head->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }

    free(temp); 
    q->size--;

    return 1;
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    int data;
    while (q.size > 0) {
        if (dequeue(&q, &data)) {
            printf("%d ", data);
        }
    }
    return 0;
}
