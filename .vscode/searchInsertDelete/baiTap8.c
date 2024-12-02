#include "stdio.h"
#include "string.h"
void deleteArray(char a[], int *n, int index){
    for(int i=index;i<*n;i++){
        a[i]=a[i+1];
    }
    (*n)--;    
}
int main(){
    int n;
    char str[1000];
    fgets(str,sizeof(str),stdin);
    scanf("%d",&n);
    int l=strlen(str);
    deleteArray(str,&l,n);
    printf("%s",str);
}
