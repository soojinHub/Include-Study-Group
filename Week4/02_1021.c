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

void QueueInit(Queue* pq);
void Enqueue(Queue* pq, int data);
int Dequeue(Queue* pq);

int main(void){
    int m, n;
    scanf("%d %d", &m, &n);

    Queue q;
    QueueInit(&q);

    for (int i = 1; i<=m; i++){
        Enqueue(&q, i);
    }
    
    return 0;
}

void QueueInit(Queue* pq){
    pq->front = NULL;
    pq->rear = NULL;
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