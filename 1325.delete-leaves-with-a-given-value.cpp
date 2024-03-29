/*
 * @lc app=leetcode id=1325 lang=cpp
 *
 * [1325] Delete Leaves With a Given Value
 *
 * https://leetcode.com/problems/delete-leaves-with-a-given-value/description/
 *
 * algorithms
 * Medium (74.07%)
 * Likes:    1077
 * Dislikes: 22
 * Total Accepted:    52.9K
 * Total Submissions: 71K
 * Testcase Example:  '[1,2,3,2,null,2,4]\n2'
 *
 * Given a binary tree root and an integer target, delete all the leaf nodes
 * with value target.
 * 
 * Note that once you delete a leaf node with value target, if it's parent node
 * becomes a leaf node and has the value target, it should also be deleted (you
 * need to continue doing that until you can't).
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,2,3,2,null,2,4], target = 2
 * Output: [1,null,3,null,4]
 * Explanation: Leaf nodes in green with value (target = 2) are removed
 * (Picture in left). 
 * After removing, new nodes become leaf nodes with value (target = 2) (Picture
 * in center).
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: root = [1,3,3,3,2], target = 3
 * Output: [1,3,null,null,2]
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: root = [1,2,null,2,null,2], target = 2
 * Output: [1]
 * Explanation: Leaf nodes in green with value (target = 2) are removed at each
 * step.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: root = [1,1,1], target = 1
 * Output: []
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: root = [1,2,3], target = 1
 * Output: [1,2,3]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= target <= 1000
 * The given binary tree will have between 1 and 3000 nodes.
 * Each node's value is between [1, 1000].
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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        bool deleteRoot = postOrderRemove(root, target);
        if (deleteRoot == true) {
            root = nullptr;
        }
        return root;
    }
    
    bool postOrderRemove(TreeNode* root, int target) {
        // If nullptr node, return
        if (root == nullptr) {
            return root;
        }
        // Otherwise remove target value in post-order
        bool isLeftRemoved = postOrderRemove(root->left, target);
        bool isRightRemoved = postOrderRemove(root->right, target);
        
        // remove left/right child node
        if (isLeftRemoved) { root->left = nullptr;}
        if (isRightRemoved) { root->right = nullptr; }
        
        // check if needed to remove itself
        bool isRootRemoved = false;
        if (root->left == nullptr && root->right == nullptr && root->val == target) {
            isRootRemoved = true; 
        }
        return isRootRemoved;
    } 

};
// @lc code=end

// n = node number
// Time: O(n)
// Space: O(1)

