/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (43.71%)
 * Likes:    3380
 * Dislikes: 221
 * Total Accepted:    240.7K
 * Total Submissions: 542.3K
 * Testcase Example:  '3'
 *
 * Given an integer n, return all the structurally unique BST's (binary search
 * trees), which has exactly n nodes of unique values from 1 to n. Return the
 * answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3
 * Output:
 * [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: [[1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 8
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

#include <vector>
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
    std::vector<TreeNode*> generateTrees(int n) {
        if (n < 1) { return std::vector<TreeNode*>(); }
        return build(1, n);
    }

    std::vector<TreeNode*> build(int lo, int hi) {
        std::vector<TreeNode*> res = std::vector<TreeNode*>();
        if (lo > hi) {
            res.push_back(nullptr);
            return res;
        }
        for (int i = lo; i <= hi; ++i) {
            std::vector<TreeNode*> leftTree = build(lo, i - 1);
            std::vector<TreeNode*> rightTree = build(i + 1, hi);
            for (int j = 0; j < leftTree.size(); ++j) {
                for (int k = 0; k < rightTree.size(); ++k) {
                    TreeNode* root = new TreeNode(i, leftTree[j], rightTree[k]);
                    res.push_back(root);
                }
            }
         }
        return res;
    }

};

// @lc code=end

// n = node number
// Time: O(2^log2(n))
// Space: O(n)
