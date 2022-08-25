// sorted section on the left part and unsorted section on the right part of the array 
// 1st number from unsorted section will be picked and swapped exactly to the correct position in sorted section of array
// other nums in sorted array will be shifted by a position towards the right.

#include<stdio.h>

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

    for(int i=1;i<n;i++){ //i starts with 1 as 0th posn is assumend as sorted section of array
        int current = arr[i];  //first element of the unsorted section of array.
        int j=i-1;
        while(arr[j]>current && j>=0){  //loop to shift elements to one position towards right 
            arr[j+1]=arr[j];
            j--;  //j will stop decrementing when the element of unsorted section finds its correct position in sorted section of array
        }
        arr[j+1]=current; //when arr[j] value gets put in arr[j+1] {means arr[j]=arr[j+1]}, 
                          //j-- is done and j is decreased by 1,   {means arr[j+1]=arr[j+2]}. 
                          //thus arr[i]/current is put in arr[j+1] which is correct position for current in sorted section
    }

    //print
    printf("Below are all elements sorted in ascending order\n");
    for(int i=0;i<n;i++){
        printf("%d \n",arr[i]);
    }
}