#include <stdio.h> //printf, scanf
#include <string.h> //strchr, strlen

    //char *ptr = strchr(word, 'a'); //문자열에서 찾은 문자 위치의 포인터를 리턴
    //printf("%p\n", word); //문자열의 주소
    //printf("%p\n", ptr); //포인터의 주소
    //printf("%d", (int)(ptr-word)); //문자열에서의 포인터의 인덱스 

int main(void){
    char word[100];
    char abc['z'-'a'+1];
    scanf("%s", word);
    
    for(int j='a'; j<='z';j++){
        for (int i=0; i<strlen(word);i++){
            char *ptr = strchr(word, j); // 알파벳이 처음 등장하는 위치의 주소
            if (ptr != NULL){
                int idx = (int)(ptr-word); // 알파벳이 처음 등장하는 위치의 인덱스
                abc[j-'a'] = idx;
            }
            else
                abc[j-'a'] = -1;
        }
    }

    for(int i=0; i<'z'-'a'+1; i++){
        printf("%d ", abc[i]);
    }

    return 0;
}