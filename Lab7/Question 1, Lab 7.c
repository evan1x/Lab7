#include <stdio.h>
#define SIZE 6

// Function prototypes
void bubbleSort(int a[]);
int binarySearch(const int b[], int searchKey, int low, int high);
void printArray(const in a[]);

// Main driver
int main(void) {
    int array[SIZE] = {10, 8, 5, 6, 3, 1};
    int res;
    
    printf("Array before sorting: \n");
    printArray(array);
    
    bubbleSort(array);
    
    printf("\nArray after soring: \n");
    printArray(array);
    
    // Test case 1
    res = binarySearch(array, 8, 0, SIZE - 1);
    if (res == -1)
        printf("\n8 is not found\n");
    else
        printf("\n8 exists in position %d\n", res);
        
    // Test case 2
    res = binarySearch(array, 13, 0, SIZE - 1);
    if (res == -1)
        printf("13 is not found\n");
    else
        printf("13 exists in position%d\n", res);
        
    return 0;
}

// Function: sorts an array using bubbleSort
void bubbleSort(int a[]) {
    int pass, j, hold;
    
    for(pass = 1; pass < SIZE; pass++) {
        for(j = 0; j < SIZE - 1; j++) {
            if (a[j] > a[j + 1]) {
                hold = a[j];
                a[j] = a[j + 1];
                a[j + 1] = hold;
            }
        }
    }
}

// Function: perform binarySearch
int binarySearch(const int b[], int searchKey, int low, int high) {
    int middle;
    
    while(low <= high) {
        middle = (low + high) / 2;
        
        if(searchKey == b[middle])
            return middle;
        else if (searchKey < b[middle])
            high = middle - 1;
        else
            low = middle + 1;
    }
    
    return -1;
}

// Helper to print the array
void printArray(const int a[]) {
    
    for(int i =0; i < SIZE; i++) 
        printf("%d", a[i]);
    printf("\n");
    
}