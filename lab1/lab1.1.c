#include<stdio.h>
int main() {
    int n,temp;
    int second_smallest, second_largest;
    printf("ENter the size of array\n");
    scanf("%d",&n);
    int arr[n];
    printf("ENter the values in array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
 
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    second_largest=arr[n-2];
    second_smallest=arr[1];
     printf("\nsecond largest element is %d\n",second_largest);
     printf("\nsecond_smallest element is %d\n",second_smallest);
     return 0;
}