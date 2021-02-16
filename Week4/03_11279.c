//정답

#include <stdio.h>
#include <stdlib.h>

int *heap, *answer; //배열
int n; //최대 개수
int cnt=0; //현재 저장된 원소 개수
int acnt=0; //출력할 배열 원소 개수

void heapify_topdown(int idx);
void heapify_bottomup(int idx);
int pop(void);
void push(int x);
void swap(int*a, int*b);

int main(void){
    scanf("%d", &n);
    heap = (int*)calloc(n, sizeof(int));
    answer = (int*)calloc(n, sizeof(int));
    int x;
    for (int i =0; i<n; i++){
        scanf("%d", &x);
        if (x==0){
            answer[acnt] = pop();
            acnt++;
        }
        else
            push(x);
    }
    for (int i=0; i<acnt; i++){
        printf("%d\n", answer[i]);
    }
    return 0;
}

void heapify_topdown(int idx){
    if (2*idx>cnt) return; //leaf 노드 도달하면 끝
    if (2*idx==cnt){ //left child 만 존재할 때
        if (heap[idx]<heap[2*idx]){
            swap(&heap[idx], &heap[2*idx]);
        }
        return;
    }
    //두 child 가 모두 존재할 때
    if(heap[2*idx]>=heap[2*idx+1]&&heap[2*idx]>heap[idx]){//left child 가 더 클 때
        swap(&heap[idx], &heap[2*idx]);
        heapify_topdown(2*idx);
    }
    else if(heap[2*idx+1]>=heap[2*idx]&&heap[2*idx+1]>heap[idx]){
        swap(&heap[idx], &heap[2*idx+1]);
        heapify_topdown(2*idx+1);
    }
}

void heapify_bottomup(int idx){
    if(idx==1) return; //root 에 도달하면 끝
    if(heap[idx/2]<heap[idx]){
        swap(&heap[idx], &heap[idx/2]);
        heapify_bottomup(idx/2);
    }
}

int pop(void){
    if (cnt!=0){
        int tmp = heap[1];
        heap[1]=heap[cnt];
        cnt--;
        heapify_topdown(1);
        return tmp;
    }
    else
        return 0;
    
}

void push(int x){
    cnt++;
    heap[cnt]=x;
    heapify_bottomup(cnt);
}

void swap(int*a, int*b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}