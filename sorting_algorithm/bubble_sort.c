#include<stdio.h>
#include "sort.h"
#include "utils.h"

void bubbleSort(int arr[], int len) {
    // Select the range of unsorted array
    for(int i = len - 1; i > 0; i--) {
        int cnt = 0; // Calculate the number of swaps in range
        // Push the marximum element to last
        for(int j = 0; j < i; j++) {
            if(arr[j] > arr[j + 1])  {
                cnt++;
                swap(arr, j, j + 1);
            }
        }
        if(cnt == 0) {
            break;
        }
    }
}
