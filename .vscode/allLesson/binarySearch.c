#include "stdio.h"
int binarySearch(int arr[], int n, int value,int *comps) {
    int l=0,r=n-1,mid,temp,i=1;
    while (l<=r){
        mid=(l+r)/2;
        temp=arr[mid];
        printf("Pass through %d: l=%d ;r=%d",i,l,r);
        (*comps)++;
        printf(" comps=%d ",*comps);
        if (value<temp){
            printf("%d<%d",value,temp);
            r=mid-1;
        }
        else if(value>temp){
            printf("%d>%d",value,temp);
            l=mid+1;
        }
        else if (value==temp){
            printf("%d=%d",value,temp);
            return mid;
        }   
        i++;
        printf("\n");
    }
    return -1;
}

int main() {
    int n;
    int arr[100];
    int value;
    int comps=0;
    printf("input n \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    //Input arr and value
    printf("input value \n");
    scanf("%d",&value);
    int index = binarySearch(arr, n, value,&comps);
    printf("\n");
    if (index == -1) printf("Not found!");
    else printf("Found %d at %d", value, index);
    printf("\nTotal comps : %d",comps);
}