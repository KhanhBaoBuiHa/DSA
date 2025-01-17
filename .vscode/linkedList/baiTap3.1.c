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