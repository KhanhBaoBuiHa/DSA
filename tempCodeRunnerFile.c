#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Cấu trúc hàng đợi (Queue)
typedef struct {
    int data[MAX]; // Mảng lưu trữ hàng đợi
    int front;     // Chỉ số đầu hàng đợi
    int rear;      // Chỉ số cuối hàng đợi
} Queue;

// Khởi tạo hàng đợi
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Kiểm tra hàng đợi rỗng
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Kiểm tra hàng đợi đầy
int isFull(Queue *q) {
    return (q->rear + 1) % MAX == q->front;
}

// Thêm người dùng vào hàng đợi
void put(Queue *q, int userID) {
    if (isFull(q)) {
        printf("Hàng đợi đầy! Không thể thêm người dùng.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = userID;
    printf("Đã thêm người dùng %d vào hàng đợi.\n", userID);
}

// Lấy người dùng đầu tiên khỏi hàng đợi
void get(Queue *q) {
    if (isEmpty(q)) {
        printf("Hàng đợi rỗng! Không có người dùng nào để lấy.\n");
        return;
    }
    printf("Người dùng đầu tiên (%d) đã được lấy khỏi hàng đợi.\n", q->data[q->front]);
    if (q->front == q->rear) {
        // Hàng đợi chỉ còn một phần tử, đặt lại trạng thái
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
}

// Hủy đăng ký của một người dùng cụ thể
void cancelRegistration(Queue *q, int userID) {
    if (isEmpty(q)) {
        printf("Hàng đợi rỗng! Không có người dùng nào để hủy.\n");
        return;
    }
    Queue temp;
    initQueue(&temp);
    int found = 0;
    while (!isEmpty(q)) {
        int current = q->data[q->front];
        get(q); // Lấy phần tử ra khỏi hàng đợi ban đầu
        if (current != userID) {
            put(&temp, current); // Chỉ thêm phần tử vào hàng đợi tạm nếu khác userID
        } else {
            found = 1;
        }
    }
    // Sao chép hàng đợi tạm trở lại hàng đợi chính
    while (!isEmpty(&temp)) {
        put(q, temp.data[temp.front]);
        temp.front = (temp.front + 1) % MAX;
    }
    if (found) {
        printf("Đã hủy đăng ký người dùng %d.\n", userID);
    } else {
        printf("Người dùng %d không có trong hàng đợi.\n", userID);
    }
}

// Hiển thị toàn bộ hàng đợi
void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Hàng đợi rỗng!\n");
        return;
    }
    printf("Danh sách người dùng trong hàng đợi: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->data[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    int choice, userID;
    do {
        printf("\n--- Hệ thống quản lý đăng ký sự kiện ---\n");
        printf("1. Đăng ký người dùng mới\n");
        printf("2. Lấy người dùng đầu tiên\n");
        printf("3. Hủy đăng ký của một người dùng\n");
        printf("4. Hiển thị danh sách hàng đợi\n");
        printf("5. Thoát\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhập ID người dùng: ");
                scanf("%d", &userID);
                put(&q, userID);
                break;
            case 2:
                get(&q);
                break;
            case 3:
                printf("Nhập ID người dùng cần hủy: ");
                scanf("%d", &userID);
                cancelRegistration(&q, userID);
                break;
            case 4:
                displayQueue(&q);
                break;
            case 5:
                printf("Thoát chương trình.\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ! Vui lòng chọn lại.\n");
        }
    } while (choice != 5);

    return 0;
}
