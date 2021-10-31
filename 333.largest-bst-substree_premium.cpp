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

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class SubtreeInfo {
public:
    // Constructors
    SubtreeInfo(int minVal = INT_MAX, int maxVal = INT_MIN, int maxSize = 0) {
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->maxSize = maxSize;
    }
    // Attributes
    int minVal, maxVal, maxSize;
};

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        return postOrderBSTSubtree(root).maxSize;
    }
    
    SubtreeInfo postOrderBSTSubtree(TreeNode* root) {
        // If nullptr node
        if (root == nullptr) {
            return SubtreeInfo();
        }
        // Otherwise, post-order traversal
        SubtreeInfo leftInfo = postOrderBSTSubtree(root->left);
        SubtreeInfo rightInfo = postOrderBSTSubtree(root->right);
        
        // Check for current node
        // If left, right, current can be combined to a new BST
        if (root->val > leftInfo.maxVal && root->val < rightInfo.minVal) {
            return SubtreeInfo(
                std::min(root->val, leftInfo.minVal), 
                std::max(root->val, rightInfo.maxVal), 
                leftInfo.maxSize + rightInfo.maxSize + 1);
        }
        // Otherwise return an info which let its parent cannot be a BST
        else {
            return SubtreeInfo(INT_MIN, INT_MAX, std::max(leftInfo.maxSize, rightInfo.maxSize) );
        }
    }
};

// n = node number
// Time: O(n)
// Space: O( log(n) ), worst case O(n)