//정답
#include <stdio.h>
#include <string.h>

typedef struct _arrayStack{
    int arr[100000];
    int topIdx;
}Stack;

void StackInit(Stack*pstack){
    pstack->topIdx = -1;
}

int isEmpty(Stack*pstack){
    if(pstack->topIdx==-1) return 1;
    else return 0;
}

void Push(Stack*pstack, int data){
    pstack->topIdx+=1;
    pstack->arr[pstack->topIdx] = data;
}

int Pop(Stack *pstack){
    int rIdx = pstack -> topIdx;
    pstack->topIdx-=1;
    return pstack->arr[rIdx];
}

int main(void){
    Stack stack;
    StackInit(&stack);
    int num, data;
    int total = 0;
    scanf("%d", &num);
    while(num--){
        scanf("%d", &data);
        if (data!=0) 
            Push(&stack, data);
        else 
            Pop(&stack);
    }
    while(isEmpty(&stack)!=1){
        total += Pop(&stack);
    }
    printf("%d", total);
    return 0;
}