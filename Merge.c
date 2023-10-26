// C program for Merge Sort 
#include <stdio.h> 
#include <stdlib.h> 

#define ARRSIZE 8;
int cp1, cmp1;
  

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  //finding out where to split the array
   
    int L[n1], R[n2]; 
  //the function creates 2 new arrays therefore taking 2(n/2)space where n is the length of the array on the current level.
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i]; 
	cp1++;
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
	cp1++;
    } 
  
  
    i = 0; 
  
    j = 0; 
  
    k = l; 
    while (i < n1 && j < n2) { 
	cmp1++;
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
 
    while (i < n1){ 
        arr[k] = L[i]; 
        i++; 
        k++; 
        cp1++;
    } 
  
  
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
        cp1++;
    } 
} 
  

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
       //checks if arr is not a single element.
       //if its not it splits it
        int m = l + (r - l) / 2; 
  
        mergeSort(arr, l, m); //first half
        mergeSort(arr, m + 1, r); //second half
  
  //algorithm recursively divides arrays into two, first going down the left subtree of an array and then going down the right of each array(in the order you would search for least elements in a BST). It only stops when it reaches single leaf nodes as these nodes by virtue of having only one element are considered to be sorted.
  
  //at each step dividing down and sorting back up, merge sort creates new arrays to store its data. For example in the first step when it divides its n aray into 2 it fetches 2(n/2) space of memory to do so. Thus as it keeps moving down it keeps using 2*level-1(n/2*level-1)space. 
  
  //it moves down log(n) base 2 levels as we keep dividing by 2 and nlog(n) base 2 space as it creates 2n space to split and reassemble its arrays.
  
  //Moreover merging two arrays from any of its levels takes O(n) time as every comparison leads to one less element from our consideration.
  
  
        merge(arr, l, m, r); 
    } 
} 
  

void printArray(int A[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  

int main() 
{ 
    int arr[] = {1, 7, 10, 13, 2, 8, 11, 20}; 
    int arr_size = ARRSIZE; 

    cp1 = 0; cmp1 = 0;
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 

    printf("Copy count %d, Comparison Count %d\n", cp1, cmp1);
    return 0; 
}
//We find that merge sort has similar worst case space and time complexity as heap sort with both of them taking nlogn time, (derived from log n level of the trees each doing functions that fluctuate with n for merge sort).


