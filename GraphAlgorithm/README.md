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
