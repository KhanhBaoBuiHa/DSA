#include "stdio.h"
#include "time.h"
#include "stdlib.h"
int minIndex(float arr[],int n,int *comps){
    int min=0;
    for(int i=0;i<n;i++){
        (*comps)++;
        if(arr[min]>arr[i]) min=i;
    }
    return min;
}
void initializeArray(float arr[],int n,int min,int max){
    for(int i=0;i<n;i++){
        arr[i]=min+(float)(rand()%(max-min+1));
    }
}
float Average(int a[],int n,int k){
    float sum=0;
    for(int i=0;i<n;i++){
        sum+=i*a[i];
    }
    sum/=k;
    return sum;
}
int main(){
    float a[20];
    int n;
    scanf("%d",&n);
    int min=-2*n,max=2*n;
    int k[5]={10,20,50,100,1000};
    time_t t;
    srand((unsigned)time(&t));
    for(int i=0;i<5;i++){
        printf("k=%d\n",k[i]);
        int fre[21]={0};
        for(int j=0;j<k[i];j++){
            initializeArray(a,n,min,max);
            int comps=0;
            minIndex(a,n,&comps);
            fre[comps]++;
        }
        float A=Average(fre, n+1, k[i]);
        for (int j = 1; j <= 20; j++){
            printf("%d:%d ", j, fre[j]);
        }
        printf("Average : %.3f\n",A);
    }
    return 0;
}