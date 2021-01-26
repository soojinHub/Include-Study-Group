//정답
#include <stdio.h>

int main(void){
    int stack[100000];
    char operate[200000];
    int howMany, n, top=0, stackIdx = 0, operIdx = 0, sign=0;
    scanf("%d", &howMany);
    for(int i = 0; i<howMany; i++){
        scanf("%d", &n);
        if (n > top){
            for(int i = top; i < n; i++){
                operate[operIdx++] = '+';
                stack[stackIdx++]=i+1;
            }
            top = n;
        }
        else
            if(stack[stackIdx-1]!=n) sign = 1;
            stackIdx--;
            operate[operIdx++]='-';
    }
    if (sign==1) {
        printf("NO");
        return 0;
    }
    for (int j=0; j<operIdx; j++){
        printf("%c\n", operate[j]);
    }
    return 0;
}