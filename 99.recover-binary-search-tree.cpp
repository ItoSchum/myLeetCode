/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
 *
 * https://leetcode.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Hard (35.46%)
 * Likes:    2330
 * Dislikes: 89
 * Total Accepted:    205K
 * Total Submissions: 481K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * You are given the root of a binary search tree (BST), where exactly two
 * nodes of the tree were swapped by mistake. Recover the tree without changing
 * its structure.
 * 
 * Follow up: A solution using O(n) space is pretty straight forward. Could you
 * devise a constant space solution?
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,3,null,null,2]
 * Output: [3,1,null,null,2]
 * Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3
 * makes the BST valid.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [3,1,4,null,null,2]
 * Output: [2,1,4,null,null,3]
 * Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2
 * and 3 makes the BST valid.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [2, 1000].
 * -2^31 <= Node.val <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
#ifdef DEBUG
#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif

class Solution {
public:
    void recoverTree(TreeNode* root) {
        inorder_traverse(root);
        swap(error_ptr1, error_ptr2);       
    }
        
    void swap(TreeNode* left, TreeNode* right) {
        int temp_val = left->val;
        left->val = right->val;
        right->val = temp_val;
    }

    void inorder_traverse(TreeNode* curr) {
        if (curr == nullptr) 
            return;
        
        inorder_traverse(curr->left);
          
        if (prev != nullptr && curr->val < prev->val) {
            // printf("Swap curr %d with prev %d\n", curr->val, prev->val ); 
            if (error_ptr1 == nullptr) {
                error_ptr1 = prev;
            }
            error_ptr2 = curr;
        }
        prev = curr;
        inorder_traverse(curr->right);
    }

private:
    TreeNode* error_ptr1;
    TreeNode* error_ptr2;
    TreeNode* prev = nullptr;
};
// @lc code=end

// n = node number
// Time: O(n)
// Space: O(1)

#ifdef DEBUG
int main() {
    Solution sol = Solution();
    return 0;
}
#endif