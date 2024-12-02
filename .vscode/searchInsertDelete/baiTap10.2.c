#include "stdio.h"
#include "string.h"
#include "stdbool.h"
// Hàm tách chuỗi con từ vị trí start với độ dài l
void tachChuoi(char* result, char str[], int start, int l){
    for(int i=0;i<l;i++){
        result[i]=str[start+i];
    }
    result[l]='\0';
}
// Hàm so sánh hai chuỗi
bool soSanh(char temp[],char s[]){
    for (int i=0;i<strlen(s);i++){
        if (temp[i]!=s[i]) return 0;
    }
    return 1;
}
// Hàm lọc mã độc
void delete(int k,char s[][100], char str[]){
    for (int i=0;i<k;i++) {
        int lenS=strlen(s[i]);
        for (int j=0;j<=strlen(str)-lenS;j++){
            char temp[lenS+1];
            tachChuoi(temp,str,j,lenS);
            if (soSanh(temp,s[i])){
                // Dịch chuỗi về phía trước
                int lenStr=strlen(str);
                for (int p=j;p<=lenStr-lenS;p++) {
                    str[p]=str[p+lenS];
                }
                str[lenStr-lenS]='\0';  // Giảm chiều dài chuỗi sau khi xóa
                j--;  // Kiểm tra lại vị trí j sau khi xóa
            }
        }
    }
}
int main() {
    // Khai báo và nhập chuỗi
    char str[1000];
    int k;
    scanf("%s",&str);
    scanf("%d",&k);
    char s[k][100];
    for(int i=0;i<k;i++) {
        scanf("%s",&s[i]);
    }
    // Lọc mã độc và xuất chuỗi đã lọc
    delete(k,s,str);
    printf("%s",str);
    return 0;
}