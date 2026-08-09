#include<stdio.h>
#include "sort.h"
#include "utils.h"
/* Selection Sort
 * We will select the range of the unsorted array using the outerloop(says i) that indicates the starting index of the range. The loop will run forward from 0 to n - 1. The value i = 0 mean the loop is from 0 to n - 1.
 * Now in each iteration, we will select the minimum element from the range of the unsorted array using an inner loop.
 * After that we will swap the minimum element with the first element of the selected range(in step 1)
 * Finally, after each iteration, we will find the array is sorted up to the first index of the range.
 */

void selectionSort(int arr[], int len) {
    // Loop for selecting the range
    for (int i = 0; i < len; i++) {
        // For each iteration find the min and swap it with the first element of the range
        int min_ele = i;
        for (int j = i + 1; j < len; j++) {
           if(arr[j] < arr[min_ele])
               min_ele = j;
        }
        // Swap with the first element
        swap(arr, i, min_ele); 
    }
}
