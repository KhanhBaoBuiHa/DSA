#include "stdio.h"
#define MAX 5

typedef struct {
    int head, tail;
    int a[MAX];
} Queue;

void init(Queue* q) {
    q->head = 0;
    q->tail = -1;
}

int isFull(Queue *q){
    return q->tail == MAX-1;
}
int isEmpty(Queue *q){
    return q->tail == -1;
}
void put(Queue* q, int value){
    if(!isFull(q)){
        q->tail++;
        q->a[q->tail] = value;
    }
}
int get(Queue* q){
    if(!isEmpty(q)) return q->a[q->tail--];
}
void displayQueue(Queue*q){
    if(!isEmpty(q)){
        for(int i=0;i<= q->tail;i++){
            printf("%d ",q->a[i]);
        }
    }
}
int main() {
    Queue q;
    init(&q);
    
    return 0;
}