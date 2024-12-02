#include "stdio.h"
#include "time.h"
#include "stdlib.h"
void initializeArray(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min +(rand() % (max - min + 1));
    }
}
void deleteArray(char a[], int *n, int index, int *compsA){
    for(int i=index;i<*n;i++){
        (*compsA)++;
        a[i]=a[i+1];
    }
    (*n)--;    
}
void caseA(int a[],int n, int k, int *compsA){
    for(int i=0;i<n;i++){
        (*compsA)++;
        if(a[i]>=k) deleteArray(a,&n,i,compsA);
    }
}
void bubbleSort(int a[],int n,int *compsB){
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            (*compsB)++;
            if(a[j-1]>a[j]){
                int temp=a[j-1];
                a[j-1]=a[j];
                a[j]=temp;
            }
        }
    }
}
void caseB(int a[], int *n, int k,int *compsB){
    bubbleSort(a,n);
    int i=n-1,j=0;;
    while(a[i]<k){
        (*compsB)++;
        a[i]='\0';
        (*n)--;
        i--;
    }
}
int main(){
    int n=100,min=1998,max=2023,k=2016;
    int a[n];
    time_t t;
    srand((unsigned)time(&t));
    initializeArray(a, n, min, max);
    int rsA[n],rsB[n],compsA=0,compsB=0;
    for(int i=0,i<n;i++){
        rsA[i]=a[i];
        rsB[i]=a[i];
    }
    caseA(rsA,&n,k,&compsA);
    caseB(rsB,&n,k,&compsB);
    printf("Case A :\n");
    for(int i=0;i<n;i++){
        printf("%d ",rsA[i]);
    }
    printf("\nComps : %d",compsA);
    printf("\nCase B :\n");
    for(int i=0;i<n;i++){
        printf("%d ",rsB[i]);
    }
    printf("\nComps : %d",compsB);
}