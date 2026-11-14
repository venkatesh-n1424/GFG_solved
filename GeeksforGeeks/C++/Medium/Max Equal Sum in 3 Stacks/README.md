# 📝 Max Equal Sum in 3 Stacks (GeeksforGeeks)

🔗 [Problem Link](https://www.geeksforgeeks.org/problems/find-maximum-equal-sum-of-three-stacks/1)

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange) ![Language](https://img.shields.io/badge/Language-C++-blue)

### 💡 Tags
Greedy, Stack

### 🚀 Performance
- **Runtime:** Successfully Evaluated
- **Memory:** N/A

---

### 📜 Problem Description

Given three stacks  **s1** ,  **s2** , and  **s3** , represented by arrays where the first element of each array represents the top of the corresponding stack.

Find the maximum possible equal sum(sum of all elements) of all three stacks by removing zero or more elements from the top of each stack.

If it is not possible to make the sum of all three stacks equal, return  **0** .

**Examples:**

```
Input: s1 = [3, 2, 1, 1, 1], s2 = [4, 3, 2], s3 = [2, 5, 4, 1]
Output: 5
Explanation: Remove 3 from s1, 4 from s2, and 2, 5 from s3. The remaining sums of all three stacks are equal to 5.

```

```
Input: s1 = [4,7], s2 = [10], s3 = [1,2,3]
Output: 0
Explanation: It is not possible to make the sums of all three stacks equal by removing elements from their tops.

```