#include "stdio.h"
#include "string.h"
#include "stdbool.h"
<<<<<<< HEAD
=======
/*
void delete(){
    for(int i=0;i<k;i++){
       for(int j=0;j<cnt;j++){
           str[]
       }
    }
}
*/
>>>>>>> 2feef14a632dcf41a166be9f0d75937b674767f7
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
<<<<<<< HEAD
int find(char s[],char str[], int start){
    int lenS=strlen(s);
    for(int i=start;i<strlen(str)-strlen(s);i++){
        char temp[lenS+1];
        tachChuoi(temp,str,i,lenS);
=======
int find(char s[],char str[]){
    for(int i=0;i<strlen(str)-strlen(s);i++){
        char temp[strlen(s)+1];
        tachChuoi(temp,str,i,strlen(s));
>>>>>>> 2feef14a632dcf41a166be9f0d75937b674767f7
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
<<<<<<< HEAD
=======
    getchar();
>>>>>>> 2feef14a632dcf41a166be9f0d75937b674767f7
    char s[k][100];
    for(int i=0;i<k;i++){
        scanf("%s",&s[i]);
    }
    //xuất
    for(int i=0;i<k;i++){
<<<<<<< HEAD
        int cnt=0,index[100],pos=0,currentPos=0;
        while((currentPos=find(s[i],str,pos))!=-1){
            index[cnt++]=currentPos;
            pos=currentPos+1;
        }
        if(cnt!=0){
            printf("%d %s",cnt,s[i]);
            for(int j=0;j<cnt;j++){
                printf(" %d",index[j]);
            }
            printf("\n");
=======
        int cnt=0;
        int index=find(s[i],str);
        if(index!=-1){
            cnt++;
            printf("%d %s %d\n",cnt,s[i],index);
>>>>>>> 2feef14a632dcf41a166be9f0d75937b674767f7
        }else{
            printf("0 %s\n",s[i]);
        }
    }
}