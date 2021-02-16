//시간초과
#include <stdio.h>

int cnt=0; //입력받은 원소 개수를 세어주기 위함
int p[100000]; //프린트를 위한 배열
int pcnt=0; //프린트를 위한 배열의 원소 개수를 세어주기 위함
void pop(int arr[]);//max를 찾아서 반환
void push(int arr[], int n);

int main(void){
    int num, x;
    int arr[100000];
    scanf("%d", &num);
    for (int i =0; i<num; i++){
        scanf("%d", &x);
        if (x==0) pop(arr);
        else 
            push(arr, x);
    }
    for (int i =0; i<pcnt; i++){
        printf("%d\n", p[i]);
    }
    return 0;
}

void pop(int arr[]){ 
    if (cnt==0){
        p[0]=0;
        pcnt++;
    }
    else {
        int max=0;
        for(int i=0; i<cnt; i++){
            if (arr[i]>max) {
                max=arr[i];
            }
        }
        for(int i=0; i<cnt; i++){
            if (arr[i]==max) {
                arr[i]=0;
                break;
            }
        }    
        p[pcnt]=max;
        pcnt++;
    }
}

void push(int arr[], int n){
    arr[cnt]=n;
    cnt++;
}