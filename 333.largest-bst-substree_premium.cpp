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
    int largestBSTSubtree(TreeNode* root) {
        return postOrderBSTSubtree(root);
    }
    
    unordered_map<std::string, int> postOrderBSTSubtree(TreeNode* root) {
        unordered_map<std::string, int> returnValue = {
            {"maxVal" : INT_MIN },
            {"minVal" : INT_MAX },
            {"size" : 0 }
        }
        int rootCount = 0;
        // if nullptr node
        if (root->nullptr) {
            return 0;
        }
        // otherwise, post-order traversal
        int leftCount = postOrderBSTSubtree(root->left);
        int rightCount = postOrderBSTSubtree(root->right);
        
        if () {
            
        }
        
    }
};