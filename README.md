# Project -1 EECE 7205 Max-Min Grouping via Dynamic Programming
This project implements a **dynamic programming** algorithm to solve the _Max-Min_ Grouping problem. Given an array **A[1...N]**, the goal is to partition it into M contiguous groups such that the **minimum group sum** among all the groups is **maximized**. This is achieved through a carefully structured dynamic programming solution.

# Problem Statement
Given:
* An integer array A[1...N]
* An integer M indicating the number of groups
Define a grouping G[1...M] such that:
* Each group G[i] contains a contiguous subarray from A
* The sum of each group is stored in array B[1...M]

**Objective**: Find the grouping that **maximizes the minimum value in B**

# Example
For input:

```ini
A = {3, 9, 7, 8, 2, 6, 5, 10, 1, 7, 6, 4}
M = 3
```
The algorithm computes an optimal grouping where the minimum sum among the M groups is maximized.

# Algorithm Summary
* Uses a DP table dp[i][j] to store the optimal result for partitioning the first i elements into j groups.
* Utilizes prefix sums to compute group sums efficiently.
* A partitionTable is maintained to trace back the optimal group sizes.
Final outputs include:
* Optimal group sizes (number of elements in each group)
* Corresponding sums of each group
* The maximum minimum sum

# Time Complexity: O(M × N²)
* Where N is the number of elements in array A
* And M is the number of desired groups

# Repository Contents
* project-1 final.cpp: Complete C++ source code for the dynamic programming solution.
* Project 1.pdf: Official problem description and project requirements.
* project-1 report (1).pdf:
**Final report includes**:
* Pseudocode
* Runtime complexity analysis
* Sample outputs
* Complete source code

# How to Run
```bash

# Clone the repository
git clone https://github.com/PRAYAG2000n/Project-1.git
cd Project-1

# Compile the code
g++ -o max_min_grouping "project-1 final.cpp"

# Run the program
./max_min_grouping
```

Follow the prompts to:
* Enter the size of the array
* Provide the array elements
* Specify the number of groups M

# Output Format
The program prints:
* Optimal sizes: — number of elements in each group
* Optimal sums: — sum of elements in each group
* The maximum minimum sum is: — final result that was maximized


