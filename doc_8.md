# Sorting Algorithm Performance Comparison in C


## (a) Data Structures Definition

The program focuses on dynamic memory and primitive types to manage large datasets:

* **Dynamic Array (`int *arr`):** Since the size $N$ is determined by the user at runtime, the program uses `malloc()` to allocate a contiguous block of memory on the heap. This allows for testing significantly larger datasets than a standard fixed-length array.
* **Performance Counters (`long long comparisons`, `swaps`):** These are defined as `long long` to prevent overflow errors. For large $N$, $O(n^2)$ algorithms can quickly exceed the capacity of a standard 32-bit integer.
* **Randomized Data:** The array is populated using `rand() % 1000`, creating a "shuffled" state that provides a fair test for the average-case performance of each algorithm.

---

## (b) Function Descriptions

The program implements a variety of sorting logic, ranging from simple swaps to divide-and-conquer recursion.

| Function | Algorithm Type | Logic Summary |
| :--- | :--- | :--- |
| `bubbleSort()` | Exchange Sort | Repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order ($O(n^2)$). |
| `selectionSort()` | Selection Sort | Maintains a sorted and unsorted boundary. It finds the minimum element from the unsorted part and puts it at the beginning ($O(n^2)$). |
| `insertionSort()` | Insertion Sort | Builds the final sorted array one item at a time by "inserting" the current element into its correct position within the sorted prefix ($O(n^2)$). |
| `mergeSort()` | Divide & Conquer | Recursively splits the array into halves until they contain one element, then merges them back together in sorted order ($O(n \log n)$). |
| `merge()` | Utility | The "Conquer" step of Merge Sort. It uses temporary arrays to combine two sorted sub-arrays into a single sorted unit. |
| `printArray()` | Utility | Displays the array. For readability, it caps the output at 50 elements to prevent the console from being flooded. |




---

## (c) Organization of `main()`

The `main()` function is designed as a user-driven benchmark tool:

1.  **Input & Allocation:** It prompts the user for the number of elements ($N$) and allocates memory accordingly.
2.  **Seeding:** It populates the array with random integers to ensure the sorting isn't "pre-biased."
3.  **Algorithm Selection:** A `switch` statement handles the user's choice, calling the specific sorting function.
4.  **Performance Analysis:** After sorting, it calculates and displays the total number of **comparisons** (how many times elements were checked) and **swaps/movements** (how many times memory was written).
5.  **Memory Cleanup:** It uses `free(arr)` to release the allocated memory, ensuring no memory leaks occur.

---

## (d) Sample Output

 For $N=10$ using **Selection Sort**, output would look like:

```text
Enter the number of elements (N): 10

Choose a sorting algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Choice: 2

--- Array Before Sorting ---
383 886 777 915 793 335 386 492 649 421 

 Array After Sorting
335 383 386 421 492 649 777 793 886 915 

Algorithm Performance 
Total Comparisons: 45
Total Swaps: 9