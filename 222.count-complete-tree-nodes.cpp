/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
 *
 * https://leetcode.com/problems/count-complete-tree-nodes/description/
 *
 * algorithms
 * Medium (50.47%)
 * Likes:    3357
 * Dislikes: 275
 * Total Accepted:    319.2K
 * Total Submissions: 621K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * Given the root of a complete binary tree, return the number of the nodes in
 * the tree.
 * 
 * According to Wikipedia, every level, except possibly the last, is completely
 * filled in a complete binary tree, and all nodes in the last level are as far
 * left as possible. It can have between 1 and 2^h nodes inclusive at the last
 * level h.
 * 
 * Design an algorithm that runs in less than O(n) time complexity.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3,4,5,6]
 * Output: 6
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = []
 * Output: 0
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [1]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 5 * 10^4].
 * 0 <= Node.val <= 5 * 10^4
 * The tree is guaranteed to be complete.
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
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        TreeNode* leftChild = root;
        TreeNode* rightChild = root;
        int leftHeight = 0;
        int rightHeight = 0;
        
        while (leftChild->left != nullptr) {
            leftHeight++;
            leftChild = leftChild->left;
        }
        while (rightChild->right != nullptr) {
            rightHeight++;
            rightChild = rightChild->right;
        }
        if (leftHeight == rightHeight) {
            return ( (int)std::pow(2, leftHeight + 1) - 1 );
        } else {
            return ( 1 + countNodes(root->left) + countNodes(root->right) );
        }

    }
};
// @lc code=end

// n = node number
// Time: O( [log2(n)]^2 )
// Space: O( log2(n) )