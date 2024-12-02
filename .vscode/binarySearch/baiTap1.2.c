#include "stdio.h"
int linearSearch(float a[], int n, float val) {
    for (int i = 0; i < n; i++) {
       if(a[i] == val) return i;
       if(a[i] > val) return -1;
    }
    return -1;
}

int main() {
    int n;
    float a[100], val;
    scanf("%d", &n);
    scanf("%f", &val);
    for (int i = 0; i < n; i++) {
        scanf("%f", &a[i]);
    }
    printf("Found %.2f at %d",val , linearSearch(a, n , val));
    return 0;
}