#include "stdio.h"
void insertionSort(int arr[], int n, int *comps, int *shift){
    for (int i = 1; i < n; i++) {
        printf("Pass through %d: [",i);
        int key = arr[i],j = i - 1;
        (*comps)++;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            (*shift)++;
        }
        arr[j + 1] = key;
        for(int i=0;i<n;i++){
            printf(" %d",arr[i]);
        }
        printf(" ] => Comps=%d, Shifts=%d\n",*comps,*shift);
    }
}
int main() {    
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("Before sort : ");
    for(int i=0;i<n;i++){
        printf("a[%d]=",i);
        scanf("%d",&arr[i]);
    }
    for (int i = 0 ; i < n ; i++){
      printf("%d ",arr[i]);
    }     
    int comps=0,shift=0;
    printf("\nAfter sort : \n");
    insertionSort(arr,n,&comps,&shift);
    for ( int j = 0 ; j < n ; j++){
    printf("%d ",arr[j]);
    }
    printf("Total comps = %d;",comps);
    printf("Total shifts = %d",shift);
    return 0;
}