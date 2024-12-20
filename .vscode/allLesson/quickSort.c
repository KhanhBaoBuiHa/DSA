#include "stdio.h"
int  partition(int a[], int  left, int right){
	int pivot = a[right];
	while(left<right){
	    while(a[left]<pivot) left++;
	    while(a[right]>pivot) right--;
	    if(right>left){
	        int temp=a[right];
	        a[right]=a[left];
	        a[left]=temp;
	    }
	}
	int temp=pivot;
	pivot=a[left];
	a[left]=pivot;
	return left;
}
void quickSort(int a[], int left, int right){
    if(left<right){
    int p=partition(a,left,right);
    quickSort(a,left,p-1);
    quickSort(a,p+1,right);}
}
int main(){
    int n;
    int a[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d ",&a[i]);
    }
    printf("left=%d",partition(a,0,n-1));
    quickSort(a,0,n-1);
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
