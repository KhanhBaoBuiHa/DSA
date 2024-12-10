#include "stdio.h"
#include "time.h"
#include "stdlib.h"
void initializeArray(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min +(rand() % (max - min + 1));
    }
}
void kiemTra(int a[],int n,int value,int *comps){
    for(int i=0;i<n;i++){
        (*comps)++;
        if(a[i]<value){
            break;
        }
    }
}
int main(){
    time_t t;
    srand((unsigned)time(&t));
    int a[10],n=10;
    int value =10,sum=0;
    for(int i=0;i<10000;i++){
        initializeArray(a,n,0,20);
        int comps=0;
        kiemTra(a,n,value,&comps);
        sum+=comps;
    }
    printf("Average comps : %.2f",(float)sum/10000);
}