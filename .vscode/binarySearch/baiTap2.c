#include "stdio.h"
#include "stdbool.h"
#include "string.h"
bool tang(char *str){
    int i=1;
    while(str[i]!='\0'){
        if(str[i-1]>=str[i]) return false;
        i++;
    }
    return true;
}
int linearSearch(char str[],char c){
    for(int i=0;i<strlen(str);i++){
        if(c==str[i]) return i;
    }
    return -1;
}
int binarySearch(char str[], char c) {
    int lower=0,upper=strlen(str)-1,mid, temp;
    while(lower<=upper){
        mid=(lower+upper)/2;
        temp=str[mid];
        if(c<temp) upper=mid-1;
        else if(c>temp) lower=mid+1;
        else return mid;
    }
    return -1;
}
int main(){
    char str[100],c;
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]='\0';
    if(tang(str)){
        scanf("%c",&c);
        int index = binarySearch(str,c); //thay bằng linearSearch cho câu b
        printf("%d",index);
    }else{
        printf("ham khong tang");
    }
}