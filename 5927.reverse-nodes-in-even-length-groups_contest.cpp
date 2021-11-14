// 5927. Reverse Nodes in Even Length Groups
//
// User Accepted:14
// User Tried:20
// Total Accepted:14
// Total Submissions:25
// Difficulty:Medium
// You are given the head of a linked list.

// The nodes in the linked list are sequentially assigned to non-empty groups whose lengths form the sequence of the natural numbers (1, 2, 3, 4, ...). The length of a group is the number of nodes assigned to it. In other words,

// The 1st node is assigned to the first group.
// The 2nd and the 3rd nodes are assigned to the second group.
// The 4th, 5th, and 6th nodes are assigned to the third group, and so on.
// Note that the length of the last group may be less than or equal to 1 + the length of the second to last group.

// Reverse the nodes in each group with an even length, and return the head of the modified linked list.

// Example 1:

// Input: head = [5,2,6,3,9,1,7,3,8,4]
// Output: [5,6,2,3,9,1,4,8,3,7]
// Explanation:
// - The length of the first group is 1, which is odd, hence no reversal occurrs.
// - The length of the second group is 2, which is even, hence the nodes are reversed.
// - The length of the third group is 3, which is odd, hence no reversal occurrs.
// - The length of the last group is 4, which is even, hence the nodes are reversed.


// Example 2:

// Input: head = [1,1,0,6]
// Output: [1,0,1,6]
// Explanation:
// - The length of the first group is 1. No reversal occurrs.
// - The length of the second group is 2. The nodes are reversed.
// - The length of the last group is 1. No reversal occurrs.


// Example 3:

// Input: head = [2,1]
// Output: [2,1]
// Explanation:
// - The length of the first group is 1. No reversal occurrs.
// - The length of the last group is 1. No reversal occurrs.


// Example 4:

// Input: head = [8]
// Output: [8]
// Explanation: There is only one group whose length is 1. No reversal occurrs.


// Constraints:

// The number of nodes in the list is in the range [1, 105].
// 0 <= Node.val <= 105

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>

class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        reverseKGroup(head, 1);
        return head;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        }
        ListNode* left = head;
        ListNode* right = head;
        ListNode* prevRight = head;
        
        int actualLen = 0;
        // find out the start & end node
        for (int i = 0; i < k; ++i) {
            if (right == nullptr) { break; }
            prevRight = right;
            right = right->next;
            actualLen += 1;
        }
        
        ListNode* nextHead;
        // reverse partial list if even-length list
        if ( (actualLen & 1) == 0) {
            nextHead = reverseList(left, right);
            left->next = reverseKGroup(right, k + 1);
        } else {
            nextHead = left;
            prevRight->next = reverseKGroup(right, k + 1);
        }
        return nextHead;
    }
    
    ListNode* reverseList(ListNode* head, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* oldNext = head;
        
        while (curr != end) {
            oldNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = oldNext;
        }
        return prev;
    }
};