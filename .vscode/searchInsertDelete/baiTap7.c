//CHƯA XONG
#include "stdio.h"
#include "string.h"
//chèn
void insert(char str[][100],char insertStr[100],int k,int *n){
    for(int i=*n;i>k;i--){
        strcpy(str[i],str[i-1]);
    }
    strcpy(str[k],insertStr);
    (*n)++;
}
//đổi kiểu dữ liệu chuỗi qua số nguyên
int strToInt(char *str){
        int rs=0;
        for(int i=0;str[i];i++){
            if(str[i]>='0'&&str[i]<='9'){
                rs=rs*10+(str[i]-'0');
            }else{
                break;
            }
        }
        return rs;
}
//hàm này để tách mã số sp ra
int serialNumber(char *str){
    char result[3];
    result[0]=str[0];
    result[1]=str[1];
    result[2]='\0';
    return strToInt(result);
}
int main(){
    //khai báo, nhập
    int n,m;
    scanf("%d",&n);
    getchar();
    char a[100][100];
    for(int i=0;i<n;i++){
        do{
            fgets(a[i],sizeof(a[i]),stdin);
            a[i][strcspn(a[i],"\n")]='\0';
        }while(strlen(a[i])!=10);
    }
    scanf("%d",&m);
    getchar();
    char b[m][100];
    for(int i=0;i<m;i++){
        do{
           fgets(b[i],sizeof(b[i]),stdin);
           b[i][strcspn(b[i],"\n")]='\0';
        }while(strlen(b[i])!=10);
    }
    //chèn vô mảng a
    for(int i=0;i<m;i++){
        int index=serialNumber(b[i]);
        insert(a,b[i],index,&n);
    }
    //xuất
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%s\n",a[i]);
    }
}