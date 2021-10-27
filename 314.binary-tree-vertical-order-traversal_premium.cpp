#include <vector>
#include <map>

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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<std::vector<int>> verticalOrder(TreeNode* root) {
        stepVerticalOrder(root, 0, 0);
        std::vector<std::vector<int> > results;
        
        std::map<int, std::map<int, std::vector<int>> >::iterator colItr;
        for (colItr = coordToNodes.begin(); colItr != coordToNodes.end(); ++colItr) {
            std::map<int, std::vector<int> >::iterator rowItr;
            std::vector<int> vals;
            for (rowItr = colItr->second.begin(); rowItr != colItr->second.end(); ++rowItr) {
                vals.insert(vals.end(), rowItr->second.begin(), rowItr->second.end() );
            }
            results.push_back(vals);
        }
        
        return results;
    }
    
    void stepVerticalOrder(TreeNode* root, int row, int col) {
        // if nullptr node, terminate
        if (root == nullptr) {
            return;
        }
        // otherwise, pre-order treversal
        coordToNodes[col][row].push_back(root->val);
        stepVerticalOrder(root->left, row + 1, col - 1);
        stepVerticalOrder(root->right, row + 1, col + 1);
    }

private:
    std::map<int, std::map<int, std::vector<int>> > coordToNodes;
};