# Graph Algorithms
This repository is practice implementing different graph algorithms on both a adjacency list-based graph implementation and an adjacency matrix implementation.

## Complexity Analysis
For all of the following analyses, V is the number of vertices/nodes and E is the number of edges in a graph.

### Depth-First Traversal (Search)
The time complexity of a DFS, curiously enough, depends on how the graph is implemented.
#### Adjacency Matrix-based Graphs
In a DFS, we will visit every node at least once, so the time complexity is atleast O(V). We will also traverse each edge at most once, so it is also at least O(E). The complexity is not just O(V+E) in an adjacency matrix-implemented graph, however, as we must iterate over a node's entire row in the adjacency matrix every time we visit it to find the edges. This requires O(V^2) steps, as there are V items in each row.  Clearly the number of edges is less than V^2, so its contribution is negligible. So, the final complexity of a DFS over an adjacency matrix is O(V^2).

#### Adjacency list-based Graphs
In a DFS, we will visit every node at least once, so the time complexity is atleast O(V). We will also traverse each edge exactly twice, so it is also at least O(2E). Since the edges are stored as lists, and we don't have to iterate over the vertices again, we find that the complexity is thus O(V+2E) or simply O(V+E). 

### Breadth-First Search
#### Adjacency Matrix-based Graphs
In a BFS, we will visit every node at least once, so the time complexity is atleast O(V). We will also traverse each edge at most once, so it is also at least O(E). The complexity is not just O(V+E) in an adjacency matrix-implemented graph, however, as we must iterate over a node's entire row in the adjacency matrix every time we visit it to find the edges. This requires O(V^2) steps, as there are V items in each row.  Clearly the number of edges is less than V^2, so its contribution is negligible. So, the final complexity of a DFS over an adjacency matrix is O(V^2).

#### Adjacency list-based Graphs
In a BFS, we will visit every node at least once, so the time complexity is atleast O(V). We will also traverse each edge exactly twice, so it is also at least O(2E). Since the edges are stored as lists, and we don't have to iterate over the vertices again, we find that the complexity is thus O(V+2E) or simply O(V+E). 

### Topological Sort
The implementation of a Topological Sort here is almost a DFS, and thus has the same complexity as a DFS for whichever implementation

### Prim's Algorithm
#### Adjacency Matrix-based Graphs
Our current implementation using an adjacency matrix checks each vertex then compares its distance to every other vertex. So the complexity is O(V^2).

#### Adjacency List-based Graphs

### Kruskal's Algorithm
#### Adjacency Matrix-based Graphs
Our current implementation is comically inefficient. It's in the order of O(V^3), since we don't bother sorting the edges first--or even make a list of edges for that matter! Each time we get choose the next edge (of which there are V), we go over the entire adjacency matrix ( O(V^2) ) to check every edge. Hence O(V^3). This could be made more efficient if we made and sorted a list of edges first. If a good sorting algorithm is used with O(n*logn), then theoretically, this could be as small as O(E*logE), and since E<=V^2, this is at most O(V^2*log(V^2))= O(V^2 * 2logV) = O(V^2 * logV).

#### Adjacency List-based Graphs
Using an adjacency list saves us the hastle of having to generate lists of edges to start with, so we can just join all our lists into one ( O(E) ) and then sort them O(E *logE). Thus, the overall complexity is simply O(E*logE)

### Dijkstra's Algorithm
#### Adjacency Matrix-based Graphs
Using an adjacency matrix, for each of the V steps, we compare V distances, since we have to go over the entire V^2 matrix. So the complexity is O(V^2).

#### Adjacency List-based Graphs
Using an adjacency list, a heap can be used to reduce the complexity to O(E * logV)

## Tree algorithms
n is the number of elements in the tree
### Regular Binary Tree
- Insert requires at worst O(n) steps, depending on where the element is inserted.
- Search, find_min, and find_max also likewise require at worst O(n) step.

### Binary Search Tree
-Insert requires at worst O(n) steps, if the new element is less than every element in the tree and the max element is the root. On average, it should take O(logn), as there are on average log(n) layers.
-Search requires at worst O(n) steps, if the searched element is the minimum element in the tree and the max element is the root. On average, it should take O(logn), as there are on average log(n) layers.
-find_min requires at worst O(n) steps, if the max element is the root. On average, it should take O(logn), as there are on average log(n) layers.
-find_max requires at worst O(n) steps, if the min element is the root. On average, it should take O(logn), as there are on average log(n) layers.
### AVL Tree
-Insert requires at worst O(logn) steps, as the balanced tree has log(n) layers
-Search requires at worst O(logn) steps, as the balanced tree has log(n) layers
-find_min requires at worst O(logn) steps, as the balanced tree has log(n) layers
-find_max requires at worst O(logn) steps, as the balanced tree has log(n) layers
### Min-heap
-Insert requires at worst O(logn) steps, as the balanced tree has log(n) layers and we will need to swap at most once per layer.
-Search requires at worst O(n) steps, as we may have to traverse every element.
-find_min requires at worst O(1) steps, as the heap property requires the minimum to be on top.
-find_max requires at worst O(n) steps, as we may have to traverse every element.
