#include <stdio.h>

char arr[26][2]={'.',};

void preorder(char root);
void inorder(char root);
void postorder(char root);

int main(void){
    int n = 10;
    int num;
    char root, left, right;
    scanf("%d", &num);
    
    for (int i =0; i<num; i++){
        getchar();
        scanf("%c %c %c", &root, &left, &right);
        arr[(int)root-'A'][0]=left;
        arr[(int)root-'A'][1]=right;
    }
    
    preorder('A');
    printf("\n");
    inorder('A');
    printf("\n");
    postorder('A');
    return 0;
}

void preorder(char root){
    if (root == '.')
        return;
    printf("%c", root);
    preorder(arr[(int)root-'A'][0]);
    preorder(arr[(int)root-'A'][1]);
}
void inorder(char root){
    if (root == '.')
        return;
    inorder(arr[(int)root-'A'][0]);        
    printf("%c", root);
    inorder(arr[(int)root-'A'][1]);
}
void postorder(char root){
    if (root == '.')
        return;
    postorder(arr[(int)root-'A'][0]);
    postorder(arr[(int)root-'A'][1]);
    printf("%c", root);
}