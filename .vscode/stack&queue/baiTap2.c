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
int checkClose(char open,char close){
    return (open == '(' && close ==')') || (open == '[' && close == ']') || (open == '{' && close == '}');
}
int checkOpen(int num,char *str[]){
    int i=0;
    if(num==3){
        if(str[i]=='{'){
            if(str[i+1]=='['){
                if(str[i+2]=='(') return 1;
                else *str[i+2]='(';
            }
            else *str[i+1]='[';
        }
        else *str[i]='(';
        return 0;
    }
    else if(num==2){
        if(str[i]=='['){
            if(str[i]=='(') return 1;
            else *str[i+1]='(';
        }
        else *str[i]='[';
        return 0;
    }
    else{
        if(str[i]=='(') return 1;
        else *str[i]='(';
        return 0;
    }
}
char peek(Stack *s) {
    if(!isEmpty(s)){
        return s->a[s->top];
    }
    return '\0';
}
void displayStack(Stack* s){
    if(!isEmpty(s)){
        for(int i=0;i<=s->top;i++){
            printf("%c",s->a[i]);
        }
    }
}
void main(){
    fgets(str,sizeof(str),stdin);
    Stack s;
    init(&s);
    int temp[3],num=0,ifError[3];
    for(int i=0;i<strlen(str);i++){
        if(str[i]== '{' || syt[i] == '[' || str[i] == '('){ 
            temp[num]=str[i];
            ifError[num]=i;
            num++;
        }
    }
    if(checkOpen(num,&temp)==0){
        printf("Error at %d",ifError[i]);
    }
    
    displayStack(&s);
}