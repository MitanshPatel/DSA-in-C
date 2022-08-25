//finding a small number from 2nd to last posn of array and swapping it to the first posn of array. 
//Then finding small from 3rd to last posn and swapping to 2nd posn of array
//swapping happens multiple times

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

    for(int i=0;i<n-1;i++){  //not to take last posn as it has no more elements ahead in array to compare. smaller number ahead will be swapped to i'th posn
        for(int j=i+1;j<n;j++){ //remaining elements that will be swapped to i'th posn
            if(arr[j]<arr[i]){  //for descending change < to >
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        } 
    }

    //print
    printf("Below are all elements sorted in ascending order\n");
    for(int i=0;i<n;i++){
        printf("%d \n",arr[i]);
    }
}