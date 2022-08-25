#include<stdio.h>

int partition(int arr[],int st,int end){

    int pi=arr[end];
    int i=st-1;

    for(int j=st;j<end;j++){
        if(arr[j]<pi){
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }

    int temp=arr[i+1];
    arr[i+1]=arr[end];
    arr[end]=temp;

    return i+1;

}   


void quickSort(int arr[],int st,int end){
    if(st<end){
        int pi=partition(arr,st,end);

        quickSort(arr,st,pi-1);
        quickSort(arr,pi+1,end);
    }
}

int main(){
    // take input
    int n;
    printf("Number of elements in array?\n");
    scanf("%d",&n);
    int arr[n];
    
    for(int i=0;i<n;i++){
        int num;
        printf("Enter %d element of array\n",i+1);
        scanf("%d",&num);
        arr[i]=num;
    }
    
    quickSort(arr,0,n-1);
    
    //print
    printf("Below are all elements sorted in ascending order\n");
    for(int i=0;i<n;i++){
        printf("%d \n",arr[i]);
    }
}