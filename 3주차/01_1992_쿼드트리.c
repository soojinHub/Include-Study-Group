//정답
#include <stdio.h>
char arr[64][64];

void quadTree(int x, int y, int size){
    int i, j, flag=0;
    char c = arr[x][y];
    for (i = 0; i<size; i++){
        for(j = 0; j<size; j++){
            if (c != arr[x+i][y+j]){
                flag = 1;
                break; 
            }
        }
        if (j!=size) {
            break;
        }
    }
    if (flag==0) printf("%c", c);
    else{
        printf("(");
        size /=2;
        quadTree(x, y, size);
        quadTree(x, y+size, size);
        quadTree(x+size, y, size);
        quadTree(x+size, y+size, size);
        printf(")");
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%s", arr[i]);
    }
    quadTree(0, 0, n);
    return 0;
}