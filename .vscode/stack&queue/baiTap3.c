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
        if
        s->a[s->top] = value;
    }
}
char pop(Stack* s){
    if(!isEmpty(s)) return s->a[s->top--];
    return '\0';
}
void displayStack(Stack* s){
    if(!isEmpty(s)){
        for(int i=0;i<=s->top;i++){
            printf("%d ",s->a[i]);
        }
    }
}
void main() {
    Stack s;
    init(&s);
    fgets(str,sizeof(str),stdin);
    for(int i=0;i<strlen(str);i++){
        char ch=str[i];
        if
    }
}