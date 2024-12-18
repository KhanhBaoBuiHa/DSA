#include<stdio.h>
void deleteArray(int a[], int* n, int index,int *assigns){
    int q=1;
    for(int i=index;i<*n-1;i++){
        (*assigns)++;
        a[i]=a[i+1];
        printf("Pass through %d : [",q);
        for (int j = 0; j < *n - 1; j++){
            printf("%d ",a[j]);
        }
        printf("] => assigns = %d \n",*assigns);
        q++;
    }
    (*n)--;    
}
int main(){
    int a[] = {1,4,3,7,5};
    int n = 5;
    int index = 2;
    int assigns=0;
    deleteArray(a,&n,index,&assigns);
    for(int i = 0; i < n; i++){
        printf("%d ",a[i]);
    }
    printf("Total assigns : %d ", assigns);
}