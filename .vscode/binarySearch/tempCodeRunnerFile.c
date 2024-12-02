#include "stdio.h"
#include "string.h"
#include "stdbool.h"
bool tang(char *str){
    int i=1;
    while(str[i]!='\0'){
        if(str[i-1]>=str[i]) return false;
        i++;
    }
    return true;
}
void insert(char str[],char insertStr,int k,int *n){
    for(int i=*n;i>k;i--){
        str[i]=str[i-1];
    }
    str[k]=insertStr;
    (*n)++;
    str[*n]='\0';
}
int main(){
    char str[26];
    fgets(str,sizeof(str),stdin);
    int n=strlen(str);
    if(tang(str)){
        for(int i=0;i<n;i++){
            if(str[i]!='a'){
                printf("a at 0 is missing\nabcdefghijklmnopqrstuvwxyz");
                return 0;
            }
            if(str[i+1]!=str[i]+1){
                char c=str[i]+1;
                printf("%c at %d is missing",c,i+1);
                insert(str,c,i+1,&n);
                break;
            }
        }
    }else{
        printf("ham khong sap xep theo thu tu");
        return 0;
    }
    printf("%s",str);
    return 0;
}