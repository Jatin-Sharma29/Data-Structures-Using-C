#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    //Bubble sort
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){ // we can also write n-1 but in it it will do unnecessary checking.
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }    
        }
    }
    printf("After sorting\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}