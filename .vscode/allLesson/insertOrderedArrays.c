#include "stdio.h"
void insertOrderedArray(int a[],int *n,int value){
    int index=0;
    for(int i=0;i<*n;i++){
        if(value<a[i]){ 
            index= -1;
            break;
        }
        if(value>=a[i] && value<=a[i+1]){
            index= i+1;
            break;
        } 
    }
    for(int i=*n;i>index;i--){
        a[i]=a[i-1];
    }
    a[index]=value;
    (*n)++;
}
int main(){
    int n,array[10], value;
    scanf("%d %d",&n,&value);
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    insertOrderedArray(array, &n, value);    
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }
}