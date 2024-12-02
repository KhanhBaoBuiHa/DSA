#include "stdio.h"
#include "string.h"
#include "stdbool.h"
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
//hàm cơ bản để chèn
void insertArray(char *a, int *n, char value, int index){
    for(int i=*n;i>index;i--){
        a[i]=a[i-1];
    }
    a[index]=value;
    (*n)++;
}
//hàm này để chèn các ký tự kế tiếp
void insertArray(int k,char s[][100],char str[100],int *n){
    for(int i=0;i<k;i++){
        int lenS=strlen(s[i]);
        for(int j=0;i<strlen(str);i++){ 
            char temp[lenS+1];
            tachChuoi(temp,str,j,lenS);
            if(soSanh(temp,s[i])){
                for(int q=i;i<=lenS;i++){
                    char a=str[q]+1;
                    insertArray(str,&n,a,str[q]+1);
                }
            }
        }
    }
}
int main(){
    //khai báo và nhập
    char str[1000];
    int k,cnt[100];
    scanf("%s",&str);
    scanf("%d",&k);
    char s[k][100];
    for(int i=0;i<k;i++){
        scanf("%s",&s[i]);
    }
    //xuất
    int n=strlen(str);
    insertArray(k,s,str,&n);
    printf("%s",str);
}