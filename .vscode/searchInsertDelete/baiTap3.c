#include "stdio.h"
#include "string.h"
int search(char serialKey[][100], char str[100],int n){
    int i=0;
    while(i<n){
        if(strcmp(serialKey[i],str)==0) return i;
        i++;
    }
    return -1;
}
int main(){
    int n,k;
    scanf("%d %d",&n, &k);
    char serialKey[n][100],str[100];
    for(int i=0;i<n;i++){
        do{
            fgets(serialKey[i],sizeof(serialKey[i]),stdin);
            serialKey[i][strcspn(serialKey[i],"\n")]='\0';
        }while(strlen(serialKey[i])!=k);
    }
    fgets(str,sizeof(str),stdin);
    str[strcspn(str, "\n")] = '\0';
    if(search(serialKey,str,n)==-1){
        printf("Not Found");
    }else{
        printf("Found at index %d",search(serialKey,str,n));
    }
}
