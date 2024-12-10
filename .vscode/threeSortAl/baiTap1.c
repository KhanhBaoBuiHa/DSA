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
            if(arr[j] > arr[j+1]){
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
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            (*comps)++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            (*swap)++;
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            (*assigns)+=3;
        }
    }
}
void insertionSort(int arr[], int n, int *comps, int *shift){
    for (int i = 1; i < n; i++) {
        int key = arr[i],j = i - 1;
        (*comps)++;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            (*shift)++;
        }
        arr[j + 1] = key;
    }
}

int main(){
    time_t t;
    srand((unsigned)time(&t));
    int arr[20],a[20],b[20],c[20];
    for(int i=0;i<20;i++){
        
    }
}