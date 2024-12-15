#include "stdio.h"
#include "time.h"
#include "stdlib.h"
void initializeArray(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min +(rand() % (max - min + 1));
    }
}
void bubbleSort(int arr[], int n, int* swap,int *comps,int *assigns){
    int temp;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n - 1 -i ; j++){
            (*comps)++;
            if(arr[j] < arr[j+1]){
                (*swap)++;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                (*assigns)+=3;
            }
        }
    }
}
void selectionSort(int arr[], int n,int *swap,int *comps,int *assigns) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            (*comps)++;
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        if(maxIndex != i) {
            (*swap)++;
            int temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
            (*assigns)+=3;
        }
    }
}
void insertionSort(int arr[], int n, int *comps, int *assign){
    for (int i = 1; i < n; i++) {
        int key = arr[i],j = i - 1;
        (*comps)++;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
            (*assign)++;
        }
        arr[j + 1] = key;
        (*assign)++;
    }
}
int main(){
    time_t t;
    srand((unsigned)time(&t));
    int n[4]={10,20,50,100};
    for(int i=0;i<4;i++){
        printf("n=%d\n",n[i]);
        printf("     \tbubble\tselection\tinsertion\n");
        int m=n[i];
        int arr[m],a[m],b[m],c[m];
        int swapA=0,swapB=0,swapC=0,compsA=0,compsB=0,compsC=0,assignA=0,assignB=0,assignC=0;
        initializeArray(arr, m, -100, 100);
        for(int j=0;j<m;j++){
            a[j]=arr[j];
            b[j]=arr[j];
            c[j]=arr[j];
        }
        bubbleSort(a,m,&swapA,&compsA,&assignA);
        selectionSort(b,m,&swapB,&compsB,&assignB);
        insertionSort(c,m,&compsC,&assignC);
        printf("comp  \t%d\t%d\t\t%d\n",compsA,compsB,compsC);
        printf("swap  \t%d\t%d\t\t%d\n",swapA,swapB,swapC);
        printf("assign\t%d\t%d\t\t%d\n",assignA,assignB,assignC);
    }
    return 0;
}