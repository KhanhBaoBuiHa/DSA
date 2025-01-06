//EX2
#include "stdio.h"
#include "time.h"
#include "stdlib.h"
void initializeArray(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min +(rand() % (max - min + 1));
    }
}
int countInverse(int a[], int n,int *cnt) {
    if (n == 1)
        return 0;
    if (a[n-1] < a[n-2]){
        (*cnt)++;
        return 1 + countInverse(a, n-1,cnt);
    }
    else
        return countInverse(a, n-1,cnt);
}
int main(){
    time_t t;
    srand((unsigned)time(&t));
    int a[10],sum=0;
    for(int i=0;i<10000;i++){
        initializeArray(a,10,-100,100);
        int cnt=0;
        countInverse(a,10,&cnt);
        sum+=cnt;
    }
    printf("Average : %.2f",(float)sum/10000);
    return 0;
}