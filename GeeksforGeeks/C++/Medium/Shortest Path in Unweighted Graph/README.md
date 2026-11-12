# 📝 Shortest Path in Unweighted Graph (GeeksforGeeks)

🔗 [Problem Link](https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1)

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange) ![Language](https://img.shields.io/badge/Language-C++-blue)

### 💡 Tags
Graph, BFS

### 🚀 Performance
- **Runtime:** Successfully Evaluated
- **Memory:** N/A

---

### 📜 Problem Description

Given an undirected graph with  **V**  vertices numbered from 0 to V-1 represented by an adjacency list  **adj[][]** , where adj[i] contains all vertices adjacent to vertex i, given two vertices  **src**  and  **dest** , find the length of the shortest path from src to dest. If there is no path between src and dest, return -1.

**Note:** All edges have a unit weight of 1.

**Examples :**

```
Input: adj[][] = [[1, 3], [0, 2], [1, 6], [0, 4], [3, 5], [4, 6], [2, 5, 7, 8], [6, 8], [6, 7]], src = 0, dest = 8
Output: 4
Explanation: One of the shortest paths from vertex 0 to vertex 8 is 0 -> 1 -> 2 -> 6 -> 8, which contains 4 edges.

```

```
Input: adj[][]= [[3], [3], [], [0, 1]], src = 3, dest = 2
Output: -1
Explanation: There is no path between vertices 3 and 2.

```