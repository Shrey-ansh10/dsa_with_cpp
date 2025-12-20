# DSA Learning Journey with C++

This repository is a comprehensive collection of Data Structures and Algorithms (DSA) implementations, solutions, and practice problems in C++. It documents my learning journey with well-organized, topic-wise code implementations ranging from basic fundamentals to advanced algorithms.

## �� Repository Overview

This is a growing collection of:
- **Core Data Structures**: Arrays, Linked Lists, Stack, Queue, Trees, etc.
- **Fundamental Algorithms**: Sorting, Searching, Pattern Matching, etc.
- **Advanced Topics**: Recursion, Dynamic Programming, Graph Algorithms, etc.
- **Problem Solutions**: LeetCode problems and classic coding challenges
- **Pattern Programs**: Visual pattern printing implementations

## 🗂️ Detailed Folder Structure

### **Core Data Structures**

#### `arrays/` - Array Operations & Problems
- **Basics**: `array.cpp`, `linearSearch.cpp`, `reverseArray.cpp`, `smallestLargest.cpp`
- **Common Problems**: 
  - `twoSum.cpp` - Find two numbers that add up to target
  - `threeSum.cpp` - Find three numbers summing to target
  - `subArrays/subArray.cpp` - Subarray operations
  - `2dArrays/` - 2D array operations and problems
    - `2dArrays.cpp` - Basic 2D array operations
    - `maxPathScore.cpp` - Maximum path sum in 2D grid
- **Advanced Array Problems**:
  - `gasStation.cpp` - Gas station problem
  - `tarppingRainwater.cpp` - Trapping rainwater algorithm
  - `distanceBtwMirrors.cpp` - Mirror distance calculation
  - `minDist.cpp` - Minimum distance problems
  - `smoothDescent.cpp` - Descent optimization
  - `countElementsWithAtLeastKgreaterVals.cpp` - Element counting with constraints
  - `validSudoku.cpp` - Sudoku validation
  - `couponCodeValidator.cpp` - Coupon validation logic

#### `linked list/` - Linked List Implementations & Problems
- **Basic Implementations**:
  - `linkedList.cpp` - Basic linked list operations
  - `doublyLinkedList.cpp` - Doubly linked list
  - `circularLLL.cpp` - Circular linked list
- **Common LL Problems**:
  - `reverseLL.cpp` - Reverse a linked list
  - `mergeTwoSortedLists.cpp` - Merge two sorted lists
  - `swapNodeInPairs.cpp` - Swap adjacent nodes
  - `swapKthNode.cpp` - Swap Kth nodes
  - `deleteNthNodeFromEnd.cpp` - Delete node from end
  - `reverseNodesInKGroup.cpp` - Reverse nodes in groups of K
- **Advanced LL Concepts**:
  - `detectCycleInLL.cpp` - Cycle detection
  - `startNodeOfCycleInLL.cpp` - Find cycle start node
  - `removeCycleFromLL.cpp` - Remove cycle from list
  - `deepCopyOfLL.cpp` - Deep copy with random pointers
  - `flattenMultiLevelLL.cpp` - Flatten multi-level lists
  - `maxTwinSum.cpp` - Maximum twin sum problem

#### `stack/` - Stack Data Structure & Applications
- **Basics**: `stack.cpp` - Basic stack operations
- **Stack Implementations**:
  - `stackUsingQueue.cpp` - Implement stack using queue
  - `minStack.cpp` - Stack with O(1) min operation
- **Common Stack Problems**:
  - `validParenthesis.cpp` - Valid parenthesis matching
  - `longestValidParentheses.cpp` - Longest valid parentheses
  - `nextGreterElement.cpp`, `nextGreateElement1.cpp`, `nextGreaterElement2.cpp` - Next greater element variants
  - `previousSmallerElement.cpp` - Previous smaller element
  - `largestRectangle.cpp` - Largest rectangle in histogram
  - `stockSpan.cpp` - Stock span problem

#### `queue/` - Queue Data Structure & Applications
- **Basics**: `queue.cpp` - Basic queue operations
- **Queue Implementations**:
  - `circularQueue.cpp` - Circular queue
  - `queueUsingStack.cpp` - Implement queue using stack
- **Queue Applications**:
  - `slidingWindowMax.cpp` - Maximum in sliding window
  - `firstUniqueChar.cpp` - First unique character finder
  - `maxKelements.cpp` - Maximum K elements

#### `binary tree/` - Binary Tree Operations
- `binaryTree.cpp` - Comprehensive binary tree implementations and traversals

### **Fundamental Algorithms**

#### `basics/` - Basic Programming Concepts
- `checkprime.cpp` - Prime number checking
- `factorial.cpp` - Factorial calculation
- `plaindromeNum.cpp` - Palindrome number checking
- `divisiblityTest.cpp` - Divisibility testing

#### `functions/` - Utility Functions
- `binary2Decimal.cpp` - Binary to decimal conversion
- `decimal2Binary.cpp` - Decimal to binary conversion
- `fibinnaciSeries.cpp` - Fibonacci series generation
- `minOfTwoNum.cpp` - Minimum of two numbers
- `nfactorial.cpp` - N factorial calculation

#### `sorting Algorithms/` - Sorting Implementations
- `bubbleSort.cpp` - Bubble sort implementation
- `insertionSort.cpp` - Insertion sort
- `selectionSort.cpp` - Selection sort
- `mergeSort.cpp` - Merge sort (divide and conquer)
- `quickSort.cpp` - Quick sort (pivot-based)

