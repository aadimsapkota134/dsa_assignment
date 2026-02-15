//Given the array of the data (unsorted), Write a program to build the min and max heap.
#include <stdio.h>
#include<stdlib.h>

// swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

//max Heap

//  max heapify function
void heapifyMax(int arr[], int n, int i) {
    int largest = i;            // largest as root
    int left = 2 * i + 1;       // left child 
    int right = 2 * i + 2;      // right child 

    // left child larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // right child  larger than largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // heapify the sub-tree recursion use garera
        heapifyMax(arr, n, largest);
    }
}

// build a max Heap: unsorted array bata
void buildMaxHeap(int arr[], int n) {
    // last non leaf node
    int startIdx = (n / 2) - 1;

    // reverse level order traversing from last non leaf node
    //heapify each node
    for (int i = startIdx; i >= 0; i--) {
        heapifyMax(arr, n, i);
    }
}


// min Heapify function
void heapifyMin(int arr[], int n, int i) {
    int smallest = i;           // smallest as root
    int left = 2 * i + 1;       // left child 
    int right = 2 * i + 2;      // right child 

    // If left child < root
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // If right child < root
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // smallest != root
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);

        // heapify the sub tree recursively feri
        heapifyMin(arr, n, smallest);
    }
}

//  Min heap from unsorted array
void buildMinHeap(int arr[], int n) {
    int startIdx = (n / 2) - 1;

    for (int i = startIdx; i >= 0; i--) {
        heapifyMin(arr, n, i);
    }
}


int main() {
    int data[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(data) / sizeof(data[0]);

    int *maxHeapArr = (int*)malloc(n * sizeof(int));
    int *minHeapArr = (int*)malloc(n * sizeof(int));

    // checking memory allocation failed or not
    if (maxHeapArr == NULL || minHeapArr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for(int i = 0; i < n; i++) {
        maxHeapArr[i] = data[i];
        minHeapArr[i] = data[i];
    }

    printf("Original Array: \n");
    printArray(data, n);

    printf("\n Building Max Heap: \n");
    buildMaxHeap(maxHeapArr, n);
    printArray(maxHeapArr, n);

    printf("\n Building Min Heap:\n");
    buildMinHeap(minHeapArr, n);
    printArray(minHeapArr, n);

    free(maxHeapArr);
    free(minHeapArr);

    return 0;
}