#include <stdio.h>
#include <stdlib.h>
//Cấu trúc TreeNode thể hiện một nút của cây.
typedef struct nodeType{
    int data;
    struct nodeType *left, *right;
} treeNode;
//Cấu trúc BinaryTree lưu trữ cây nhị phân với đại diện là con trỏ kiểu TreeNode tên là root
typedef struct{
    treeNode *root;
} binaryTree;
//Hàm makeNode tạo một nút từ phần vùng nhớ được máy tính cấp phát.
treeNode* makeNode(int data){
    treeNode *newNode = (treeNode*)malloc(sizeof(treeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}
//Hàm init khởi tạo nút đầu tiên của cây.
void init(binaryTree *tree){
    tree->root = NULL;
}
//Hàm insert chèn nút có giá trị data vào cây
void insert(binaryTree *tree, int data){
    treeNode *newNode = makeNode(data);
    
    if (tree->root == NULL){
        tree->root = newNode;
        return;
    }
    treeNode *current = tree->root;
    treeNode *parent = NULL;
    
    while (current != NULL){
        parent = current;
        if (data < current->data){
            current = current->left;
        } 
        else{
            current = current->right;
        }
    }
    if (data < parent->data){
        parent->left = newNode;
    } 
    else{
        parent->right = newNode;
    }
}
//Hàm print in cây nhị phân ra màn hình
void print(treeNode *node){
    if (node != NULL){
        print(node->left);
        printf("%d ", node->data);
        print(node->right);
    }
}

int main(){
    binaryTree tree;
    init(&tree);

    int arr[] = {4, 6, 2, 3, 5, 1, 7};
    for (int i = 0; i < 7; i++) {
        insert(&tree, arr[i]);
    }

    print(tree.root);

    return 0;
}
