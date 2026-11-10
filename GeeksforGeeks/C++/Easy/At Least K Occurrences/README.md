# 📝 At Least K Occurrences (GeeksforGeeks)

🔗 [Problem Link](https://www.geeksforgeeks.org/problems/first-element-to-occur-k-times5150/1)

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen) ![Language](https://img.shields.io/badge/Language-C++-blue)

### 💡 Tags
Arrays, Hash

### 🚀 Performance
- **Runtime:** Successfully Evaluated
- **Memory:** N/A

---

### 📜 Problem Description

Given an array  **arr[]**  and an integer  **k** , find the first element that occurs at least k times in the array.

- If multiple elements satisfy the condition, return the element whose k-th occurrence appears earliest in the array.
- If no element occurs at least k times, return -1.

**Examples:**

```
Input: arr[] = [1, 7, 4, 3, 4, 8, 7], k = 2
Output: 4
Explanation: Both 7 and 4 occur twice. However, 4 reaches its second occurrence before 7, so the answer is 4.
```

```
Input: arr[] = [3, 1, 3, 4, 5, 1, 3, 3, 5, 4], k = 3
Output: 3
Explanation: The element 3 is the only element that occurs at least 3 times in the array.

```

```
Input: arr[] = [10, 8, 2], k = 10
Output: -1
Explanation: No element occurs at least 10 times in the array.
```