#### `binary search/` - Binary Search & Applications
- `binarySearch.cpp` - Classic binary search
- `peakOfMountain.cpp` - Find peak in mountain
- `agressiveCows.cpp` - Binary search optimization problem
- `bookAllocation.cpp` - Book allocation problem
- `paintersPartition.cpp` - Partition painters problem

#### `patterns/` - Pattern Printing Problems
- `pyramid.cpp` - Pyramid pattern
- `invertedPyramid.cpp` - Inverted pyramid
- `invertedTriangle.cpp` - Triangle patterns
- `butterfly.cpp` - Butterfly pattern
- `hollowDiamondPattern.cpp` - Hollow diamond

### **Advanced Topics**

#### `recursion/` - Recursive Algorithms & Backtracking
- **Recursion Fundamentals**:
  - `intro.cpp` - Recursion introduction
- **Backtracking Problems**:
  - `nQueen.cpp` - N-Queens problem
  - `sudokuSolver.cpp` - Sudoku solver
  - `pathInMaze.cpp` - Maze path finding
  - `combinationSum.cpp` - Combination sum problem
- **Permutations & Combinations**:
  - `permutationOfSet.cpp` - Set permutations
  - `permutatuinOfString.cpp` - String permutations
  - `permutations2.cpp` - Permutations with duplicates
  - `printSubsets.cpp` - Generate all subsets
  - `findSubsetWithoutDuplicated.cpp` - Subsets without duplicates
  - `plaindromePartitioning.cpp` - Palindrome partitioning
- **Advanced Recursion**:
  - `mergeSort.cpp` - Merge sort (recursive)
  - `countInversion.cpp` - Count inversions
  - `knightConfiguration.cpp` - Knight tour configuration validation
  - `numOfWaysToClimbStairs.cpp` - Staircase climbing ways

#### `strings/` - String Algorithms & Operations
- **Basic String Operations**:
  - `strings.cpp` - String fundamentals
  - `charArr.cpp` - Character array operations
- **String Patterns & Matching**:
  - `longestCommonPrefix.cpp` - Find longest common prefix
  - `findAnagram.cpp` - Anagram finder
  - `validAnagram.cpp` - Anagram validation
- **String Transformations**:
  - `validPalindromeString.cpp` - Palindrome validation
  - `validParenthesis.cpp` - Parenthesis validation
  - `numOfFlipsToRevBinaryString.cpp` - Binary string flipping
- **Advanced String Problems**:
  - `maxDistinct.cpp` - Maximum distinct elements
  - `uniqueEmails.cpp` - Unique email counting

### **Specialized Problems**

#### Standalone Problem Files
- `containerWithMostWater.cpp` - Container with most water (two-pointer technique)
- `stockBuySell.cpp` - Stock buy-sell problems
- `sieveOfEratosthenes.cpp` - Prime sieve algorithm
- `LRUCache.cpp` - Least Recently Used Cache implementation

#### `math/` - Mathematical Algorithms
- `math.cpp` - Core math operations
- `powerOfX.cpp` - Power calculation
- `moduloOperator.cpp` - Modulo operations
- `smallestNumWithSetBits.cpp` - Smallest number with set bits
- `wavinessOfNum.cpp` - Number waviness calculation

## 🚀 How to Use

### Compile and Run
```bash
# Compile a C++ file
g++ -std=c++17 path/to/file.cpp -o output

# Run the compiled program
./output
```

### Examples
```bash
# Compile and run a binary search solution
g++ -std=c++17 binary\ search/binarySearch.cpp -o binsearch
./binsearch

# Compile a recursion problem
g++ -std=c++17 recursion/nQueen.cpp -o nqueen
./nqueen
```

## 💡 Key Features

✅ **Well-Organized**: Topic-wise folder structure for easy navigation  
✅ **Comprehensive**: From basics to advanced DSA concepts  
✅ **Multiple Approaches**: Different solutions for the same problem (iterative, recursive, optimized)  
✅ **Clean Code**: Well-commented implementations for better understanding  
✅ **Problem Focus**: Solutions to classic DSA and LeetCode problems  
✅ **Learning Journey**: Documents progression from fundamentals to advanced concepts

## 📊 Topics Covered

- **Data Structures**: Arrays, Linked Lists, Stack, Queue, Trees, Hash Tables
- **Searching**: Linear Search, Binary Search, Advanced Search Patterns
- **Sorting**: Bubble, Insertion, Selection, Merge Sort, Quick Sort
- **Recursion & Backtracking**: N-Queens, Sudoku, Maze, Permutations
- **String Algorithms**: Anagram, Palindrome, Pattern Matching
- **Advanced Topics**: LRU Cache, Cycle Detection, Subarray Problems
- **Mathematical**: Prime Checking, Fibonacci, Power Calculation, Modulo

## 🤝 Contributions & Feedback

This is a personal learning repository, but suggestions, improvements, and discussions are welcome!  
- Feel free to fork and adapt the code for your learning
- Open issues for bugs, improvements, or clarifications
- Pull requests with enhancements are appreciated

## 📅 Regular Updates

This repository is actively maintained and updated as I:
- Learn new DSA topics and algorithms
- Solve additional problems from various platforms
- Optimize and improve existing implementations
- Add better explanations and comments

---

**Last Updated**: December 2025  
**Language**: C++ (C++17 and above)  
**Status**: Active Development

**Happy Learning & Happy Coding! 🚀**
