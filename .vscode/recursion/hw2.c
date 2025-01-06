#include "stdio.h"
#define MAX 100
#include "time.h"
#include "stdlib.h"
void initializeArray(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min +(rand() % (max - min + 1));
    }
}
/*
void f1(int a[MAX],int n,int i){
    printf("%d ",a[i]);
    if(i==n) return;
    f(a,n,i++);
}
*/
/***************************************************/
/*
int f2(int value, int a[MAX],int n,int i){
    if(a[i]==value) return i;
    return f(value,a,n,i++);
}
*/
/***************************************************/
typedef struct Stack_type{
    int a[MAX];
    int top;
} Stack;

void init(Stack *s){
    s->top = -1;
}

int isEmpty(Stack* s){
    return s->top == -1;
}
int isFull(Stack* s){
    return s->top == MAX - 1;
}
void push(Stack* s, int value){
    if(!isFull(s)){
        s->top++;
        s->a[s->top] = value;
    }
}
int pop(Stack* s){
    if(!isEmpty(s)) return s->a[s->top--];
}
void displayStack(Stack* s){
    if(!isEmpty(s)){
        for(int i=0;i<=s->top;i++){
            printf("%d ",s->a[i]);
        }
    }
}
void f3a(Stack *s){
    pop(s);
    printf("pop %d : ",s->a[s->top]);
    displayStack(s);
    printf("\n");
    if(isEmpty(s)) return;
    f3a(s);
}
/***************************************************/
/*
typedef struct {
    int head, tail;
    int a[MAX];
} Queue;

void init(Queue* q) {
    q->head = 0;
    q->tail = -1;
}

int isfull(Queue *q){
    return q->tail == MAX-1;
}
int isempty(Queue *q){
    return q->tail == -1;
}
void put(Queue* q, int value){
    if(!isfull(q)){
        q->tail++;
        q->a[q->tail] = value;
    }
}
int get(Queue* q){
    if(!isempty(q)) return q->a[q->tail--];
}
void f3b(Queue *q){
    get(&q);
    if(isemty(&q)) return;
    f3b(q);
}

/***************************************************/
/*
int f4(int a[], int left, int right, int x) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2; 
    if (a[mid] == x) return mid;        
    if (a[mid] > x) return f4(a, left, mid - 1, x);
    else return f4(a, mid + 1, right, x);
}
*/
/***************************************************/
int main(){
    Stack s;
    init(&s);
    int num[6] = {1,-2,3,-4,5,-6};
    for (int i = 0; i <=6; i++){
        if(!isFull(&s)){
            push(&s,num[i]);
        }
    }
    f3a(&s);
}