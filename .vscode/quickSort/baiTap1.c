#include "stdio.h"
#include "time.h"
#include "stdlib.h"
void initializeArray(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min +(rand() % (max - min + 1));
    }
}
int partition(int a[], int  left, int right,int *shiftLeft,int *shiftRight){
    int pivot = a[right];
    right--;
    while(left<right){
        while(a[left]<pivot){
            left++;
            (*shiftLeft)++;
        }
        while(a[right]>pivot){
            right--;
            (*shiftRight)++;
        }
        if(left<right){
            int temp=a[right];
            a[right]=a[left];
            a[left]=temp;
        }
    }
    int temp=pivot;
    pivot=a[left];
    a[left]=temp;
    return left;
}
void quickSort(int a[], int left, int right,int *shiftLeft,int *shiftRight){
    if (left >= right) return;
    int indexPivot = partition(a, left, right,shiftLeft,shiftRight);
    quickSort(a,left,indexPivot - 1,shiftLeft,shiftRight);
    quickSort(a,indexPivot + 1, right,shiftLeft,shiftRight);
}
int main(){
    time_t t;
    srand((unsigned)time(&t));
    int arr[10];
    int k[4]={10,100,1000,10000};
    for(int i=0;i<4;i++){
        int totalShiftLeft=0,totalShiftRight=0;
        printf("k=%d\n",k[i]);
        for(int j=0;j<k[i];j++){
            int shiftLeft=0,shiftRight=0;
            initializeArray(arr,10,-100,100);
            quickSort(arr,0,9,&shiftLeft,&shiftRight);
            totalShiftLeft+=shiftLeft;
            totalShiftRight+=shiftRight;
        }
        printf("Average shift left: %0.2f\n",(float)totalShiftLeft/k[i]);
        printf("Average shift right: %0.2f\n",(float)totalShiftRight/k[i]);
    }
    return 0;
}