#include "stdio.h"
#include "string.h"
#include "stdbool.h"
/*
void delete(){
    for(int i=0;i<k;i++){
       for(int j=0;j<cnt;j++){
           str[]
       }
    }
}
*/
//hàm này để tách chuỗi str thành chuỗi con có độ dài bằng mã độc
void tachChuoi(char* result,char str[],int start,int l){
    for(int i=0;i<l;i++){
        result[i]=str[start+i];
    }
    result[l]='\0';
}
//hàm này để so sánh 2 chuỗi
bool soSanh(char temp[],char s[]){
    for(int i=0;i<strlen(s);i++){
        if(temp[i]!=s[i]) return 0;
    }
    return 1;
}
//hàm này để tìm kiếm mã độc
int find(char s[],char str[]){
    for(int i=0;i<strlen(str)-strlen(s);i++){
        char temp[strlen(s)+1];
        tachChuoi(temp,str,i,strlen(s));
        if(soSanh(temp,s)) return i;
    }
    return -1;
}
int main(){
    //khai báo và nhập
    char str[1000];
    int k,cnt[100];
    scanf("%s",&str);
    scanf("%d",&k);
    getchar();
    char s[k][100];
    for(int i=0;i<k;i++){
        scanf("%s",&s[i]);
    }
    //xuất
    for(int i=0;i<k;i++){
        int cnt=0;
        int index=find(s[i],str);
        if(index!=-1){
            cnt++;
            printf("%d %s %d\n",cnt,s[i],index);
        }else{
            printf("0 %s\n",s[i]);
        }
    }
}