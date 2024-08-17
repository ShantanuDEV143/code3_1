#include<stdio.h>
int main() {
    int i,n,sum;
    printf("ENter the size of array\n");
    scanf("%d",&n);
    int arr[n];
    printf("ENter the values in array\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sum=0;
    for(i=0;i<n;i++){
        sum=sum+arr[i];
        printf("%d\t",sum);
    }
    return 0;
}