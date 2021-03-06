# Algorithms and Data Structures

This repository was made to support the learning of algorithm analysis and data structures.

## Sorting algorithms

Sorting algorithms are a nice study case to learn algorithm analysis since it is possible to visualize how simple changes to the code influence the better/worst scenario. Here we have implemented the following techniques and with their respective description.

```json
{
  "sorting/": {
    "bubble-sort": "O(nˆ2)",
    "counting-sort": "O(n)",
    "heap-sort": "O(nlogn)",
    "insertion-sort": "O(nˆ2)",
    "merge-sort": "O(nlogn)",
    "quick-sort": "O(nlogn)",
    "radix-sort": "O(n)",
    "selection-sort": "O(nˆ2)"
  }
}
```

## Data Structures

### Linear Lists

There are a bunch of implementation of linear lists. Here are a few of them and their basic functions: `[initialize, show, search, insert, remove]`.

```json
{
  "linear-lists/": {
    "sequential-list": "a basic list where the elements have the same physical and logical order.",
    "linked-list": "a list where the physical and logical order are not the same.",
    "circular-linked-list": "a list where the elements forms a circle.",
    "stack": "a list where insertions and removals happens at the beginning of the structure.",
    "deque": "stack and a queue implemented in the same structure.",
    "queue": "a list where insertions are at the end and removals are at the beginning."
  }
}
```

### Trees

Trees are non-linear data-structs. Here we have three implementations of trees with their basic functions.

```json
{
  "trees/": {
    "binary-search-tree": "a basic tree implementation without any strategy to control the tree imbalance problem caused by insertions or deletions.",
    "avl-tree": "a balanced binary search tree where the balance factor is given by the height of the sub-trees.",
    "red-black-tree": "a balanced binary search tree where the balance factor is that every path from a parent node to a leaf contains the same number of black nodes."
  }
}
```

### Linear Lists vs Trees - Complexity Comparison

![image](/assets/complexity-comparison.png)

### Graphs

Graphs are a non-linear data-struct that is used to represent the relationship between two elements.

```json
{
  "graphs/": {
    "Graph": "main class, implementing a direct graph and some basic functions",
    "BreadthFirstSearch": "algorithm to find the shortest path between two vertices",
    "DepthFirstSearch": "algorithm to find the path between two vertices recursively"
  }
}
```

## Algorithms


### Brute Force (`backtracking`)

- Knight's Tour
- Binary Knapsack Problem

### Greedy Algorithms

- Fractional Knapsack Problem

## Other topics

- Loop Invariant
- Priority Queues
- Minimum Fibonacci Heap

## References

`T.H. Cormen, C.E. Leiserson, R.L. Rivest and C. Stein, Introduction to Algorithms, 2nd.ed., MIT Press & McGraw-Hill, 2001.`
