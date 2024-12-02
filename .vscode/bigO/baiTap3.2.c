#include "stdio.h"
#include "time.h"
#include "stdlib.h"
void initializeArray(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min +(rand() % (max - min + 1));
    }
}
void bubbleSort(int a[],int n,int *comps){
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            (*comps)++;
            if(a[j-1]>a[j]){
                int temp=a[j-1];
                a[j-1]=a[j];
                a[j]=temp;
            }
        }
    }
}
float Average(int a[],int k) {
    float sum=0;
    for(int i=0;i<k;i++){
        sum+=a[i];
    }
    return sum/k;
}
int main(){
    int n=20,min=-100,max=100;
    int k[6]={10,20,50,100,1000,10000};
    int a[n],comps[6][10000]={0};
    time_t t;
    srand((unsigned)time(&t));
    for(int i=0;i<6;i++){
        printf("k=%d\n",k[i]);
        for(int j=0;j<k[i];j++){
            initializeArray(a, n, min, max);
            bubbleSort(a,n,&comps[i][j]);
        }
        float A=Average(comps[i],k[i]);
        printf("average comps : %.3f\n",A);
    }
}