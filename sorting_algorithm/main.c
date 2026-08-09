#include<stdio.h>
#include "sort.h"
#define ARR_LEN 32

int main() {
    int arr[ARR_LEN];
    int len = 0, val;

    while(scanf("%d", &val) == 1) {
        arr[len] = val;
        len++;
    }

    insertionSort(arr, len);

    printf("\nSorted arr is ");
    for(int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
