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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        
        TreeNode* leftMostNode = root;
        while (leftMostNode != nullptr && leftMostNode->left != nullptr) {
            leftMostNode = leftMostNode->left;
        }
        stepUpsideDownBinaryTree(root, nullptr);
        return leftMostNode;
    }
    
    void stepUpsideDownBinaryTree(TreeNode* curr, TreeNode* parent) {
        // if null node
        if (curr == nullptr) {
            return;
        }
        stepUpsideDownBinaryTree(curr->left, curr);
        // if most left node
        if (parent == nullptr) {
            curr->left = nullptr;
            curr->right = nullptr;
        } else {
            curr->left = parent->right; 
            curr->right = parent;
        }
    }
};

// n = node number
// Time: O(n)
// Spce: O(1)