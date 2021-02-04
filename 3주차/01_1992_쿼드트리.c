//정답
#include <stdio.h>
char arr[64][64]; // 가로 세로의 길이 N 은 1 ≤ N ≤ 64

void quadTree(int x, int y, int size);

int main(void){
    int n;
    scanf("%d", &n); // 가로 세로의 길이 n 입력 받기
    for(int i=0;i<n;i++){
        scanf("%s", arr[i]); //행마다 0 또는 1로 이루어진 길이 n 의 문자열을 입력 받기
    }
    quadTree(0, 0, n); //첫 시작은 arr[0][0]
    return 0;
}

void quadTree(int x, int y, int size){
    int i, j, flag=0;
    char c = arr[x][y];
    for (i = 0; i<size; i++){
        for(j = 0; j<size; j++){
            if (c != arr[x+i][y+j]){ //가로로 검사하면서 매개변수로 입력받은 좌표 [x][y] 와 다른 문자를 발견하면
                flag = 1; //분할을 해야함을 표시
                break; //안쪽 for문 빠져나옴
            }
        }
        if (j!=size) { //j가 끝까지 돌아서 for문을 빠져나온 것이 아니라면
            break; //바깥쪽 for문 빠져나옴
        }
    }
    if (flag==0) printf("%c", c); //첫번째 좌표와 검사한 영역이 모두 같은 문자면 그 문자를 출력 
    else{ //다른 문자가 있어서 이중 for문은 빠져나온 경우
        printf("("); //분할 시작 
        size /=2; //1,2,3,4 분면으로 나누므로 가로 세로의 길이를 반으로 줄임
        quadTree(x, y, size); //1사분면
        quadTree(x, y+size, size); //2사분면
        quadTree(x+size, y, size); //3사분면
        quadTree(x+size, y+size, size); //4사분면
        printf(")"); //분할 끝
    }
}