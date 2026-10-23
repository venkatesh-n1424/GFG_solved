# 📝 Count Pairs Violating BST Property (GeeksforGeeks)

🔗 [Problem Link](https://www.geeksforgeeks.org/problems/pairs-violating-bst-property--212515/1)

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange) ![Language](https://img.shields.io/badge/Language-C++-blue)

### 💡 Tags
Binary Search Tree, Merge Sort, Traversal

### 🚀 Performance
- **Runtime:** Successfully Evaluated
- **Memory:** N/A

---

### 📜 Problem Description

Given a binary tree, count pairs of nodes that violate any of the following Binary Search Tree (BST) properties.

****

- All values in the left subtree are strictly smaller.
- All values in the right subtree are strictly greater.

**Examples:**

```
Input: root[] = [10, 50, 40, N, N, 20, 30]

Output: 5
Explanation: Pairs violating BST property are:-
(10,50), 10 should be greater than its left child value.
(40,30), 40 should be less than its right child value.
(50,20), (50,30) and (50,40), maximum of left subtree of 10 is 50 greater than 20, 30 and 40 of its right subtree.
```

```
Input: root[] = [80, 40, 30, 70, N, 60, 70]

Output: 9
Explanation: There are total 9 pairs (80,30),(80,60),(80,70),(30,60),(40,70),(40,30),(70,30),(70,60),(70,70) which violate the BST properties.
```