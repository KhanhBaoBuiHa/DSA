#include "stdio.h"
#include "stdlib.h"

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}


Node* buildTree(int arr[], int index, int n) {
    if (index >= n) return NULL;
    Node* root = createNode(arr[index]);
    root->left = buildTree(arr, 2 * index + 1, n);
    root->right = buildTree(arr, 2 * index + 2, n);
    return root;
}

void displayTree(Node* root, int space) {
    if (root == NULL) return;
    space += 5;
    displayTree(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    displayTree(root->left, space);
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    //BÀI 1.1
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int n = sizeof(a) / sizeof(a[0]);
    Node* rootA = buildTree(a, 0, n);
    printf("Binary Tree:\n");
    displayTree(rootA, 0);
    freeTree(rootA);

    //BÀI 1.2
    int b[] = {50,17,76,9,23,54,14,19,72,12,67};
    int m = sizeof(b) / sizeof(b[0]);
    Node* rootB = buildTree(b, 0, m);
    printf("Binary Tree:\n");
    displayTree(rootB, 0);
    freeTree(rootB);

    //BÀI 1.3
    int c[] = {15,11,26,8,12,20,30,6,9,14,35};
    int k = sizeof(c) / sizeof(c[0]);
    Node* rootC = buildTree(c, 0, k);
    printf("Binary Tree:\n");
    displayTree(rootC, 0);
    freeTree(rootC);

    //BÀI 1.4
    int d[] = {3,1,10,13,5,11,16,6,15,2,9,4};
    int l = sizeof(d) / sizeof(d[0]);
    Node* rootD = buildTree(d, 0, l);
    printf("Binary Tree:\n");
    displayTree(rootD, 0);
    return 0;
}
