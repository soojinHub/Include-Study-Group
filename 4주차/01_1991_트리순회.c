#include <stdio.h>

int arr[26][2]={'.',};

void preorder(int root);
void inorder(int root);
void postorder(int root);

int main(void){
    int num, root, left, right;
    scanf("%d", &num);
    for (int i =0; i<num; i++){
        scanf("%d %d %d", &root, &left, &right);
        arr[root-'A'][0]=left;
        arr[root-'A'][1]=right;
    }
    preorder(0);
    inorder(0);
    postorder(0);
    return 0;
}

void preorder(int root){
    if (root == '.')
        return;
    printf("%d, root");
    preorder(arr[root-'A'][0]);
    preorder(arr[root-'A'][1]);
}
void inorder(int root){
    if (root == '.')
        return;
    inorder(arr[root-'A'][0]);        
    printf("%d, root");
    inorder(arr[root-'A'][1]);
}
void postorder(int root){
    if (root == '.')
        return;
    postorder(arr[root-'A'][0]);
    postorder(arr[root-'A'][1]);
    printf("%d, root");
}