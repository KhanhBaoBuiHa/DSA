#include "stdio.h"
void insertArray(float a[], int *n, float value, int index){
    for(int i=*n;i>index;i--){
        a[i]=a[i-1];
    }
    a[index]=value;
    (*n)++;
}
int main(){
    int n,m,k;
    scanf("%d",&n);
    float a[n];
    for(int i=0;i<n;i++){
        scanf("%f",&a[i]);
    }
    scanf("%d",&m);
    float b[m];
    int l[m];
    for(int i=0;i<m;i++){
        scanf("%f %d",&b[i],&l[i]);
    }
    for(int i=0;i<m;i++){
        insertArray(a,&n,b[i],l[i]+i);
    }
    for(int i=0;i<(n+m);i++){
        printf("%.2f ",a[i]); 
    }
}