#include "stdio.h"
#include "stdlib.h"
#define MAX 100

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
        printf("Add new user successfully!\n");
    }else{
        printf("Queue is full! Can't add.\n");
    }
}
int get(Queue* q){
    if(!isEmpty(q)) {
        printf("User is removed!\n");
        return q->a[q->tail--];
    }else{
        printf("Queue is null. No user is removed\n");
    }
}
void cancelRegistration(Queue *q, int value){
    if(isEmpty(q)){
        printf("List is null, there is no user to cancel\n");
        return;
    }
    Queue temp;
    init(&temp);
    int found=0;
    while(!isEmpty(q)) {
        int current=q->a[q->head];
        get(q);
        if(current!=value){
            put(&temp,current);
            found=1;
        }
    }
    while(!isEmpty(&temp)){
        put(q,temp.a[temp.head]);
        temp.head=(temp.head+1)%MAX;
    }
    if (found) printf("Cancelling registration successfully %d.\n", value);
    else printf("User %d not found!\n", value);
}
void displayQueue(Queue*q){
    if(!isEmpty(q)){
        printf("Users list :\n");
        for(int i=0;i<= q->tail;i++){
            printf("%d\n",q->a[i]);
        }
    }else{
        printf("List is null\n");
    }
}
int main() {
    Queue q;
    init(&q);
    int function,userID;
    do{
        printf("______________MANAGING USERS PROGRAM____________\nFUNCTION________________________________________\n1. New user registration\n2. Remove the fist user information\n3. Cancel registration\n4. Users list\n5. Exit\n________________________________________________\n");
        printf("Press here to use : (1-5) ");
        scanf("%d",&function);
        switch(function){
            case 1:
            printf("Enter userID :");
            scanf("%d",&userID);
            put(&q,userID);
            break;

            case 2:
            get(&q);
            break;

            case 3:
            printf("Enter userID which need to be cancelled:");
            scanf("%d",&userID);
            cancelRegistration(&q,userID);
            break;
            
            case 4:
            displayQueue(&q);
            break;

            default:
            printf("Invalid selection. Please select again.");
        }       
    }while(function!=5);
    return 0;
}