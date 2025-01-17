#include "stdio.h"
#include "time.h"
#include "stdlib.h"
void initializeArray(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min +(rand() % (max - min + 1));
    }
}
typedef struct NodeType {
    int data;
    struct NodeType* next;
} Node;

typedef struct LinkedListType {
    Node* head;
} LinkedList;

void init(LinkedList* list) {
    list->head = NULL;
}
Node* makeNode(int data){
    Node* node =(Node*)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;
    return node;
}
void insertHead(int data, LinkedList* list){
    Node* v=makeNode(data);
    if(list->head==NULL){
        list->head=v;
    }else{
        v->next=list->head;
        list->head=v;
    }
}

void freeList(LinkedList* list){
    while(list->head != NULL){
        Node* t = list->head;
        list->head = list->head->next;
        free(t);
    }
}
void printList(LinkedList* list){
    Node* node = list->head;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}
//theo tính tăng lên
void insert(LinkedList* list, int data){ 
    Node *newNode=(Node *)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    if(list->head==NULL || list->head->data<=data){
        newNode->next=list->head;
        list->head=newNode;
    }
    else{
        Node *current=list->head;
        while(current->next!=NULL && current->next->data>data){
            current=current->next;
        }
        newNode->next=current->next;
        current->next=newNode;
    }
}
//theo tính giảm xuống
void delete(LinkedList* list, int value) {
    if (list->head == NULL) return;
    while (list->head != NULL && list->head->data == value) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
    Node* current = list->head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == value) {
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}
int main(){
    LinkedList list;
    init(&list);
    time_t t;
    srand((unsigned)time(&t));
    int arr[10];
    printf("Array:\n");
    initializeArray(arr,10,-100,100);
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("Inssert value to list (increasing):\n");
    for(int i=0;i<10;i++){
        printf("Node %d:\n",i);
        insert(&list,arr[i]);
        printList(&list);
        printf("\n");
    }
    printf("Delete value from list (decreasing):\n");
    for(int i=9;i>=0;i--){
        printf("Node %d:\n",i);
        delete(&list,arr[i]);
        printList(&list);
        printf("\n");
    }
}