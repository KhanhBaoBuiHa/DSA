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
    int n[10]={10,20,30,40,50,60,70,80,90,100};
    int min=-100,max=100;
    int k[6]={10,20,50,100,1000,10000};
    int a[100],comps[6][10000]={0};
    time_t t;
    srand((unsigned)time(&t));
    for(int q=0;q<10;q++){
        printf("n=%d\n",n[q]);
        for(int i=0;i<6;i++){
            for(int j=0;j<k[i];j++){
               initializeArray(a, n[q], min, max);
                bubbleSort(a,n[q],&comps[i][j]);
            }
            float A=Average(comps[i],k[i]);
            printf("k\tcomps\n");
            printf("%d\t%.3f\n",k[i],A);
        }
    }
}