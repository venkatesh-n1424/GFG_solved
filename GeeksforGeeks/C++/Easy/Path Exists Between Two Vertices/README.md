# 📝 Path Exists Between Two Vertices (GeeksforGeeks)

🔗 [Problem Link](https://www.geeksforgeeks.org/problems/path-exists/1)

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen) ![Language](https://img.shields.io/badge/Language-C++-blue)

### 💡 Tags
BFS, Graph, DFS

### 🚀 Performance
- **Runtime:** Successfully Evaluated
- **Memory:** N/A

---

### 📜 Problem Description

Given an undirected graph with  **V**  vertices numbered from 0 to V - 1, represented by an adjacency list  **adj[][]** , where adj[i] contains all vertices adjacent to vertex **i** . Also given two vertices  **u** and  **v** , check whether a path exists between them.

Return true if a path exists, otherwise return false.

**Examples:**

```
Input: adj[][] = [[2, 3], [2], [0, 1], [0], [5], [4]], u = 1, v = 5

Output: false
Explanation: There is no path from vertex 1 to vertex 5.
```

```
Input: adj[][] = [[2, 3], [2], [0, 1], [0], [5], [4]], u = 2, v = 3

Output: true
Explanation: We can reach vertex 3 from vertex 2 via vertex 0.

```