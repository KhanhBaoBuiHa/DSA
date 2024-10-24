#include "stdio.h"
int main(){
    int i=0;
    char str[100],c;
    fgets(str,sizeof(str),stdin);
    scanf("%c", &c);
    while(str[i]!='\0'){
        if(str[i]==c){
            printf("Found %c at %d",c,i);
            return 0;
        }
        i++;
    }
    printf("Not Found!");
    return 0;
}