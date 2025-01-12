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
//hàm này để so sánh 2 chuỗi có giống nhau không
bool soSanh(char temp[],char s[]){
    for(int i=0;i<strlen(s);i++){
        if(temp[i]!=s[i]) return false;
    }
    return true;
}
//hàm cơ bản để chèn
void insert(char *a, int *n, char value, int index){
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
        for(int j=0;j<strlen(str);j++){ 
            char temp[lenS+1];
            tachChuoi(temp,str,j,lenS);
            if(soSanh(temp,s[i])){
                for(int q=0;q<=lenS;q++){
                    char a=str[j+q]+1;
                    insert(str,n,a,j+q+1);
                    j++;
                }
            }
        }
    }
}
int main(){
    //khai báo và nhập
    char str[1000];
    int k;
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