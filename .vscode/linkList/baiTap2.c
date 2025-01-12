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
        printf("Node address: %p | ", &(node->data));
        printf("data = %d| ", node->data);
        printf("next node address = %p\n ", node->next);
        node = node->next;
    }
    printf("\n");
}
void insert(LinkedList* list, int data){
    makeNode(data);
    Node* node=list->head;
    while(data != NULL){
        
    }
}
void delete(LinkedList* list, int value){

}
int main(){
    LinkedList list;
    init(&list);
    time_t t;
    srand((unsigned)time(&t));
    int arr[10];
    initializeArray(arr,10,-100,100);

}