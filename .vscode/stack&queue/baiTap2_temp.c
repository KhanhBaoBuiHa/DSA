#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define MAX 100
typedef struct Stack_type{
    int index[MAX];
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
void push(Stack* s, int value, int index){
    if(!isFull(s)){
        s->top++;
        s->a[s->top] = value;
        s->index[s->top]=index;
    }
}
char pop(Stack* s,int *index){
    if(!isEmpty(s)){
        return s->a[s->top--];
    }
    return '\0';
}
char peek(Stack *s){
    if (isEmpty(s)) return '\0';
    return s->a[s->top];
}
void displayStack(Stack* s){
    if(!isEmpty(s)){
        for(int i=0;i<=s->top;i++){
            printf("%c",s->a[i]);
        }
    }
}
int isMatching(char open,char close){
    return (open == '(' && close ==')') || (open == '[' && close == ']') || (open == '{' && close == '}');
}
int main(){
    Stack s;
    init(&s);
    char str[100];
    fgets(str,sizeof(str),stdin);
    int error=0;
    for(int i=0;i<strlen(str);i++){
        char ch=str[i];
        if(ch=='(' || ch=='[' || ch=='{'){
            push(&s, ch,i);
        } 
        else if(ch==')' || ch==']' || ch=='}'){
            int topIndex;
            char top=pop(&s,&topIndex);
            if(!isMatching(top,ch)){
                printf("Error at %d\n",i);
                if(top=='(') str[i]=')';
                else if(top=='[') str[i]=']';
                else if(top=='{') str[i]='}';
                error++;
            } 
        }
    }
    if(error==0) printf("No error");   
    else{
        printf("%s",str);
    }
    return 0;
}