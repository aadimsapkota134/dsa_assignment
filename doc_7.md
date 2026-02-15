# Dijkstra's Shortest Path Algorithm in C

## (a) Data Structures Definition

The program relies on standard arrays and constants to represent the graph's mathematical properties:

* **Adjacency Matrix (`int graph[V][V]`):** A 2D array where `graph[i][j]` represents the weight of the edge between vertex $i$ and $j$. A value of $0$ indicates no direct edge exists.
* **Distance Array (`int dist[V]`):** This array holds the shortest distance from the source to each vertex $i$. Initially, these are set to infinity ($\infty$).
* **Visited Array (`bool visited[V]`):** A boolean tracker to ensure each vertex is processed exactly once.
* **Infinity (`INT_MAX`):** A constant from `<limits.h>` used to represent a distance that is currently unknown or unreachable ($d = \infty$).



---

## (b) Function Descriptions

The logic is divided into finding the next node, relaxing edges, and displaying the results.

| Function | Purpose |
| :--- | :--- |
| `find_min_distance()` | A greedy helper function that searches the `dist[]` array for the vertex with the minimum value that has not yet been visited. |
| `print_solution()` | Iterates through the final `dist[]` array and prints the shortest path values in a formatted table. |
| `dijkstra()` | The core algorithm. It initializes distances, marks the source as 0, and repeatedly "relaxes" the edges of the closest unvisited vertex. |

### The Logic of Relaxation
For every neighbor $v$ of the current vertex $u$, the algorithm checks:
$$\text{if } dist[u] + weight(u, v) < dist[v]$$
If this is true, it updates $dist[v]$ with the new, shorter path.



---

## (c) Organization of `main()`

The `main()` function serves as the entry point and data provider:

1.  **Graph Definition:** It defines a $9 \times 9$ adjacency matrix representing a weighted undirected graph.
2.  **Algorithm Trigger:** It calls the `dijkstra()` function, passing the graph and the starting source vertex (Vertex `0`).
3.  **Result Delivery:** Once the algorithm completes its iterations, the results are automatically printed to the console via the helper function.

---

## (d) Sample Output

running the program with the provided $9 \times 9$ matrix, the output shows the minimum cost to reach every vertex from Vertex 0:

```text
Vertex   Distance from Source
0        0
1        4
2        12
3        19
4        21
5        11
6        9
7        8
8        14