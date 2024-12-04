#include "stdio.h"
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
        printf("Pass through %d: [",i+1);
        for(int k=0;k<n;k++){
            printf(" %d",arr[k]);
        }
        printf(" ] => Comps=%d, Swaps=%d, Assigns=%d\n",*comps,*swap,*assigns);
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
    int swap=0,comps=0,assigns=0;
    printf("\nAfter sort : ");
    selectionSort(arr,n,&swap,&comps,&assigns);
    for ( int j = 0 ; j < n ; j++){
    printf("%d ",arr[j]);
    }
    printf("\nTotal Swap = %d;",swap);
    printf("Total comps = %d;",comps);
    printf("Total assigns = %d",assigns);
    return 0;
}