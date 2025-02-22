#include <stdio.h>
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
    int num[6] = {1,-2,3,-4,5,-6};
    // push
    printf("MAX = %d\n\n", MAX);
    printf("PUT\n");
    for (int i = 0; i < 6; i++){
        printf("put %d: \n",num[i]);
        if(!isFull(&q)){
            put(&q,num[i]);
            displayQueue(&q);
            printf("\n");
        }
        else
            printf("Queue is full. \n\n");
    }
    // get
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