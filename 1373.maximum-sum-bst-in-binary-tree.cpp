/*
 * @lc app=leetcode id=1373 lang=cpp
 *
 * [1373] Maximum Sum BST in Binary Tree
 *
 * https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/
 *
 * algorithms
 * Hard (37.09%)
 * Likes:    595
 * Dislikes: 81
 * Total Accepted:    19.2K
 * Total Submissions: 51.3K
 * Testcase Example:  '[1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]'
 *
 * Given a binary tree root, the task is to return the maximum sum of all keys
 * of any sub-tree which is also a Binary Search Tree (BST).
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
 * Output: 20
 * Explanation: Maximum sum in a valid Binary search tree is obtained in root
 * node with key equal to 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: root = [4,3,null,1,2]
 * Output: 2
 * Explanation: Maximum sum in a valid Binary search tree is obtained in a
 * single root node with key equal to 2.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [-4,-2,-5]
 * Output: 0
 * Explanation: All values are negatives. Return an empty BST.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: root = [2,1,3]
 * Output: 6
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: root = [5,4,8,3,null,6,3]
 * Output: 7
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The given binary tree will have between 1 and 40000 nodes.
 * Each node's value is between [-4 * 10^4 , 4 * 10^4].
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// #include <iostream>
// #include <limits.h>
// // #include <bits/stdc++.h>
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    int* maxSum = new int[4]{1, INT_MIN, INT_MAX, 0};
    
    int maxSumBST(TreeNode* root) {
        traverse(root);
        return maxSum[3];
    }

    int* traverse(TreeNode* root) {
        if (root == nullptr) {
            return new int[4]{1, INT_MAX, INT_MIN, 0};
        }

        int* leftTreeMaxSum = traverse(root->left);
        int* rightTreeMaxSum = traverse(root->right);

        int* res = new int[4]{1, INT_MIN, INT_MAX, 0};
        if (leftTreeMaxSum[0] == 1 && rightTreeMaxSum[0] == 1 
            && root->val > leftTreeMaxSum[2] && root->val < rightTreeMaxSum[1]) {
            res[0] = 1;
            res[1] = std::min(root->val, leftTreeMaxSum[1]);
            res[2] = std::max(root->val, rightTreeMaxSum[2]);
            res[3] = root->val + leftTreeMaxSum[3] + rightTreeMaxSum[3];
            if (maxSum[3] < res[3]) { maxSum = res; }
            // std::cout << "found " << res[3] << std::endl;
        }
        else {
            res[0] = 0;
        }
        return res;
    }
};
// @lc code=end

// n = node number
// Time: O(n)
// Space: O(log2(n))
