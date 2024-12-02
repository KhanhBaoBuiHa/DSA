#include "stdio.h"
#include "time.h"
#include "stdlib.h"
void initializeArray(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min +(rand() % (max - min + 1));
    }
}
void bubbleSort(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            if(a[j-1]>a[j]){
                int temp=a[j-1];
                a[j-1]=a[j];
                a[j]=temp;
            }
        }
    }
}
int main(){
    int n=20,min=-100,max=100;
    int a[n];
    time_t t;
    srand((unsigned)time(&t));
    initializeArray(a, n, min, max);
    bubbleSort(a,n);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}