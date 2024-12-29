#include "stdio.h"
int f(int n)
{
    if (n == 1)
        return 1;
    return f(n-1)*2;
}
//kĩ thuật ko đệ quy
int f1(int n)
/*
base case 1
result of base case f(1)=1
before base case f(2)=f(1)*2=2
before before f(3)=f(2)*2=2*2=4
*/
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
int main(){
    
}