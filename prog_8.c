#include <stdio.h>
#include <stdlib.h>

//counters for analysis of algos
long long comparisons = 0;
long long swaps = 0;

// func haru ko protos
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void printArray(int arr[], int n);

int main() {
    int n, choice;

    printf("Enter the number of elements (N): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    // dynamic memory allocation for N elements
    int *arr = (int *)malloc(n * sizeof(int));
    
    //seeding for elements
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 1000) + 1;
    }

    printf("\nChoose a sorting algorithm:\n");
    printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n");
    printf("Choice: ");
    scanf("%d", &choice);

    printf("\n--- Array Before Sorting ---\n");
    printArray(arr, n);

    comparisons = 0;
    swaps = 0;

    switch (choice) {
        case 1: bubbleSort(arr, n); break;
        case 2: selectionSort(arr, n); break;
        case 3: insertionSort(arr, n); break;
        case 4: mergeSort(arr, 0, n - 1); break;
        default: 
            printf("Invalid choice!\n"); 
            free(arr); 
            return 1;
    }

    printf("\n Array After Sorting\n");
    printArray(arr, n);

    printf("\nAlgorithm Performance \n");
    printf("Total Comparisons: %lld\n", comparisons);
    
    // merge sort moves elements to temp arrays, so "swaps" aren't used
    if (choice == 4) {
        printf("Total Movements (Assignments): %lld\n", swaps);
    } else {
        printf("Total Swaps: %lld\n", swaps);
    }

    free(arr);
    return 0;
}

// to print array ( 50 elements for readability)
void printArray(int arr[], int n) {
    int limit = (n > 50) ? 50 : n;
    for (int i = 0; i < limit; i++) {
        printf("%d ", arr[i]);
    }
    if (n > 50) printf("... [truncated]");
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            swaps++;
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
                swaps++;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}


void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
        swaps++; 
    }
    while (i < n1) { arr[k++] = L[i++]; swaps++; }
    while (j < n2) { arr[k++] = R[j++]; swaps++; }

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}