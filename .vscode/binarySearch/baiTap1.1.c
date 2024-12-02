#include "stdio.h"
void insertOrderedArray(float a[],int *n,float value){
    int index=*n;
    for (int i = 0; i < *n; i++) {
        if (value < a[i]) {
            index = i;
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
    int n;
    float array[10], value;
    scanf("%d %f",&n,&value);
    for(int i=0;i<n;i++){
        scanf("%f",&array[i]);
    }
    insertOrderedArray(array, &n, value);    
    for(int i=0;i<n;i++){
        printf("%.2f ",array[i]);
    }
}