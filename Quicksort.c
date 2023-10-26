#include <stdio.h>
#define ARRSIZE 12
int swpcnt, cmpcnt;
// Function to swap two elements
void swap(int* a, int* b) {
int t = *a;
*a = *b;
*b = t;
swpcnt++;
}

int partition(int arr[], int low, int high) {
int pivot = arr[high];
int i = (low - 1);
for (int j = low; j <= high - 1; j++) {
cmpcnt++;
if (arr[j] < pivot) {
i++;
swap(&arr[i], &arr[j]);
}
}
swap(&arr[i + 1], &arr[high]);
return (i + 1);
}
//like merge sort quick sort is also a partitioning algorithm that recursively calls itself on its partitions. When we compare worst case complexities we see that merge sort does not have a descernable worst case, fluctuating with O(nlogn) while quick sorts is listed below.

//worst case complexity of quick sort is found when we keep choosing partitions at a maximal or minimal element, this way we do not get subtrees but rather only one subtree which is all elements exept the pivot. This way we have to go through n elements in our first sort n-1 in our second until 1, giving us (n)+(n-1)..+1=n(n+1)/2 which has a g(n) of O(n^2).

//best case time complexity of quicksort however is quiet interesting when compared to merge sort as one structure mirrors the other. We find the best case of quick sort when we choose the median element of the elements given as this partitions the tree into two equal subhalfs. Doing it this way, it is easy to see that when we get two equal subhalves in every step that we have a depth of log(n) and that total space taken at every level is totally equal to N thus giving us best case time complexity of O(nlogn).

//Average complexity increases when we take cases such as finding pivots that are the median of medians as they make better points to partition an array.

void quickSort(int arr[], int low, int high) {
if (low < high) {
int pi = partition(arr, low, high);
quickSort(arr, low, pi - 1);
quickSort(arr, pi + 1, high);
//dividing an array from below and above a partition point and working the algorithm on those sub algorithms.
}
}

// Function to print the array
void printArray(int arr[], int size) {
int i;
for (i = 0; i < size; i++)
printf("%d ", arr[i]);
printf("\n");
}

int main(){
int arr[] = {8, 19, 9, 11, 12, 11, 13, 5, 6, 7, 3, 17};
int n = ARRSIZE;
swpcnt = 0; cmpcnt = 0;
printf("Unsorted array: \n");
printArray(arr, n);
quickSort(arr, 0, n - 1);
printf("Sorted array: \n");
printArray(arr, n);
printf("Swap %d Comparison %d\n\n", swpcnt, cmpcnt);

int arr1[] = {82, 1, 70, 11, 62, 11, 89, 5, 6, 8, 6, 7};
int g = ARRSIZE;
swpcnt = 0; cmpcnt = 0;
printf("Unsorted array: \n");
printArray(arr1, g);
quickSort(arr1, 0, g - 1);
printf("Sorted array: \n");
printArray(arr1, g);
printf("Swap %d Comparison %d\n\n", swpcnt, cmpcnt);

int arr2[] = {86, 16, 0, 1, 52, 91, 39, 25, 36, 80, 6, 17};
int t = ARRSIZE;
swpcnt = 0; cmpcnt = 0;
printf("Unsorted array: \n");
printArray(arr2, t);
quickSort(arr2, 0, t - 1);
printf("Sorted array: \n");
printArray(arr2, t);
printf("Swap %d Comparison %d\n\n", swpcnt, cmpcnt);

int arr3[] = {8, 162, 0, 10, 52, 1, 309, 251, 6, 80, 36, 7};
int r = ARRSIZE;
swpcnt = 0; cmpcnt = 0;
printf("Unsorted array: \n");
printArray(arr3, r);
quickSort(arr3, 0, r - 1);
printf("Sorted array: \n");
printArray(arr3, r);
printf("Swap %d Comparison %d\n\n", swpcnt, cmpcnt);

//seeing that all arrays are of size 12 we can see that comparisons stay above twice n and swaps usually stay between n and 2n. Thus we can conclude from these numbers that it does better than heapinsert+heapdelete in terms of both metrics and about as well as heapify+heapdelete.

//It does worse than merge sort trivially as it forms a merge sort like structure only in its best case.

return 0;
}