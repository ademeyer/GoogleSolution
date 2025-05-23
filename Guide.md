﻿
** Meta Questions **
    - Done:
        - 1.    Clone Graph
        - 2.    Course Schedule (Topological Sort)
        - 3.    Serialize and Deserialize Binary Tree
        - 4.    Binary Tree Maximum Path Sum
        - 5.    Maximum Product Subarray
        - 6.    Merge K Sorted Lists
        - 7.    LRU Cache Implementation
        - 8.    Longest Palindromic Substring
        - 9.    Find the Longest Increasing Subsequence
        - 10.   Minimum Remove to Make Valid Parentheses
        - 11.   Max Consecutive Ones III
        - 12.   Valid Palindrome
        - 13.   Kth Largest Element in an Array
        - 14.   Asteroid Collision
        - 15.   Binary Search Tree Iterator
        - 16.   Minimum Window Substring
        - 17.   Top K Frequent Elements
        - 18.   Pow(x, n)
        - 19.   K Closest Points to Origin
        - 20.   Pacific Atlantic Water Flow
        - 21.   Best Time to Buy and Sell Stock
        - 22.   Merge Sorted Array
        - 23.   Binary Tree Zigzag Level Order Traversal
        - 24.   Lowest Common Ancestor of a Binary Tree
        - 25.   Simplify Path
        - 26.   Word Search II
        - 27.   Maximum Swap
        - 28.   Shortest Path in Binary Matrix
        - 29.   Range Sum of BST
        - 30.   Making A Large Island
        - 31.   Next Permutation
        - 32.   Subarray Sum Equals K
        - 33.   Find closest element in BST
        - 34.   Letter Combinations of a Phone Number
        - 35.   Sliding Window Maximum
        - 36.   Valid Palindrome II
        - 37.   Valid Palindrome III
        - 38.   Lowest Common Ancestor of a Binary Search Tree
        - 39.   Lowest Common Ancestor of a Binary Tree III
        - 40.   Palindrome Permutation
        - 41.   Custom Sort String
        - 42.   Interval List Intersections
        - 43.   Sliding Window Median
        - 44.   Minesweeper
        - 45.   Vertical Order Traversal of a Binary Tree
        - 46.   Basic Calculator II
        - 47.   Valid Number
        - 48.   Buildings With an Ocean View
        - 49.   Find Peak Element
        - 50.   Valid Word Abbreviation
        - 51.   Trapping Rain Water
        - 52.   Word Ladder
        - 53.   Sum Root to Leaf Numbers
        - 54.   Diameter of Binary Tree

    - Todo:
        - 1.    
        - 2.    
        - 3.    
        - 4.    Median of Two Sorted Arrays
        - 5.    
        - 6.   
        - 7.    
        - 8.    Modify characters by shifting pattern (not on leetcode)

    - Looking through Top 75  in the Last 6 Months list



    class Solution {
public:
    // Function to shift letters in the string based on the shifts vector.
    string shiftingLetters(string s, vector<int>& shifts) {
        long long totalShifts = 0;  // Initialize total shifts to 0
        int stringLength = s.size(); // Get the size of the string
      
        // Loop through the string starting from the end
        for (int i = stringLength - 1; i >= 0; --i) {
            totalShifts += shifts[i];  // Add shifts for current position to total shifts
            totalShifts %= 26;         // Avoid overflow and keep within valid alphabet indexes
          
            // Calculate the new offset for current letter based on the total shifts
            int newLetterIndex = (s[i] - 'a' + totalShifts) % 26;
            s[i] = 'a' + newLetterIndex;  // Set the new letter in the string
        }
      
        return s;  // Return the modified string after shifts
    }
};
