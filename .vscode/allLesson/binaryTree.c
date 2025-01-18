#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType{
    int data;
    struct nodeType *left, *right;
} treeNode;

typedef struct{
    treeNode *root;
} binaryTree;

treeNode* makeNode(int data){
    treeNode *newNode = (treeNode*)malloc(sizeof(treeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

void init(binaryTree *tree){
    tree->root = NULL;
}

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
