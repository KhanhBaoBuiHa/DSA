#include "stdio.h"
#include "stdlib.h"
#define MAX 100

typedef struct GuestNode {
    char guestName;                 
    char roomCode[10];              
    struct GuestNode* nextGuest;    
} GuestNode;

typedef struct Hotel {
    GuestNode* rooms[17][12];
} Hotel;

void init(Hotel* hotel){
    for(int i=0;i<17;i++){
        for(int j=0;j<12;j++){
            hotel->rooms[i][j] = NULL;
        }
    }
}

//problem 1
void assignGuestsToRooms(Hotel* hotel, char guests[], int numGuests, int groupIndex) {
    GuestNode* prevGuest = NULL;
    for (int g = 0; g < numGuests; g++) {
        int assigned = 0;

        // Tìm phòng trống
        for (int i = 0; i < 17; i++) {
            for (int j = 0; j < 12; j++) {
                if (hotel->rooms[i][j] == NULL) {  // Phòng trống
                    // Tạo node cho khách mới
                    GuestNode* newGuest = (GuestNode*)malloc(sizeof(GuestNode));
                    newGuest->guestName = guests[g];
                    sprintf(newGuest->roomCode, "P%d.%d", i, j);
                    newGuest->nextGuest = NULL;

                    hotel->rooms[i][j] = newGuest;  // Đưa khách vào phòng

                    // Liên kết khách trong đoàn
                    if (prevGuest != NULL) {
                        prevGuest->nextGuest = newGuest;
                    }
                    prevGuest = newGuest;

                    assigned = 1;
                    break;
                }
            }
            if (assigned) break;
        }
    }
}

//problem 2
void getGroupInfo(Hotel* hotel, char* startRoom) {
    int floor, room;
    sscanf(startRoom, "P%d.%d", &floor, &room);

    GuestNode* current = hotel->rooms[floor][room];
    if (current == NULL) {
        printf("Group leader not found %s.\n", startRoom);
        return;
    }

    printf("Group information:\n");
    while (current != NULL) {
        printf("Guest: %c, Room: %s\n", current->guestName, current->roomCode);
        current = current->nextGuest;
    }
}

//problem 3
void addNewGuests(Hotel* hotel, char* startRoom, char newGuests[], int numNewGuests) {
    int floor, room;
    sscanf(startRoom, "P%d.%d", &floor, &room);

    GuestNode* current = hotel->rooms[floor][room];
    if (current == NULL) {
        printf("Group leader not found %s.\n", startRoom);
        return;
    }

    // Duyệt đến cuối danh sách liên kết
    while (current->nextGuest != NULL) {
        current = current->nextGuest;
    }

    // Thêm các khách mới
    for (int i = 0; i < numNewGuests; i++) {
        for (int f = 0; f < 17; f++) {
            for (int r = 0; r < 12; r++) {
                if (hotel->rooms[f][r] == NULL) {  // Phòng trống
                    GuestNode* newGuest = (GuestNode*)malloc(sizeof(GuestNode));
                    newGuest->guestName = newGuests[i];
                    sprintf(newGuest->roomCode, "P%d.%d", f, r);
                    newGuest->nextGuest = NULL;

                    hotel->rooms[f][r] = newGuest;  // Đưa khách vào phòng
                    current->nextGuest = newGuest; // Liên kết vào đoàn
                    current = newGuest;
                    break;
                }
            }
        }
    }
}

//problem 4
void checkOutGroup(Hotel* hotel, char* startRoom) {
    int floor, room;
    sscanf(startRoom, "P%d.%d", &floor, &room);

    GuestNode* current = hotel->rooms[floor][room];
    if (current == NULL) {
        printf("Group leader not found %s.\n", startRoom);
        return;
    }

    // Giải phóng các node trong linked list
    while (current != NULL) {
        int f, r;
        sscanf(current->roomCode, "P%d.%d", &f, &r);
        hotel->rooms[f][r] = NULL;

        GuestNode* temp = current;
        current = current->nextGuest;
        free(temp);
    }
}

//problem 5
void display(Hotel* hotel){
    for(int i=0;i<17;i++){
        for(int j=0;j<12;j++){
            printf("Room %d.%d: ", i, j);
            GuestNode* current = hotel->rooms[i][j];
            while(current != NULL){
                printf("%s, ", current->guestName);
                current = current->nextGuest;
            }
            printf("\n");
        }
    }
}
int main(){
    Hotel list;
    init(&list);
    int choice;
    do{
        printf("______________HOTEL MANAGING PROGRAM____________\n");
        printf("1. Guests assignment\n");
        printf("2. Get group's information\n");
        printf("3. Add new guest\n");
        printf("4. Check-out group\n");
        printf("5. Display all rooms\n");
        printf("6. Exit\n");
        printf("________________________________________________\n");
        printf("Press here to use : (1-6)");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                char guests[MAX];
                int numGuests;
                int groupIndex;
                printf("Enter number of guests: ");
                scanf("%d", &numGuests);
                printf("Enter guests' names: ");
                for (int i = 0; i < numGuests; i++) {
                    scanf(" %c", &guests[i]);
                }
                printf("Enter group index: ");
                scanf("%d", &groupIndex);
                assignGuestsToRooms(&list, guests, numGuests, groupIndex);
                break;
            case 2:
                char startRoom[10];
                printf("Enter start room: ");
                scanf("%s", startRoom);
                getGroupInfo(&list, startRoom);
                break;    
            case 3:
                char newGuests[MAX];
                int numNewGuests;
                printf("Enter start room: ");
                scanf("%s", startRoom);
                printf("Enter number of new guests: ");
                scanf("%d", &numNewGuests);
                printf("Enter new guests' names: ");
                for (int i = 0; i < numNewGuests; i++) {
                    scanf(" %c", &newGuests[i]);
                }
                addNewGuests(&list, startRoom, newGuests, numNewGuests);
                break;
            case 4:
                printf("Enter start room: ");
                scanf("%s", startRoom);
                checkOutGroup(&list, startRoom);
                break;
            case 5:
                display(&list);
                break;
        }
    }while(choice!=6);
    return 0;
}