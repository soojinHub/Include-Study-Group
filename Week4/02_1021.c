//정답
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * next;
    struct node *prev;
}Node;

typedef struct deque{
    Node* head;
    Node* tail;
}Deque;

void DQinit(Deque *pdeq);
int DQisEmpty(Deque *pdeq);

void DQaddFirst(Deque *pdeq, int data);
void DQaddLast(Deque *pdeq, int data);

int DQremoveFirst(Deque *pdeq);
int DQremoveLast(Deque *pdeq);

int findMin(Deque *pdeq, int target, int *front, int *back);

int main(void){
    int n, m, mlist[50], returnMin, front=0, back=0, rotation=0;
    scanf("%d %d", &n, &m);

    Deque q;
    DQinit(&q);

    for (int i = 1; i<=n; i++){
        DQaddLast(&q, i);
    }
    for(int i =0; i<m; i++){
        scanf("%d", &mlist[i]);
    }

    for(int i=0; i<m; i++){
        if(q.head->data!=mlist[i]){
            returnMin = findMin(&q, mlist[i], &front, &back);
            if(front) while(returnMin--)DQaddLast(&q, DQremoveFirst(&q)), ++rotation;
            else if (back) while(returnMin--)DQaddFirst(&q, DQremoveLast(&q)), ++rotation;
        }
        DQremoveFirst(&q);
    }

    printf("%d", rotation);

    return 0;
}

void DQinit(Deque * pdeq){
    pdeq->head = NULL;
    pdeq->tail = NULL;
}

int DQisEmpty(Deque * pdeq){
    if (pdeq->head ==NULL) return 1;
    else return 0;
}

void DQaddFirst(Deque* pdeq, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = pdeq->head;

    if(DQisEmpty(pdeq))
        pdeq->tail = newNode;
    else
        pdeq->head->prev=newNode;
    
    newNode->prev = NULL;
    pdeq->head = newNode;
}

void DQaddLast(Deque* pdeq, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->prev = pdeq->tail;
    if(DQisEmpty(pdeq))
        pdeq->head = newNode;
    else
        pdeq->tail->next = newNode;

    newNode->next = NULL;
    pdeq->tail = newNode;    
}

int DQremoveFirst(Deque * pdeq){
    Node * rnode = pdeq->head;
    int rdata=pdeq->head->data;
    pdeq->head=pdeq->head->next;
    free(rnode);

    if(pdeq->head == NULL)
        pdeq->tail == NULL;
    else
        pdeq->head->prev= NULL;
    
    return rdata;
}

int DQremoveLast(Deque* pdeq){
    Node * rnode = pdeq->tail;
    int rdata=pdeq->tail->data;
    pdeq->tail=pdeq->tail->prev;
    free(rnode);

    if(pdeq->tail==NULL)
        pdeq->head = NULL;
    else
        pdeq->tail->next=NULL;

    return rdata;
}


int findMin(Deque *pdeq, int target, int *front, int *back){
    pdeq->head->prev = pdeq->tail;
    pdeq->tail->next = pdeq->head;

    int findFront = 0, findBack =0;
    Node* temp = pdeq->head;
    while(temp->data!=target) {
        temp = temp->next; 
        ++findFront;
        }
    temp = pdeq->head;
    while(temp->data!=target) {
        temp = temp->prev; 
        ++findBack;
    }
    if(findFront>=findBack){
        *front = 0; *back=1;
        return findBack;
    }
    else{
        *front=1, *back=0;
        return findFront;
    }
}
