# Graph Traversal Implementation in C


## (a) Data Structures Definition

The program uses global variables and basic arrays to manage the graph's state:

* **Adjacency Matrix (`int adjMatrix[maxV][maxV]`):** A 2D array where `maxV` is 5. It stores the edges of the graph. If `adjMatrix[i][j]` is 1, a connection exists between vertex $i$ and vertex $j$.
* **Visited Array (`bool visited[maxV]`):** A boolean array used during traversals to keep track of which vertices have already been processed, preventing infinite loops.
* **Queue for BFS (`int queue[maxV]`, `front`, `rear`):** A simple array-based linear queue used to manage the order of nodes for Breadth-First Search.



---

## (b) Description of Functions

The implementation is broken down into helper functions and core algorithm functions:

### Utility Functions
* **`initGraph()`**: Loops through the adjacency matrix and sets all elements to 0 to ensure a clean start.
* **`resetVisited()`**: Sets all elements in the `visited` array to `false` before starting a new traversal.
* **`addEdge(int u, int v)`**: Sets `adjMatrix[u][v]` and `adjMatrix[v][u]` to 1, creating an undirected connection between two nodes.
* **`printAdjMatrix()`**: Iterates through the 2D array and prints it in a grid format for visualization.

### Queue Operations (for BFS)
* **`enqueue(int vertex)`**: Adds a vertex to the end of the queue.
* **`dequeue()`**: Removes and returns the vertex from the front of the queue.
* **`isQueueEmpty()`**: Returns true if there are no more elements to process in the queue.

### Traversal Algorithms
* **`BFS(int startVertex)`**: Uses a queue-based approach to visit nodes level by level. It starts at the source, marks it as visited, and explores all its neighbors before moving to the next level.
* **`DFS(int startVertex)`**: A wrapper function that resets the visited array and initiates the recursive depth-first exploration.
* **`DFS_Recursive(int vertex)`**: The core DFS logic. It visits a node and immediately dives into the first unvisited neighbor it finds, using the call stack for backtracking.



---

## (c) Overview of `main()`

The `main()` function follows a structured sequence to demonstrate the graph's capabilities:

1.  **Graph Setup**: It calls `initGraph()` to initialize the matrix.
2.  **Edge Definition**: It uses `addEdge()` to build a specific graph structure (connecting 0-1, 0-2, 1-3, 1-4, and 2-4).
3.  **Visualization**: It prints the resulting Adjacency Matrix to the console.
4.  **Traversal Execution**: It performs a **BFS** starting from vertex 0, followed by a **DFS** starting from vertex 0, to show the difference in how the two algorithms explore the same graph.

---

## (d) Sample Output

When the program is compiled and executed, it produces the following output:

```text
Adjacency Matrix:
0 1 1 0 0 
1 0 0 1 1 
1 0 0 0 1 
0 1 0 0 0 
0 1 1 0 0 

BFS Traversal: 0 1 2 3 4 
DFS Traversal: 0 1 3 4 2