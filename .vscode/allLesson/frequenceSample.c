#include "stdio.h"
#include "time.h"
#include "stdlib.h"
void initializeArray(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min +(rand() % (max - min + 1));
    }
}
float Average(int a[],int n,int k){
    float sum=0;
    for(int i=0;i<n;i++){
        sum+=i*a[i];
    }
    return sum/k;
}
void f(int a[], int n, int b[],int *comps)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                (*comps)++;
                if (a[i] == a[j])
                {
                    b[a[i]]++;
                }
            }
        }
    }
int main()
{
    time_t t;
    srand((unsigned)time(&t));
    int arr[20],b[200], n = 20;
    int max=100,min=-100;
    int k[3] = {100,1000,10000};
    for (int i=0; i<3; i++)
    {
        printf("k=%d \n", k[i]);
        int fre[401] = {0};
        for(int j=0; j<k[i]; j++) {
            initializeArray(arr, n, min, max);
            int comps=0;
            f(arr,n,b,&comps);
            (fre[comps])++; 
        }
        float A=Average(fre, 401, k[i]); 
        for (int j = 1; j <= 401; j++)
        {
            printf("%d:%d ", j, fre[j]);
        }
        printf("Average: %0.3f\n", A);
    }
    return 0;
}   