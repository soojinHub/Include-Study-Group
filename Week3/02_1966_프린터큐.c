//정답
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * next;
}Node;

typedef struct queue{
    Node* front;
    Node* rear;
}Queue;
Node* target;
void QueueInit(Queue* pq);
int QisEmpty(Queue* pq);
void Enqueue(Queue* pq, int data);
int Dequeue(Queue* pq);
Node* Target(Queue* pq);
void Priority(Queue* pq);
int Max(Queue* pq);

int main(void){
    Queue q;
    QueueInit(&q);

    int num, n, m, data;
    scanf("%d", &num);
    while(num--){
        scanf("%d %d",&n, &m);
        for(int i =0; i<n; i++){
            scanf("%d",&data);
            Enqueue(&q, data);
            if (i==m) Target(&q);
        }
        Priority(&q);
    }

    //while(!QisEmpty(&q)){
    //    printf("%d", Dequeue(&q));
    //}
    return 0;
}

void QueueInit(Queue* pq){
    pq->front = NULL;
    pq->rear = NULL;
}

int QisEmpty(Queue* pq){
    if (pq->front == NULL) return 1;
    else return 0;
}

void Enqueue(Queue* pq, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next=NULL;
    newNode->data=data;
    if(QisEmpty(pq)){
        pq->front = newNode;
        pq->rear = newNode;
    }
    else{
        pq->rear->next = newNode;
        pq->rear = newNode;
    }
}

int Dequeue(Queue *pq){
    Node* delNode = pq->front;
    int retData = delNode->data;
    pq->front = pq->front->next;
    free(delNode);
    return retData;
}

Node* Target(Queue* pq){
    target = (Node*)malloc(sizeof(Node));
    target = pq->rear;
    return target;
}

int Max(Queue* pq){
    Node *cur = (Node*)malloc(sizeof(Node));
    cur = pq->front;
    int max = pq->front->data;
    while(cur!=NULL){
        if (max < cur->data) max = cur->data;
        cur = cur->next;
    }
    return max;
}

void Priority(Queue* pq){
    int cnt = 0;
    while(!QisEmpty(pq)){
    if(pq->front->data!=Max(pq)){
        if (pq->front == target){
            int data = Dequeue(pq);
            Enqueue(pq, data);
            target=pq->rear;
        }
        else {
            int data = Dequeue(pq);
            Enqueue(pq, data);
        }
    }
    else {
        if(pq->front == target){
            Dequeue(pq);
            cnt++;
            printf("%d\n", cnt);
        }
        else{
            Dequeue(pq);
            cnt++;
        }
    }
    }
}