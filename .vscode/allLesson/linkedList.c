#include <stdio.h>
#include <stdlib.h>

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
//Hàm main
int main(){
    LinkedList list;
    init(&list);
    //Tạo danh sách tự động
    for(int i = 0; i < 10; i++)
       insertHead(i, &list); 
    //In danh sách
    printList(&list);
    return 0;
}
