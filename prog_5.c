#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define maxV 5 //maxV vertices

// graph structure

int adjMatrix[maxV][maxV];
bool visited[maxV];

// queuefor BFS
int queue[maxV];
int front = -1, rear = -1;

void enqueue(int vertex) {
    if (rear == maxV - 1) return; // queue full
    if (front == -1) front = 0;
    queue[++rear] = vertex;
}

int dequeue() {
    if (front == -1 || front > rear) return -1; // queue empty
    return queue[front++];
}

bool isQueueEmpty() {
    return (front == -1 || front > rear);
}

// Initialize matrix to 0
void initGraph() {
    for (int i = 0; i < maxV; i++) {
        for (int j = 0; j < maxV; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

// fresh traversal
void resetVisited() {
    for (int i = 0; i < maxV; i++) {
        visited[i] = false;
    }
}

//undirected edge
void addEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

//Traverse Algos

//bfs
void BFS(int startVertex) {
    resetVisited();
    
    // enqueueing the first node
    enqueue(startVertex);
    visited[startVertex] = true;
    
    printf("BFS Traversal: ");
    
    while (!isQueueEmpty()) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);
        
        
        for (int i = 0; i < maxV; i++) {
            
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = true;
            }
        }
    }
    printf("\n");
}

// dfs(recursion help)
void DFS_Recursive(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = true;
    
    for (int i = 0; i < maxV; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS_Recursive(i);
        }
    }
}

// dfs(wrap)
void DFS(int startVertex) {
    resetVisited();
    printf("DFS Traversal: ");
    DFS_Recursive(startVertex);
    printf("\n");
}

// visualize
void printAdjMatrix() {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < maxV; i++) {
        for (int j = 0; j < maxV; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main() {
    initGraph();

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 4);

    printAdjMatrix();

    // traverse starts from vertex 0
    BFS(0);
    DFS(0);

    return 0;
}