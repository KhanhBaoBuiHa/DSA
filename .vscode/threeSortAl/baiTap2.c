#include "stdio.h"
#include "time.h"
#include "stdlib.h"
void initializeArray(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min +(rand() % (max - min + 1));
    }
}
/*
void bubbleSort(int arr[], int n){
    int temp;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n - 1 -i ; j++){
            if(arr[j] < arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
*/
/*
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        if(maxIndex != i) {
            int temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
    }
}
*/
/*
void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++) {
        int key = arr[i],j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
*/
int main(){
    time_t t;
    srand((unsigned)time(&t));
    int arr[20];
    initializeArray(arr, 20, -100, 100);
    //bubbleSort(arr,20);
    //selectionSort(arr,20);
    //insertionSort(arr,20);
    for(int i=0;i<20;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}