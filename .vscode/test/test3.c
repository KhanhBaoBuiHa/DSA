//bài 1
/*
1.
u(n)=n*(n+1)
3.
base case : n=0
result of base case : S(0)=0
before base case : S(1)=S(0)+1*(1+1)=2
before before : S(2)=S(1)+2*(2+1)=8
*/
/*
#include "stdio.h"
int S(int n){
    if(n==0) return 0;
    return S(n-1)+n*(n+1);
}
int S1(int n){
    int sum=0;
    for(int i=0;i<=n;i++){
        sum+=n*(n+1);
    }
}
*/
//bài 3
