#include "stdio.h"
#include "time.h"
#include "stdlib.h"
void initializeArray(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min +(rand() % (max - min + 1));
    }
}
int minIndex(int arr[],int n,int j,int *comps){
    int min=j;
    for(int i=j+1;i<n;i++){
        (*comps)++;
        if(arr[min]>arr[i]){
            min=i;
        }
    }
    return min;
}
void sort(int a[],int n,int *comps,int *swap){
    for(int i=0;i<n-1;i++){
        int minIdx=minIndex(a,n,i,comps);
        if(minIdx!=i){
            (*swap)++;
            int temp=a[minIdx];
            a[minIdx]=a[i];
            a[i]=temp;
        }
    }
}
int main(){
    int n=40,comps=0,swap=0,min=0,max=10;
    int k[]={};
    int a[n];
    time_t t;
    srand((unsigned)time(&t));
    initializeArray(a, n, min, max);
    sort(a,n,&comps,&swap);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\nComps : %d",comps);
}