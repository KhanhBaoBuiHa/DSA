#include "stdio.h"
#include "stdlib.h"
#define MAX 100
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
void fill(Stack *s){
    int value=rand()%10+1;
    push(s,value);
    if(value!=1) fill(s);
}
/*
base case 1
result of base case  value = a , stack [ a ]
before base case     value = b , stack [ a b ]
before before        value = c , stack [ a b c ]
*/
int sum(Stack *s){
    if(isEmpty(s)) return 0;
    int value=pop(s);
    int total=value+sum(s);
    return total;
}
int main(){
    Stack s;
    init(&s);
    fill(&s);
    printf("total cards : %d ",sum(&s));
}