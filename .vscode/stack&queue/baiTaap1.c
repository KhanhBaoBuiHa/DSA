#include "stdio.h"
#include "string.h"
#include "stdlib.h"

char str[100];
#define MAX 100

typedef struct Stack_type{
    char a[MAX];
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
            printf("%c",s->a[i]);
        }
    }
}
int main(){
    fgets(str,sizeof(str),stdin);
    Stack s;
    init(&s);
    //cách 1
    for(int i=strlen(str)-1;i>=0;i--){
        printf("%c",str[i]);
    }
    printf("\n");
    //cách 2
    for(int i=strlen(str)-1;i>=0;i--){
        push(&s,str[i]);
    }
    displayStack(&s);
}