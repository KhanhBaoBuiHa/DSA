#include "stdio.h"
#include "string.h"

// Hàm này để tách chuỗi con có độ dài bằng mã độc
/* 
maDoc : thứ tự mã độc
start : vị trí bắt đầu của chuỗi con trong chuỗi
*/
void tachChuoi(char* result, char str[], int start, int len) {
    strncpy(result, str + start, len);
    result[len] = '\0';  // Kết thúc chuỗi
}

// Hàm tìm kiếm mã độc
int find(char s[], char str[]) {
    int lenStr = strlen(str);
    int lenSubStr = strlen(s);
    
    // Duyệt qua chuỗi gói tin để tìm chuỗi con
    for (int i = 0; i <= lenStr - lenSubStr; i++) {
        char temp[lenSubStr + 1];
        tachChuoi(temp, str, i, lenSubStr);
        if (strcmp(temp, s) == 0) {
            return i;  // Trả về vị trí tìm thấy
        }
    }
    return -1;  // Trả về -1 nếu không tìm thấy
}

int main() {
    char str[1000];
    int k;

    // Nhập gói tin
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Xóa bỏ ký tự xuống dòng

    // Nhập số lượng mã độc
    scanf("%d", &k);
    getchar();  // Xóa bỏ ký tự xuống dòng trong bộ đệm

    char s[k][100];  // Mã độc tối đa là k chuỗi

    // Nhập các chuỗi mã độc
    for (int i = 0; i < k; i++) {
        fgets(s[i], sizeof(s[i]), stdin);
        s[i][strcspn(s[i], "\n")] = '\0';  // Xóa bỏ ký tự xuống dòng
    }

    // Duyệt qua từng chuỗi mã độc và tìm kiếm trong gói tin
    for (int i = 0; i < k; i++) {
        int cnt = 0;  // Đếm số lượng chuỗi mã độc xuất hiện
        int index = find(s[i], str);

        if (index != -1) {
            cnt++;  // Tăng số lượng mã độc nếu tìm thấy
            printf("%d %s %d\n", cnt, s[i], index);
        } else {
            printf("0 %s\n", s[i]);
        }
    }

    return 0;
}
