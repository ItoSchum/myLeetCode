#include <iostream>
#include <vector>
#include <queue>

using namespace std;
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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        extractAllNodeVals(root);
        filterKClosest(k, target);
        
        vector<int> closestKValVec(k);
        for (unsigned int i = 0; i < k; ++i) {
            closestKValVec[i] = pqueue.top().second;
            pqueue.pop();
        }
        return closestKValVec;
    }
    
    // inorder traversal
    void extractAllNodeVals(const TreeNode* root) {
        if (root == nullptr) { 
            return; 
        }
        extractAllNodeVals(root->left);
        allNodeVals.push_back(root->val);
        extractAllNodeVals(root->right);
    }
    
    // filter other nodes keeping first K
    void filterKClosest(int cloestK, double target) {
        for (unsigned int i = 0; i < allNodeVals.size(); ++i) {
            pqueue.push( {abs(allNodeVals[i] - target), allNodeVals[i]} );
            while (pqueue.size() > cloestK) {
                pqueue.pop();
            }
        }
    }
    
private:
    vector<int> allNodeVals;
    priority_queue<pair<double, int> > pqueue;
};

// n = node number
// Time: O( nlog(k) )
// Space: O(n + k)