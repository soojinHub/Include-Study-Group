//오답 - 시간초과

#include <stdio.h>
#include <stdlib.h>

int binary_search(int A[], int value, int left, int right, int cnt) {
    int mid = (left + right) / 2;
    if (A[mid] == value)
        return cnt;
    else if (value < A[mid])
        return binary_search(A, value, left, mid - 1, cnt+1);
    else
        return binary_search(A, value, mid + 1, right, cnt+1);
}

int ternary_search(int A[], int value, int left, int right, int cnt) {
    int left_third = left + (right - left) / 3;
    int right_third = right - (right - left) / 3;
    if (A[left_third] == value) 
        return cnt;
    else if (A[right_third] == value)
        return cnt+1;
    else if (value < A[left_third])
        return ternary_search(A, value, left, left_third - 1, cnt+2);
    else if (value < A[right_third])
        return ternary_search(A, value, left_third + 1, right_third - 1, cnt+2);
    else
        return ternary_search(A, value, right_third + 1, right, cnt+2);
}

int main(void){
    int query, n, s, e;
    scanf("%d", &query);
    int *total_sum = malloc(sizeof(int)*query);
    for (int i = 0; i<query; i++){
        scanf("%d %d %d", &n, &s, &e);
        int *numPtr = malloc(sizeof(int) * n);
        for (int i = 0; i < n-1; i++)             // 입력받은 크기만큼 반복
        {
            numPtr[i] = s + i;                    // 인덱스로 접근하여 값 할당
        }
        numPtr[n-1] = e;
        int  b_sum=0, t_sum=0;
        for (int i =0; i<n; i++){
            b_sum += binary_search(numPtr, numPtr[i], 0, n-1, 0);
            t_sum += ternary_search(numPtr, numPtr[i], 0, n-1, 0);
        }
        total_sum[i] = t_sum-b_sum;
        free(numPtr);
    }

    for (int i = 0; i<query; i++){
        printf("%d\n", total_sum[i]);
    }
    
    free(total_sum);
    return 0;
}