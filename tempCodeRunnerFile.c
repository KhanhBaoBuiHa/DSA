#include "stdio.h"
#include "time.h"
#include "stdlib.h"
void f(int a[], int n, int b[], int *comps,int *shifts)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i] == a[j])
                {
                    b[a[i]]++;
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
void initializeArray(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min +(rand() % (max - min + 1));
    }
}
int main(){
    int n=10,min=-100,max=100,comps=0,shifts=0;
    int k[3]={100,1000,10000};
    int a[n];
    time_t t;
    srand((unsigned)time(&t));
    for(int i=0;i<3;i++){
        printf("k=%d\n",k[i]);
        for(int j=0;j<k[i];j++){
            initializeArray(a, n, min, max);
            f(a,n,&comps,&shifts);
        }
        float A=Average(comps,k[i]);
        printf("average comps : %.3f\n",A);
        float B=Average(shifts,k[i]);
        printf("average shitfs : %.3f\n",B);
    }
}