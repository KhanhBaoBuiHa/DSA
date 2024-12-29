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
        printf("Add new wifi successfully!\n");
    }else{
        printf("Storage is full! Can't add.\n");
    }
}
int get(Queue* q){
    if(!isEmpty(q)) {
        printf("Wifi is removed!\n");
        return q->a[q->tail--];
    }else{
        printf("Storage is null. No wifi is removed\n");
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
    if (found) printf("Cancelling adding successfully %d.\n", value);
    else printf("Wifi %d not found!\n", value);
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
int main(){
    Queue q[MAX];
    int N,function,wifi;
    int M[MAX];

    printf("______________SETTTING_______________");
    printf("\nEnter the number of floors of your house : ");
    scanf("%d",&N);
    printf("\nEnter the number of wifi accessment of each floor\n");
    for(int i=0;i<N;i++){
        printf("Floor %d : ",i+1);
        scanf("%d",&M[i]);  
    } 
    do{
        printf("______________MANAGING WIFI PROGRAM____________\nFUNCTION________________________________________\n1. New wifi accessment\n2. Cancel accessment\n3. Wifi list\n4. Exit\n________________________________________________\n");
        printf("Press here to use : (1-4) ");
        scanf("%d",&function);
        int inputFloor;
        switch(function){
            case 1:
            printf("Enter the floor to be installed :");
            while(1){
                scanf("%d",&inputFloor);
                if(inputFloor>0 && inputFloor<N){
                    break;
                }
                printf("Invalid floor");
            }
            init(&q[inputFloor]);
            printf("Enter WIFI name  : (only accept number)");
            scanf("%d",&wifi);
            put(&q[inputFloor],wifi);
            break;

            case 2:
            printf("Enter floor: ");
            scanf("%d",&inputFloor);
            printf("Enter wifi need to be removed:");
            scanf("%d",&wifi);
            cancelRegistration(&q[inputFloor],wifi);
            break;
            
            case 3:
            for(int i=0;i<N;i++){
                printf("Floor %d",i+1);
                displayQueue(&q[i]);
            }
            break;

            default:
            printf("Invalid selection. Please select again.");
        }       
    }while(function!=4);
    return 0;
}