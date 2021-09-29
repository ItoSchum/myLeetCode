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
#include <vector>

class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        int roundNum = 0;
        while(root != nullptr) {
            leafNodeVals.push_back({ });
            stepFindLeaves(root, roundNum++);   
        }
        return leafNodeVals;
    }
    
    void stepFindLeaves(TreeNode*& root, int roundNum) {
        // if null node
        if (root == nullptr) {
            return;
        }

        // if leaf node
        if (root->left == nullptr && root->right == nullptr) {
            leafNodeVals[roundNum].push_back(root->val);
            root = nullptr;
            return;
        }
        
        // if not leaf node
        stepFindLeaves(root->left, roundNum);
        stepFindLeaves(root->right, roundNum);
    }
    
private:
    vector<vector<int> > leafNodeVals;
};

// n = node number
// Time: O( log2(n) * log2(n) )
// Space: O(1)