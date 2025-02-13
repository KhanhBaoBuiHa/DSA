#include <stdio.h>
#include <stdlib.h>

typedef struct NodeType {
    int data;
    struct NodeType* left, * right;
} TreeNode;

typedef struct BinaryTreeType {
    struct NodeType* root;
} BinaryTree;

TreeNode* makeNode(int data) {
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL){
        printf("Memory allocation failed.\n");
        exit(1); 
    } 
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void print(TreeNode* node) {
    if (node != NULL) {
        print(node->left);         
        printf("%d ", node->data); 
        print(node->right);        
    }
}
void init(BinaryTree* tree) {
    tree->root = NULL;
}

void insert(BinaryTree* tree, int data) {
    TreeNode* newNode = makeNode(data);
    if (tree->root == NULL) {
        tree->root = newNode;
        return;
    }

    TreeNode* current = tree->root;
    TreeNode* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

void freeTree(TreeNode* node) {
    if (node != NULL) {
        freeTree(node->left);   
        freeTree(node->right);  
        free(node);             
    }
}

int main() {
    BinaryTree tree;

    init(&tree);

    // 1.1.1
    int values1[] = {4, 6, 2, 3, 5, 1, 7};
    int size1 = sizeof(values1) / sizeof(values1[0]);
    for (int i = 0; i < size1; i++) {
        insert(&tree, values1[i]);
    }
    printf("Binary Tree 1.1.1 (In-order): ");
    print(tree.root);
    printf("\n");

    freeTree(tree.root);
    init(&tree);

    int values2[] = {8, 10, 3, 6, 14, 1, 7, 13, 4};
    int size2 = sizeof(values2) / sizeof(values2[0]);
    for (int i = 0; i < size2; i++) {
        insert(&tree, values2[i]);
    }
    printf("Binary Tree 1.1.2 (In-order): ");
    print(tree.root);
    printf("\n");

    freeTree(tree.root);
    init(&tree);

    int values3[] = {50, 25, 75, 10, 33, 56, 89, 4, 11, 40, 52, 61, 82, 95};
    int size3 = sizeof(values3) / sizeof(values3[0]);
    for (int i = 0; i < size3; i++) {
        insert(&tree, values3[i]);
    }
    printf("Binary Tree 1.1.3 (In-order): ");
    print(tree.root);
    printf("\n");

    freeTree(tree.root);

    return 0;
}