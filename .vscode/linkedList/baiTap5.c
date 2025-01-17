#include "stdio.h"
#include "stdlib.h"
#define MAX 100

typedef struct NodeType {
    int data;
    struct NodeType* next;
}Node;


int main(){
    LinkedList list[];
    init(&list);
    int choice;
    do{
        printf("______________HOTEL MANAGING PROGRAM____________\n");
        printf("1. Display rooms's status\n");
        printf("2. Search group's information\n");
        printf("3. New group registration\n");
        printf("4. Cancel group registration\n");
        printf("5. Remove members \n");
        printf("Press here to use : (1-6)");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            printList(&list);

        }
    }
}