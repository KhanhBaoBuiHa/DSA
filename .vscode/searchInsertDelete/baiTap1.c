#include "stdio.h"
#include "math.h"
int main(){
    float n[10];
    int m,size,d,min=100,index;
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        scanf("%f",&n[i]);
    }
    scanf("%d",&m);
    for(int i=0;i<size;i++){
        d=abs(n[i]-m);
        if(d<min){
            min=d;
            index=i;
        }
    }
    printf("%.2f at index %d nearest to %d",n[index],index,m);
}