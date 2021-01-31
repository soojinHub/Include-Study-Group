//정답
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int n;
    int idx;
    struct node* prev;
    struct node* next;
}Node;

Node* head;
Node* cur;

void create(int num){
    Node* tmp = (Node*)malloc(sizeof(Node));
    head = tmp;

    for (int i=0; i<num;i++){
        Node* newnode;
        newnode = (Node*)malloc(sizeof(Node));
        tmp->next = newnode;
        newnode->prev = tmp;
        tmp = newnode;        
        scanf("%d", &tmp->n);
        tmp->idx = i+1;
    }
    tmp->next = head->next;
    head->next->prev = tmp;
}

void delete(Node* dnode){
    printf("%d ", dnode->idx);
    dnode->prev->next = dnode->next;
    dnode->next->prev = dnode->prev;
    cur = dnode;
}

Node* cursor(int n){
    if(n>0){
        for (int i=0; i<n;i++){
            cur = cur->next;
        }
    }
    else{
        for (int i=n; i<0;i++){
            cur = cur->prev;
        }
    }
    return (cur);
}

int main(void){
    int num;
    scanf("%d", &num);
    create(num);

    cur = head->next;
    delete(cur);
    for(int i = 0; i<num-1; i++){
        cur = cursor(cur->n);
        delete(cur);
    }
    return 0;
}