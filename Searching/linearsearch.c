//normal way

#include<stdio.h>


//using function
int LinearSearch(int arr[],int n, int key){  //use int instead of void or else not finding the element part wont be executed

    for(int i=0;i<n; i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1; //key not found
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
    int b=LinearSearch(arr,n,key);
    if (b==-1){
        printf("Element not found\n");
    }
    else printf("Element at position %d\n",b+1);

}