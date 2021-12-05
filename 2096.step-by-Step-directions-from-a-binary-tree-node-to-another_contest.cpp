// 2096. Step-By-Step Directions From a Binary Tree Node to Another
// User Accepted:1714
// User Tried:2600
// Total Accepted:1757
// Total Submissions:5635
// Difficulty:Medium
// You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

// Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

// 'L' means to go from a node to its left child node.
// 'R' means to go from a node to its right child node.
// 'U' means to go from a node to its parent node.
// Return the step-by-step directions of the shortest path from node s to node t.

 

// Example 1:


// Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
// Output: "UURL"
// Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
// Example 2:


// Input: root = [2,1], startValue = 2, destValue = 1
// Output: "L"
// Explanation: The shortest path is: 2 → 1.
 

// Constraints:

// The number of nodes in the tree is n.
// 2 <= n <= 105
// 1 <= Node.val <= n
// All the values in the tree are unique.
// 1 <= startValue, destValue <= n
// startValue != destValue

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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        std::string pathToStart = "";
        std::string pathToDest = "";
        dfsSearch(root, startValue, pathToStart, pathToStart);
        dfsSearch(root, destValue, pathToDest, pathToDest);
        
        int flippingStart;
        for (flippingStart = 0; flippingStart < std::min(pathToStart.size(), pathToDest.size()); ++flippingStart) {
            if (pathToStart[flippingStart] != pathToDest[flippingStart]) { break; }
        }
        
        int upperPathLen = pathToStart.size() - flippingStart;
        // std::cout << pathToStart << "\n" << pathToDest << std::endl;
        std::string upperPath(upperPathLen, 'U');
        return upperPath.append( pathToDest.substr(flippingStart) );
    }
    
    void dfsSearch(TreeNode* root, int value, const std::string& currPath, std::string& outputPath) {
        if (root == nullptr) {
            return;
        }
        if (root->val == value) {
            outputPath = currPath;
            return;
        }
        if (root->left) { 
            dfsSearch(root->left, value, currPath + "L", outputPath); 
        }
        if (root->right) { 
            dfsSearch(root->right, value, currPath + "R", outputPath); 
        }
    }
    
};