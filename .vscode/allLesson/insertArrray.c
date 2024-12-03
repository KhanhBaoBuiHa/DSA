#include "stdio.h"
void insertArray(int a[], int *n, int value, int index, int *assigns){
    int q=1;
    for(int i=*n;i>index;i--){
        (*assigns)++;
        a[i]=a[i-1];
        printf("Pass through %d : [",q);
        for(int j=0;j<(*n);j++){
            printf("%d ",a[j]);
        }
        printf("] => assigns = %d \n",*assigns);
        q++;
    }
    (*assigns)++;
    a[index]=value;
    (*n)++;
}

int main() {
    int n = 5;
    int array[10] = { 3, 1, 5, 7, 4 };
    int value;
    int index = 2;
    value = 8;
    int assigns=0;
    insertArray(array, &n, value, index,&assigns);    // 3 1 8 5 7 4
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }
    printf("Total assigns : %d ", assigns);
}
