#include "stdio.h"
int find(float x[][2], int n,float x1,float x2){
    for(int i=0;i<n;i++){
        if(x[i][0]==x1 && x[i][1]==x2) return i;
    }
    return -1;
}
void delete(float x[][2], int *n,int index){
    for(int i=index; i<*n-1;i++){
        x[i][0]=x[i+1][0];
        x[i][1]=x[i+1][1];
    }
    (*n)--;
}
int main(){
    int n;
    scanf("%d",&n);
    float x[n][2];
    float x1,x2;
    for(int i=0;i<n;i++){
        scanf("%f %f",&x[i][0],&x[i][1]);
    }
    scanf("%f %f",&x1,&x2);
    int index=find(x,n,x1,x2);
    if(index==-1) printf("Can not delete %.2f %.2f from the array!",x1,x2);
    else{
        delete(x,&n,index);
        for(int i=0;i<n;i++){
            printf("\n%.2f %.2f",x[i][0],x[i][1]);
        }
        printf("\nDelete %.2f %.2f at %d",x1,x2,index);
    }
<<<<<<< HEAD
}
=======
}
>>>>>>> 2feef14a632dcf41a166be9f0d75937b674767f7
