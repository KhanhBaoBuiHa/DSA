#include "stdio.h"
#include "string.h"
void insert(char str[][100],char insertStr[100],int k,int *n){
    for(int i=*n;i>k;i--){
        strcpy(str[i], str[i - 1]);
    }
    strcpy(str[k], insertStr);
    (*n)++;
}
int main(){
    int n,m,k;
    scanf("%d %d",&n,&m);
    char str[n+1][100],insertStr[100];
    for(int i=0;i<n;i++){
        do{
            fgets(str[i],sizeof(str[i]),stdin);
            str[i][strcspn(str[i],"\n")]='\0';
        }while(strlen(str[i])!=m);
    }
    scanf("%d",&k);
    do{
        fgets(insertStr,sizeof(insertStr),stdin);
        insertStr[strcspn(insertStr,"\n")]='\0';
    }while(strlen(insertStr)!=m);
    insert(str,insertStr,k,&n);
    for(int i=0;i<n;i++){
        printf("%s ",str[i]);
    }
}
