#include "stdio.h"
void bubbleSort(int arr[], int n, int* swap,int *comps,int *assigns){
    int temp;
    for(int i = 0 ; i < n ; i++){
        printf("Round %d:\n",i+1);
        for(int j = 0 ; j < n - 1 -i ; j++){
            printf("Pass through %d: [",j+1);
            (*comps)++;
            if(arr[j] > arr[j+1]){
                (*swap)++;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                (*assigns)+=3;
            }
            for(int i=0;i<n;i++){
                    printf(" %d",arr[i]);
                }
            printf(" ] => Comps=%d, Swaps=%d, Assigns=%d\n",*comps,*swap,*assigns);
        }
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
    bubbleSort(arr,n,&swap,&comps,&assigns);
    for ( int j = 0 ; j < n ; j++){
    printf("%d ",arr[j]);
    }
    printf("\n Total Swap = %d;",swap);
    printf("Total comps = %d;",comps);
    printf("Total assigns = %d",assigns);
    return 0;
}