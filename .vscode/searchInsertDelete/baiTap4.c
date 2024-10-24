#include "stdio.h"
#include "string.h"
char *insertString(int n,char str[n],char c,int index){
    for(int i=n;i>index;i--){
        str[i]=str[i-1];
    }
    str[index]=c;
    n++;
    return str;
}
int main(){
    char str[1000],c;
    int index;
    fgets(str,sizeof(str),stdin);
    scanf("%c %d",&c,&index);
    printf("%s",insertString(strlen(str),str,c,index));
}
