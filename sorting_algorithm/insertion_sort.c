#include<stdio.h>
#include "sort.h"

void insertionSort(int arr[], int len) {
    // Unsorted array range
    for(int i = 1; i < len; i++) {
        // Select ele from unsorted range put in the correct position in sorted array
        int ele = arr[i];
        int pos = 0;
        for(; pos < i; pos++) {
            if(ele < arr[pos]) break;
        }
        // Shift the element to make the place for ele
        for(int j = i; j > pos; j--) {
            arr[j] = arr[j - 1];
        }
        arr[pos] = ele;
    } 
}
