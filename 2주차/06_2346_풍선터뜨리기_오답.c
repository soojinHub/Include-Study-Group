//오답
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
    int n;
    struct node* prev;
    struct node* next;
}Node;

Node* head;

void create(int num){
    Node* tmp;
    tmp = (Node*)malloc(sizeof(Node));
    head = tmp;

    for (int i=0; i<num;i++){
        Node* newnode;
        newnode = (Node*)malloc(sizeof(Node));
        tmp->next = newnode;
        newnode->prev = tmp;
        tmp = newnode;        
        scanf("%d", &tmp->n);
    }
    tmp->next = head->next;
    head->next->prev = tmp;
}

void print(int num){
    Node *ptr = head -> next;
    for(int i =0; i<num; i++){
        printf("%d", ptr->n);
        ptr = ptr->next;
    }
}

int main(void){
    int num;
    scanf("%d", &num);
    create(num);
    print(num);
    return 0;
}