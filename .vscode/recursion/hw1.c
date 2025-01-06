#include "stdio.h"
int f(int n)
{
    if (n == 1)
        return 1;
    return f(n-1)*2;
}
/*
base case 1
result of base case f(1)=1
before base case f(2)=f(1)*2=2
before before f(3)=f(2)*2=2*2=4
*/
//kĩ thuật ko đệ quy
int f1(int n){
    int sum=0;
    while(1){
        sum+=n;
        n--;
        if(n==1) break;
    }
    return sum;
}
/***************************************************/
float g(int n)
{
    if (n == 1)
        return 1.0;
    return n * n + g(n - 1);
}
/*
base case 1
result of base case f(1)=1.0 
before base case f(2)=2*2+f(1)=5
before before f(3)=3*3+f(2)=14
*/
//kĩ thuật không đệ quy
float g1(int n){
    float sum=0;
    while(1){
        sum+=n*n;
        if(n==1) break;
    }
    return sum;
}
/***************************************************/
int F(int n)
{
    if (n == 1) return 1;
    if (n == 2) return 1;
    return F(n-1)+F(n-2);
}
/*
base case n=1,n=2
result of base case F(1)=1
before base case F(2)=2
before before F(3)=F(2)+F(1)=2
*/
//kĩ thuật không đệ quy
int F1(int n){
    int a=1,b=1;
    if(n==1 || n==2) return 1;
    for(int i=3;i<=n;i++){
        int temp=a+b;
        a=b;
        b=temp;
    }
    return b;
}
/***************************************************/
int P(int n)
{
    if (n == 0) return 1;
    if (n == 1) return 2;
	if (n == 2) return 3;
    return P(n-1)*P(n-3);
}
/*
base case n=0,n=1,n=2 
result of base case F(1)=2
before base case F(2)=3
before before F(3)=F(2)+F(0)=3+1=4
*/
//kĩ thuật không đệ quy
int P1(int n){
    if (n == 0) return 1;
    if (n == 1) return 2;
	if (n == 2) return 3;
    int a=1,b=2,c=3;
    int current;
    for(int i=3;i<=n;i++){
        int temp= c*a;
        a=b;
        b=c;
        c=current;
    }
    return current;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("\t\tf\tg\tF\tP\n");
    printf("de quy   \t%d\t%.2f\t%d\t%d\t\n",f(n),g(n),F(n),P(n));
    printf("ko de quy\t%d\t%.2f\t%d\t%d\t",f1(n),g1(n),F1(n),P1(n));
}