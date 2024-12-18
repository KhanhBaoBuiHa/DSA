#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"
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
char pop(Stack* s){
    if(!isEmpty(s)) return s->a[s->top--];
    return '\0';
}
char peek(Stack *s){
    if (isEmpty(s)) return '\0';
    return s->a[s->top];
}
void displayStack(Stack* s){
    if(!isEmpty(s)){
        for(int i=0;i<=s->top;i++){
            printf("%d ",s->a[i]);
        }
    }
}
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
void hauTo(char *infix,char *postfix){
    Stack s;
    init(&s);
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        if (ch >= '0' && ch <= '9'){
            postfix[j++] = ch;
        }else if((ch == '+' || ch == '-' || ch == '*' || ch == '/')){
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}
int evaluate(char *expr) {
    Stack s;
    init(&s);
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (isdigit(ch)) {
            push(&s, ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int val2 = pop(&s);
            int val1 = pop(&s);
            int result;
            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': 
                    if (val2 != 0) result = val1 / val2; 
                    else {
                        printf("Error: Division by zero\n");
                        return -1;
                    }
                    break;
                default:
                    printf("Invalid operator\n");
                    return -1;
            }
            push(&s, result);
        }
    }
    return pop(&s);
}
void main() {
    char str[MAX],rs1[MAX];
    fgets(str,sizeof(str),stdin);
    hauTo(str,rs1);
    printf("Postfix : %s",rs1);
    int rs2 = evaluate(str);
    printf("\nResult : %d",rs2);
}