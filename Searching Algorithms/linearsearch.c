#include<stdio.h>
int main(){
    int n;
    printf("Enter the Size of Array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the Elements of Array : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int key;
    printf("Enter the Element to be Searched : ");
    scanf("%d",&key);
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            printf("Element Found at Index : %d\n",i);
            return 0;
        }
    }
    printf("Element Not Found\n");
    return 0;
}