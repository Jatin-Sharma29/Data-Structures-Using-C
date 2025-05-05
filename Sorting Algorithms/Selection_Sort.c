#include<stdio.h>
int main(){
    int n;
    printf("Enter the Size: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d Elements :",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    // Selection Sort
    for(int i=0;i<n-1;i++){
        int min_Index=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_Index])
                min_Index=j;
        }
        if(i!=min_Index){
            int temp=arr[i];
            arr[i]=arr[min_Index];
            arr[min_Index]=temp;
        }
    }
    printf("Elements After Sorting are :");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}