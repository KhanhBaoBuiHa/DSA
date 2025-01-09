#include "stdio.h"
#include "stdlib.h"
typedef struct NodeType {
    int data;
    struct NodeType* next;
}Node;

typedef struct LinkedListType{
    Node* head;
}LinkedList;

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
void insertAtEverywhere(LinkedList *list,int data, int position){
    makeNode(data);
    Node* node = list->head;
    for(int i=0;i<position-1;i++){
        node = node->next;
    }
    Node* newNode = makeNode(data);
    newNode->next = node->next;
    node->next = newNode;
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
int main(){
    LinkedList list;
    init(&list);
    int a[6]={2,3,4,5,6,7};
    for(int i=0;i<6;i++){
        insertHead(a[i],&list);
    }
    insertAtEverywhere(&list,1,2);
    printList(&list);
    freeList(&list);
    return 0;
}