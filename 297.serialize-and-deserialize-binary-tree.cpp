/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (50.87%)
 * Likes:    4467
 * Dislikes: 204
 * Total Accepted:    457.9K
 * Total Submissions: 899.7K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 * 
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 * 
 * Clarification: The input/output format is the same as how LeetCode
 * serializes a binary tree. You do not necessarily need to follow this format,
 * so please be creative and come up with different approaches yourself.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3,null,null,4,5]
 * Output: [1,2,3,null,null,4,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = []
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [1]
 * Output: [1]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: root = [1,2]
 * Output: [1,2]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 10^4].
 * -1000 <= Node.val <= 1000
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <sstream>
#include <list>
#include <string>
#include <bits/stdc++.h>

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Codec {
public:

    const std::string SEPARATOR = ","; 
    const std::string NULL_NODE = "null";
    std::list<std::string> serializedStrList;

    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        serializeStep(root);
        std::string serializedStr;
        std::list<std::string>::iterator itr;
        for (itr = serializedStrList.begin(); itr != serializedStrList.end(); ++itr) {
            serializedStr.append(*itr);
            serializedStr.append(SEPARATOR);
        }
        return serializedStr;
    }

    void serializeStep(TreeNode* node) {
        if (node == nullptr) {
            serializedStrList.push_back(NULL_NODE);
            return;
        }
        serializedStrList.push_back(std::to_string(node->val) );
        serializeStep(node->left);
        serializeStep(node->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        std::stringstream strStream(data);
        std::list<std::string> strList;
        
        while (strStream.good()) {
            std::string substr;
            std::getline(strStream, substr, ',');
            strList.push_back(substr);
        }
        return deserializeStep(strList);

    }

    TreeNode* deserializeStep(std::list<std::string> &strList) {
        if (strList.size() < 1) {
            return nullptr;
        }
        std::string strVal = strList.front();
        strList.pop_front();
        
        TreeNode* currNodePtr;
        if (strVal == "null") {
            return nullptr;
        } else {
            currNodePtr = new TreeNode(std::atoi(strVal.c_str()) );
            // std::cout << currNodePtr->val << std::endl;
        }
        currNodePtr->left = deserializeStep(strList);
        currNodePtr->right = deserializeStep(strList);
        return currNodePtr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

