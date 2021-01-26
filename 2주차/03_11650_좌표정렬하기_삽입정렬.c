//오답 - 시간초과
#include <stdio.h>
#include <stdlib.h>

typedef struct point
{
    int x;
    int y;
}Point;

void insertion_sort(Point arr[], int n);
void swap(Point* a, Point *b);

int main(void){
    int num;
    scanf("%d", &num);
    Point * arr = (Point*)malloc(sizeof(Point)*num); //구조체 배열 메모리 할당
    
    for (int i = 0; i<num; i++){
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }
    
    insertion_sort(arr, num);

    for (int i = 0; i<num; i++){
        printf("%d %d\n", arr[i].x, arr[i].y);
    }
return 0;
}

void insertion_sort(Point arr[], int n){
    for (int i = 1; i<n; i++){
        for (int j=i; j>0;j--){
            if (arr[j-1].x > arr[j].x) swap(&arr[j-1], &arr[j]);
            else if ((arr[j-1].x == arr[j].x)&&(arr[j-1].y>arr[j].y)) swap(&arr[j-1],&arr[j]);
        }
    }

}

void swap(Point *a, Point *b){
    Point tmp = *a;
    *a = *b;
    *b= tmp;
}