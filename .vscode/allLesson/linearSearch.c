#include "stdio.h"
int searchArray(int arr[], int n, int val, int *comps){
    int index=-1;
    for(int i=0;i<n;i++){
        (*comps)++;
        if(arr[i]==val) return i;
    }
    return index;
}
int main() {
    int n;
    int arr[100];
    int value;
    int comps=0;

    //Input arr and value
    scanf("%d %d", &n,&value);
    for(int i=0;i<n;i++){
        printf("a[%d]=",i);
        scanf("%d",&arr[i]);
    }
    int index = searchArray(arr, n, value,&comps);
    if (index == -1) printf("Not found!");
    else printf("Found %d at %d", value, index);
    printf("\nTotal comps : %d",comps);
}