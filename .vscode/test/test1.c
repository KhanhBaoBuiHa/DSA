//bài 1
/*
1. u(n)=1/(n.(n+1))
2. 
float S(int n){
if(n==0) return 1;
reuturn S(n-1) +1/(n*(n+1));
}
3.
base case : 1
result of base case : f(1)=1/(1+2)+f(0)=4/3
before base case : f(2)=1/(2+3)+f(1)=1/5+f(1)=1/5+4/3
before before : f(3)=1/7+f(2)=1/7+1/5+4/3
4.
float S1(int n){
int sum=0;
for(int i=0;i<n;i++){
sum+=1/(n+(n+1));
}
return sum;
}
*/
//bài 2
/*
#include "stdio.h"
#include "stdlib.h"

//Định nghĩa node
typedef struct NodeType {
    int data;
    struct NodeType* next;
}Node;

//Định nghĩa Linked list
typedef struct LinkedListType{
    Node* head;
}LinkedList;

//Khởi tạo linked list
void init(LinkedList* list) {
    list->head = NULL;
}

//Hàm tạo node mới
Node* makeNode(int data){
    Node* node =(Node*)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;
    return node;
}

//Hàm chèn node mới vào đầu danh sách
void insertHead(int data, LinkedList* list){
    Node* v=makeNode(data);
    if(list->head==NULL){
        list->head=v;
    }else{
        v->next=list->head;
        list->head=v;
    }
}
//Hàm in linked list
void printList(LinkedList* list){
    Node* node = list->head;
    while (node != NULL) {
        printf("Node address: %p | ", &(node->data));
        printf("data = %d| ", node->data);
        printf("next node address = %p\n ", node->next);
        node = node->next;
    }
    printf("\n");
}
void freeList(LinkedList* list){
    while(list->head != NULL){
        Node* t = list->head;
        list->head = list->head->next;
        free(t);
    }
}
int main(){
    LinkedList list;
    init(&list);
    char a[12]="DSATTHS12023";
    //Tạo danh sách tự động
    for(int i=0;i<10;i++){
        insertHead(a[i],&list);
    }
    //In danh sách
    printList(&list);
    return 0;
}
*/
//bài 3
/*
1. sai
*/
/*
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
*/
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
//hàm để xoá một nút trong cây
void delete(binaryTree *tree, int val){
    treeNode *curr = tree->root;
    treeNode *prev = NULL;
    while (1){
        if(curr == NULL){
            printf("Not found!\n");
            return;
        }
        if (val < curr->data){
            prev = curr;
            curr = curr->left;
        } else if (val > curr->data){
            prev = curr;
            curr = curr->right;
        } else if (val == curr->data){
            if (curr->left==NULL && curr->right==NULL){
                if(prev->left == curr){
                    prev->left = NULL;
                }else{
                    prev->right = NULL;
                }
                free(curr);
                return;
            } else if (curr->left == NULL){
                if (prev->left == curr){
                    prev->left = curr->right;
                }else{
                    prev->right = curr->right;
                }
                free(curr);
                return;
            } else if (curr->right == NULL){
                if (prev->left == curr){
                    prev->left = curr->left;
                }else{
                    prev->right = curr->left;
                }
                free(curr);
                return;
            } else {
                treeNode *temp = curr->right;
                treeNode *pretemp = curr;
                while (temp->left != NULL){
                    pretemp=temp;
                    temp = temp->left;
                }
                curr->data = temp->data;
                
                if (pretemp->left == temp)
                    pretemp->left = temp->right;
                else pretemp->right = temp->right;
                free(temp);
                return;
            }
        }
    }
}

int main(){
    binaryTree tree;
    init(&tree);

    int arr[] = {34,10,8,7,29,19,26,75,65,50,55,70};
    for (int i = 0; i < 12; i++) {
        insert(&tree, arr[i]);
    }
    print(tree.root);
    delete(&tree, 7);
    delete(&tree, 50);
    delete(&tree, 65);
    printf("\n");
    print(tree.root);
    return 0;
}