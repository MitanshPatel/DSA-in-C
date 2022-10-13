#include<stdio.h>
#include<stdlib.h>

int size =0;

void swap(int *a, int *b){
    int temp=*b;
    *b=*a;
    *a=temp;
}

void heapify(int array[], int size, int i){
    if(size==1){
        printf("Single element in heap");
    }
    else{
        int largest=i;
        int l=2*i+1;  //this array position contains left child of i th array posn
        int r=2*i+2;  //this array position contains right child of i th array posn

        if(l<size && array[l]>array[largest]){  //if left child of parent root is bigger than parent root
            largest=l;
        }
        if(r<size && array[r]>array[largest]){  //if right child of parent root is bigger than parent root
            largest=r;
        }

        if(largest!=i){  // heap feature not satisfied. child is bigger than parent
            swap(&array[i], &array[largest]);  //swapping child with parent, such that parent becomes bigger and child becomes lower
            heapify(array,size,largest); 
        }
    }
}

void heapSort(int arr[],int n){
    //first build max heap
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }

    //Heap sort
    for(int i=n-1;i>=0;i--){
        swap(&arr[0], &arr[i]);
        heapify(arr,i,0); // Heapify root element to get highest element at root again
    }
}

void printArray(int array[],int size){
    for (int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
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
  
    heapSort(arr, n);
  
    printf("Sorted array is \n");
    printArray(arr, n);
  }