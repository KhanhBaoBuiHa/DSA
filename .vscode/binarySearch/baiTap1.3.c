#include "stdio.h"
int binarySearch(float arr[], int n, float value) {
    int lower=0,upper=n-1,mid;
    float temp;
    while (lower<=upper){
        mid=(lower+upper)/2;
        temp=arr[mid];
        if (value<temp) upper=mid-1;
        else if(value>temp) lower=mid+1;
        else return mid;
    }
    return -1;
}
int main() {
    int n;
    float arr[100], value;
    scanf("%d",&n);
    scanf("%f",&value);
    for(int i=0;i<n;i++){
        scanf("%f",&arr[i]);
    }
    if (binarySearch(arr, n, value) == -1)
        printf("Not found!");
    else
        printf("Found %.2f at %d", value, binarySearch(arr, n, value));
}