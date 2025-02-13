//bài 1
/*
#include "stdio.h"
int binarySearch(int a[], int left, int right, int x) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2; 
    if (a[mid] == x) return mid;        
    if (a[mid] > x) return binarySearch(a, left, mid - 1, x);
    else return binarySearch(a, mid + 1, right, x);
}
/*
base case : a[mid]=x
result of base case : mid
before base case : a[mid]>x
before before :

int main(){
    int a[]={1,2,3,4,5,6,7,8,9,10};
    printf("%d",binarySearch(a,0,9,5));
}
*/
//bài 2
/*
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define MAX 10

void initializeArray(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min +(rand() % (max - min + 1));
    }
}
typedef struct NodeType {
    int data;
    struct NodeType* next;
}Node;

typedef struct Stacktype{
    Node* top;
}Stack;

void init(Stack* s) {
    s->top = NULL;
}

Node* makeNode(int data){
    Node* node =(Node*)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;
    return node;
}

int isEmpty(Stack* s){
    return s->top == NULL;
}

int isFull(Stack* s){
    return s->top == MAX - 1;
}

void push(Stack* s, int value){
    Node* node=makeNode(value);
    node->next=s->top;
    s->top=node;
}
int pop(Stack* s){
    if(!isEmpty(s)){
        Node* temp=s->top;
        int data=temp->data;
        s->top=temp->next;
        free(temp);
        return data;
    }
}

void displayStack(Stack* stack) {
    Node* current = stack->top;
    printf("Stack: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
void freeStack(Stack* s){
    while(s->top != NULL){
        Node* t = s->top;
        s->top = s->top->next;
        free(t);
    }
}

int main(){
    Stack s;
    init(&s);
    time_t t;
    srand((unsigned)time(&t));
    int arr[10];
    initializeArray(arr, 10, -100, 100);
    printf("PUSH\n");
    for (int i = 0; i < 6; i++){
        printf("push %d: \n",arr[i]);
        if(!isFull(&s)){
            push(&s,arr[i]);
            displayStack(&s);
            printf("\n");
        }
        else printf("Stack is full. \n\n");
    }
    // pop
    printf("POP\n");
    int i = 0;
    while (!isEmpty(&s)) {
        printf("pop %d: %d\n",i, pop(&s));
        displayStack(&s);
        i++;
        printf("\n");
     }
}
*/
//bài 3
#include <stdio.h>
#include <stdlib.h>

// Cấu trúc node của cây
typedef struct nodeType {
    int data;
    struct nodeType *left, *right;
} treeNode;

// Cấu trúc cây nhị phân
typedef struct {
    treeNode *root;
} binaryTree;

// Tạo một nút mới
treeNode* makeNode(int data) {
    treeNode *newNode = (treeNode*)malloc(sizeof(treeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Khởi tạo cây
void init(binaryTree *tree) {
    tree->root = NULL;
}

// Chèn một nút vào cây
void insert(binaryTree *tree, int data) {
    treeNode *newNode = makeNode(data);
    
    if (tree->root == NULL) {
        tree->root = newNode;
        return;
    }
    
    treeNode *current = tree->root;
    treeNode *parent = NULL;
    
    while (current != NULL) {
        parent = current;
        if (data < current->data)
            current = current->left;
        else
            current = current->right;
    }
    
    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}

// Duyệt cây theo thứ tự trung tố
void inorderTraversal(treeNode *node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->data);
        inorderTraversal(node->right);
    }
}

// Tính chiều cao của cây
int height(treeNode* root) {
    if (root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// 1. Tính tổng các nhánh dài nhất
void sumLongestPath(treeNode* root, int depth, int maxDepth, int currentSum, int* maxSum) {
    if (root == NULL) return;
    
    currentSum += root->data;
    
    if (depth == maxDepth) {
        *maxSum += root->data;
    }
    
    sumLongestPath(root->left, depth + 1, maxDepth, currentSum, maxSum);
    sumLongestPath(root->right, depth + 1, maxDepth, currentSum, maxSum);
}

int getSumLongestPath(treeNode* root) {
    int maxDepth = height(root);
    int maxSum = 0;
    sumLongestPath(root, 1, maxDepth, 0, &maxSum);
    return maxSum;
}

// 2. Tìm tổng lớn nhất trên một nhánh
void maxSumBranch(treeNode* root, int currentSum, int* maxSum) {
    if (root == NULL) return;

    currentSum += root->data;

    if (root->left == NULL && root->right == NULL) { // Nếu là lá
        if (currentSum > *maxSum) *maxSum = currentSum;
    }

    maxSumBranch(root->left, currentSum, maxSum);
    maxSumBranch(root->right, currentSum, maxSum);
}

int getMaxSumBranch(treeNode* root) {
    int maxSum = 0;
    maxSumBranch(root, 0, &maxSum);
    return maxSum;
}

// 3. Xóa số lẻ trong cây nhị phân (trừ root)
treeNode* deleteOdd(treeNode* root) {
    if (root == NULL) return NULL;

    root->left = deleteOdd(root->left);
    root->right = deleteOdd(root->right);

    if (root->data % 2 != 0) { 
        treeNode* temp = (root->right != NULL) ? root->right : root->left;
        free(root);
        return temp;
    }
    return root;
}
int main(){
    binaryTree tree;
    init(&tree);
    treeNode* root;
    int arr[] = {4, 6, 2, 3, 5, 1, 7};
    for (int i = 0; i < 7; i++) {
        insert(&tree, arr[i]);
    }
    printf("the sum of the longest path: %d\n", getSumLongestPath(tree.root));
    printf("the largest sum of the branch: %d\n", getMaxSumBranch(tree.root));
    tree.root = deleteOdd(tree.root);
    inorderTraversal(tree.root);
    return 0;
}