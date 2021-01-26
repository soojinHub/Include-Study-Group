//정답

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
    char ch;
    struct node* next;
    struct node* prev;
}Node;

int main(void){
    Node* head = (Node*)malloc(sizeof(Node));
    head->ch='h';
    head->prev = NULL;
    head->next = NULL;
    Node* cur = head;

    char input;
    while((input=getchar())!='\n'){
        Node* newnode = (Node*)malloc(sizeof(Node));
        newnode->ch=input;
        newnode->prev=cur;
        newnode->next=NULL;
        cur->next=newnode;
        cur=newnode;
    }

    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        char c;
        scanf(" %c", &c);
        switch(c){
            case 'L':{
                if(cur->prev) cur=cur->prev;
                break;
            }
            case 'D':{
                if(cur->next) cur=cur->next;
                break;
            }
            case 'B':{
                if(cur->prev==NULL) continue;
                Node* dnode = (Node*)malloc(sizeof(Node));
                dnode = cur;
                cur = dnode->prev;
                if(dnode->next){
                    cur->next= dnode->next;
                    dnode->next->prev= cur;
                    dnode->prev=NULL;
                }
                else{
                    cur->next = NULL;
                }
                free(dnode);
                break;
            }
            case 'P':{
                char temp;
                scanf(" %c", &temp);
                Node* newnode = (Node*)malloc(sizeof(Node));
                newnode->ch = temp;
                newnode->prev = cur;
                if(cur->next){
                    newnode->next = cur->next;
                    cur->next->prev = newnode;
                }
                else
                {
                    newnode->next = NULL;
                }
                cur->next = newnode;
                cur = cur->next;
                break;
            }
        }
    }

    head = head->next;
    while(head){
        printf("%c",head->ch);
        head=head->next;
    }

    return 0;
}