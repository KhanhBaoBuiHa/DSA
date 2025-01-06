#include "stdio.h"
/*
BASE CASE n=1

RESULT OF BASE CASE 
countInverse(a,1,&cnt)=0

BEFORE BASE CASE 
n=2
a[1]>a[0] (2>1)
countInverse(a,2,&cnt)=countInverse(a,1,&cnt)=0

BEFORE BEFORE 
n=3;
a[2]<a[1] (4>2)
countInverse(a,3,&cnt)=countInverse(a,2,&cnt)=countInverse(a,1,&cnt)=0
*/
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

int main() {
    int a[] = {1, 2, 4, 3, 6, 5, 7, 8};
    int cnt=0;
    printf("%d\n", countInverse(a, 8,&cnt));
    printf("%d\n",cnt);
    return 0;
}