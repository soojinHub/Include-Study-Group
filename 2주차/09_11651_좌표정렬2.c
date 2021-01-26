//정답
#include <stdio.h>
#include <stdlib.h>

typedef struct point
{
    int x;
    int y;
}Point;

void merge(Point arr[], Point temp[], int l, int m, int r);
int merge_sort(Point arr[], Point temp[], int l, int r);
void swap(Point* a, Point *b);

int main(void){
    int num;
    scanf("%d", &num);
    Point * arr = (Point*)malloc(sizeof(Point)*num); //구조체 배열 메모리 할당
    Point * temp = (Point*)malloc(sizeof(Point)*num);
    for (int i = 0; i<num; i++){
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }
    
    merge_sort(arr, temp, 0, num-1);

    for (int i = 0; i<num; i++){
        printf("%d %d\n", arr[i].x, arr[i].y);
    }
return 0;
}

void merge(Point arr[], Point temp[], int l, int m, int r){
    int i = l;
    int j = m+1;
    for (int k =l; k<r+1;k++){
        if (i>m){
            temp[k]=arr[j];
            j++;
        }
        else if (j>r){
            temp[k]=arr[i];
            i++;
        }
        else if ((arr[j].y<arr[i].y)||((arr[j].y==arr[i].y)&&(arr[j].x<arr[i].x))){
            temp[k] = arr[j];
            j++;
        }
        else{
            temp[k]=arr[i];
            i++;
        }
    }
    for (int k =l; k<r+1; k++){
        arr[k]=temp[k];
    }
}

int merge_sort(Point arr[], Point temp[], int l, int r){
    if (r<=l) return -1; //arr의 크기가 1이라면 종료
    int m = l + (r-l)/2; //중간 원소의 인덱스
    merge_sort(arr, temp, l, m);
    merge_sort(arr, temp, m+1, r);
    merge(arr, temp, l, m, r);
}
