#include <stdio.h>

struct Box {
    int arr[100];
    int length;
};

int sorted(struct Box *box) {//flags 1 if sorted, 0 if not
int i;
    for (i = 0; i < box->length - 1; i++) {
        if (box->arr[i] > box->arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

struct Box *IS(struct Box *UL, int *comp, int *swap) {
    int i, key, j;
    for (i = 1; i < UL->length; i++) {//takes O(n) time to traverse through the whole array
        key = UL->arr[i];
        j = i - 1;

        while (j >= 0) {
            (*comp)++; // comparisons with elements before the key, that are bigger than it on loop. Worst case when the smallest element is at the end, giving us O(n) for sorting only that element back into the sorted list.

            if (UL->arr[j] > key) {
                UL->arr[j + 1] = UL->arr[j];
                (*swap)++; // moving the bigger elements ahead of our key
                j = j - 1;
            } else {
                break; // No need to continue comparing if key is in its correct position.
            }
        }

        UL->arr[j + 1] = key;
        // inserting our key into the right position in the list
    }

    return UL;
}

void Ins(struct Box *UL) {
    int comp = 0; 
    int swap = 0; 

    IS(UL, &comp, &swap);

    for (int i = 0; i < UL->length; i++) {
        printf("Element %d: %d\n", i, UL->arr[i]);
    }

    printf("Comparisons: %d\n", comp);
    printf("Swaps: %d\n", swap);
}

void swap(int *xp, int *yp)
{
int temp;
temp = *xp; *xp = *yp; *yp = temp;
}
void printArray(int arr[], int size)
{
int i;
for (i = 0; i < size; i++)
printf("%d ", arr[i]);
printf("\n");
}


void bubbleSort(int arr[], int n)
{
int i, j, flag, comparisonCnt = 0, swapCnt = 0;
for (i = 0; i < n - 1; i++) {
flag = 0;
for (j = 0; j < n - i - 1; j++) {
comparisonCnt++;
if (arr[j] > arr[j + 1]) {
swap(&arr[j], &arr[j + 1]);
flag = 1;
swapCnt++;
}
}
if (flag == 0) break;
}
printf("comp %d, swap %d\n", comparisonCnt, swapCnt);
}

int main() {

//General case: We see that no matter the input, the space complexity of the sorting algorythm stays constant or O(1) as it does all its functions within a given space itself and takes nothing extra. 


 //best case: Our best case occurs when a list is already sorted 
    printf("With an already sorted array we see:\n");
    
    struct Box mysBox;
    mysBox.length = 5;
    mysBox.arr[0] = 1;
    mysBox.arr[1] = 2;
    mysBox.arr[2] = 3;
    mysBox.arr[3] = 4;
    mysBox.arr[4] = 5;
    
       printf("Original Array:\n");
    for (int i = 0; i < mysBox.length; i++) {
        printf("Element %d: %d\n", i, mysBox.arr[i]);
    }

    printf("Array length: %d\n", mysBox.length);

    printf("sorted: %d\n\n", sorted(&mysBox));

    printf("On calling Insertion Sort:\n");
    Ins(&mysBox);
    
     printf("Array length: %d\n", mysBox.length);
     printf("sorted: %d\n\n\n", sorted(&mysBox));
     
     
     //  We see from the output that in our best case we have 0 swaps, or constant O(1) time and 4 comparisons for the 5 element array giving us O(n-1) or O(n) time complexity for the comparisons. We can note that the comparisons in this case are 1 per shift in 'i', in the code, which is to say that as we traverse through the code we do a constant comparison of 1 in the best case as our "if (UL->arr[j] > key)" condition on line 27 never gets activated. That means that our O(n) complexity is simply derived from our step of traversing through the array and nothing more.
     
     //worst case, a list in decending order
      struct Box mywBox;
    mywBox.length = 5;
    mywBox.arr[0] = 5;
    mywBox.arr[1] = 4;
    mywBox.arr[2] = 3;
    mywBox.arr[3] = 2;
    mywBox.arr[4] = 1;
    
        printf("Original Array:\n");
    for (int i = 0; i < mywBox.length; i++) {
        printf("Element %d: %d\n", i, mywBox.arr[i]);
    }

    printf("Array length: %d\n", mywBox.length);

    printf("sorted: %d\n\n", sorted(&mywBox));

    printf("On calling Insertion Sort:\n");
    Ins(&mywBox);
    
     printf("Array length: %d\n", mywBox.length);
     printf("sorted: %d\n\n\n", sorted(&mywBox));
    
    //Analysing step by step we can see that the insertion sort algorithm makes sorted sublists at the start of a list which it then inserts 1 extra element into. We see that the sorted lists go from size 1,2..n. and at each step we can have a max of 0,1..n-1 comparisons and swaps respectively. So when counting the total number of comparisons and swaps in our worst case we find 0+1+2+3..(n-2)+(n-1) which we know can be represented as n(n-1)/2. Thus we have (n^2-n)/2 comparisons and swaps in our worst case which can be represented as O(n^2) by notation. 
    
    //in this case we can take n=5 and see that n(n-1)/2=5*4/2=20/2=10 which is the number of comparisons and swaps in our worst case.
    //the worst case of comparisons and swaps will never exceed n(n-1)/2 which is of the order O(n^2).
    
    //The average case thus falls between our best case of O(n) and our worst case of O(n^2). More specifically the comparisons fall between n and n(n-1)/2 while the swaps do the same while always staying equal to or below the number of comparisons as a swap can only be made afetr a comparison. We can understand this by taking a list which is partially sorted as some elements will travel to their place in the already sorted list without having to bubble all the way to the start. That is, at every insertion of a element, there will not be n-1 comparisons and swaps, thus we dont have our max of 0,1..n-1 comparisons and swaps as the sublists go from size 1 to n. We might have to do the full list for certain elements but it still gives us a value between n and n(n-1)/2. Giving us an average case of the order of O(n^2). 
    
    //some average cases are printed below after which we compare to bubble sort.
struct Box myBox;
    myBox.length = 5;
    myBox.arr[0] = 7;
    myBox.arr[1] = 6;
    myBox.arr[2] = 9;
    myBox.arr[3] = 2;
    myBox.arr[4] = 0;

    printf("Original Array:\n");
    for (int i = 0; i < myBox.length; i++) {
        printf("Element %d: %d\n", i, myBox.arr[i]);
    }

    printf("Array length: %d\n", myBox.length);

    printf("sorted: %d\n\n", sorted(&myBox));

    printf("On calling Insertion Sort:\n");
    Ins(&myBox);
    
     printf("Array length: %d\n", myBox.length);
     printf("sorted: %d\n\n\n", sorted(&myBox));
     
     struct Box my1Box;
    my1Box.length = 5;
    my1Box.arr[0] = 1;
    my1Box.arr[1] = 2;
    my1Box.arr[2] = 3;
    my1Box.arr[3] = 4;
    my1Box.arr[4] = 0;

    printf("Original Array:\n");
    for (int i = 0; i < my1Box.length; i++) {
        printf("Element %d: %d\n", i, my1Box.arr[i]);
    }

    printf("Array length: %d\n", my1Box.length);

    printf("sorted: %d\n\n", sorted(&my1Box));

    printf("On calling Insertion Sort:\n");
    Ins(&my1Box);
    
     printf("Array length: %d\n", my1Box.length);
     printf("sorted: %d\n\n\n\n\n", sorted(&my1Box));

//running bubble sort on the same data we see
 int n = 5;
int arr[] = {1, 2, 3, 4, 5};
printf("Initial array: \n");
printArray(arr, n);
bubbleSort(arr, n);
printf("Sorted array: \n");
printArray(arr, n);

int arr1[] = {5, 4, 3, 2, 1};
printf("Initial array: \n");
printArray(arr1, n);
bubbleSort(arr1, n);
printf("Sorted array: \n");
printArray(arr1, n);

//In our best and worst case we have the identical amount of comparisons and swaps as bubble sort also works with a best case of O(n) and a worst of O(n^2), more specifically of n and n(n-1)/2.

int arr2[] = {7, 6, 9, 2, 0};
printf("Initial array: \n");
printArray(arr2, n);
bubbleSort(arr2, n);
printf("Sorted array: \n");
printArray(arr2, n);

int arr3[] = {1, 2, 3, 4, 0};
printf("Initial array: \n");
printArray(arr3, n);
bubbleSort(arr3, n);
printf("Sorted array: \n");
printArray(arr3, n);

//In our average case we again see that bubble sort falls between n and n(n-1)/2 comprisons. However the number of comparisons in bubble sort is always higher if not equal. This is due to the fact that bubble sort allows two numbers to be compared multiple times in its worst case while insert sort only ever allows two numbers to be comared a maximum of once according to which they are shifted in the sorting list. Bubble sort in trying to make a list where it finds the niggest of a remaining list first runs the risk of comparing the same to elements to each other multiple times. This is most clear in my last trial where 1 is compared to 2 a total of 3 times in bubble sort by only once in insert. This is due to the nature of insert sort where during the process of insertion, every element can be compared to every other element a maximum of 1 times and then is never compared to the elements inside the sorted list again.

    return 0;
}
