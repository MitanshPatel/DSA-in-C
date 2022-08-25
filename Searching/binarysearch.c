#include<stdio.h>

int BinarySearch(int arr[], int n, int key){
    int start=0; //start position of array
    int end=n-1; //end position of array
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return -1;
}

int main(){
    //take input
    int n;
    printf("Number of elements in array?\n");
    scanf("%d",&n);
    int arr[n];
    
    for(int i=0;i<n;i++){
        int num;
        printf("Enter element %d of array\n", i+1);
        scanf("%d", &num);
        arr[i]=num;
    }
    int key;
    printf("Enter element to find\n");
    scanf("%d",&key);
    int b=BinarySearch(arr,n,key);
    if (b==-1){
        printf("Element not found\n");
    }
    else printf("Element at position %d\n",b+1);

}