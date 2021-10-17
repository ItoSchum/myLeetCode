/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 *
 * https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/
 *
 * algorithms
 * Medium (57.17%)
 * Likes:    2749
 * Dislikes: 208
 * Total Accepted:    183.8K
 * Total Submissions: 318.5K
 * Testcase Example:  '[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]'
 *
 * You are given a doubly linked list which in addition to the next and
 * previous pointers, it could have a child pointer, which may or may not point
 * to a separate doubly linked list. These child lists may have one or more
 * children of their own, and so on, to produce a multilevel data structure, as
 * shown in the example below.
 * 
 * Flatten the list so that all the nodes appear in a single-level, doubly
 * linked list. You are given the head of the first level of the list.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
 * Output: [1,2,3,7,8,11,12,9,10,4,5,6]
 * Explanation:
 * 
 * The multilevel linked list in the input is as follows:
 * 
 * 
 * 
 * After flattening the multilevel linked list it becomes:
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2,null,3]
 * Output: [1,3,2]
 * Explanation:
 * 
 * The input multilevel linked list is as follows:
 * 
 * ⁠ 1---2---NULL
 * ⁠ |
 * ⁠ 3---NULL
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = []
 * Output: []
 * 
 * 
 * 
 * 
 * How multilevel linked list is represented in test case:
 * 
 * We use the multilevel linked list from Example 1 above:
 * 
 * 
 * ⁠1---2---3---4---5---6--NULL
 * ⁠        |
 * ⁠        7---8---9---10--NULL
 * ⁠            |
 * ⁠            11--12--NULL
 * 
 * The serialization of each level is as follows:
 * 
 * 
 * [1,2,3,4,5,6,null]
 * [7,8,9,10,null]
 * [11,12,null]
 * 
 * 
 * To serialize all levels together we will add nulls in each level to signify
 * no node connects to the upper node of the previous level. The serialization
 * becomes:
 * 
 * 
 * [1,2,3,4,5,6,null]
 * [null,null,7,8,9,10,null]
 * [null,11,12,null]
 * 
 * 
 * Merging the serialization of each level and removing trailing nulls we
 * obtain:
 * 
 * 
 * [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of Nodes will not exceed 1000.
 * 1 <= Node.val <= 10^5
 * 
 * 
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

// class Node {
// public:
//     int val;
//     Node* prev;
//     Node* next;
//     Node* child;
// };

class Solution {
public:
    Node* flatten(Node* head) {
        // Check head
        if (head == nullptr) {
            return nullptr;
        }
        Node* pseudoHead = new Node();
        dfsFlatten(pseudoHead, head);
        head->prev = nullptr;
        return head;
    }
    
    // Solution 1
    Node* dfsFlatten(Node* prevNode, Node* currNode) {
        if (currNode == nullptr) {
            return prevNode;
        }
        prevNode->next = currNode;
        currNode->prev = prevNode;
        
        Node* oldNext = currNode->next;
        Node* newNextTail = dfsFlatten(currNode, currNode->child);
        currNode->child = nullptr;

        return dfsFlatten(newNextTail, oldNext);
    }

    // Solution 2
    Node* dfsFlatten(Node* head) {
        // If no child node, forward with next node
        if (head->child == nullptr) {
            if (head->next != nullptr) {
                return dfsFlatten(head->next);
            } else {
                return head;  
            }
        } 
        // If no next node, forward with child node
        if (head->next == nullptr) {
            head->next = head->child;
            if (head->child != nullptr) {
                head->child->prev = head;
                head->child = nullptr;
                return dfsFlatten(head->next);
            } else {
                return head;  
            }
        }
        
        // If both of next & child node exist
        Node* oldChild = head->child;
        Node* oldNext = head->next;
        Node* newNextTail = dfsFlatten(head->child);
        
        // Modify original child node
        oldChild->prev = head;
        head->next = oldChild;
        head->child = nullptr;
        
        // Modify original next node
        oldNext->prev = newNextTail;
        newNextTail->next = oldNext;
        
        return dfsFlatten(oldNext);
    }
};
// @lc code=end

// n = node number
// Time: O(n)
// Space: O(1)

