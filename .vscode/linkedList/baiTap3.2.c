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

typedef struct Queuetype{
    Node* head;
    Node* tail;
}Queue;

void init(Queue* q){
    q->head = NULL;
    q->tail = NULL;
}

Node* makeNode(int data){
    Node* node =(Node*)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;
    return node;
}

int isEmpty(Queue* q){
    return q->head == NULL;
}

int isFull(Queue* q){
    return q->tail == MAX - 1;
}

void put(Queue* q, int value){
    Node* node=makeNode(value);
    if (q->tail == NULL) {
        q->head = node;
        q->tail = node;
    }
    else{
    q->tail->next=node;
    q->tail=node;
    }
}

int get(Queue* q){
    if(!isEmpty(q)){
        Node* temp=q->head;
        int data=temp->data;
        q->head=temp->next;
        if(q->head==NULL) q->tail=NULL;
        free(temp);
        return data;
    }
    return -1;
}
void displayQueue(Queue* q){
    Node* current = q->head;
    printf("Queue: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
void freeQueue(Queue* q){
    while(q->head != NULL){
        Node* t = q->head;
        q->head = q->tail->next;
        free(t);
    }
}
int main(){
    Queue q;
    init(&q);
    time_t t;
    srand((unsigned) time(&t));
    int arr[10];
    initializeArray(arr,10,-100,100);
    printf("PUT\n");
    for(int i=0;i<10;i++){
        printf("put %d: \n",arr[i]);
        if(!isFull(&q)){
            put(&q,arr[i]);
            displayQueue(&q);
            printf("\n");
        }
        else printf("Queue is full. \n\n");
    }
    printf("GET\n");
    int i = 0;
    while (!isEmpty(&q)) {
        printf("get %d: %d\n",i, get(&q));
        displayQueue(&q);
        i++;
        printf("\n");
    }
    return 0;
}