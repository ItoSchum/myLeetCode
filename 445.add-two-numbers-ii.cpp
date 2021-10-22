/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (56.92%)
 * Likes:    2876
 * Dislikes: 218
 * Total Accepted:    273.6K
 * Total Submissions: 474.2K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: l1 = [7,2,4,3], l2 = [5,6,4]
 * Output: [7,8,0,7]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [8,0,7]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have
 * leading zeros.
 * 
 * 
 * 
 * Follow up: Could you solve it without reversing the input lists?
 * 
 */

// @lc code=start
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
#include <vector>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // reverse list
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        
        // Add up
        ListNode* sumListHead = nullptr;
        int carry = 0;
        int digit = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int val1 = 0;
            int val2 = 0;
            val1 = (l1 == nullptr) ? 0 : l1->val;
            val2 = (l2 == nullptr) ? 0 : l2->val;

            digit = (carry + val1 + val2) % 10;
            carry = (carry + val1 + val2) / 10;

            ListNode* curr = new ListNode(digit);
            curr->next = sumListHead;
            sumListHead = curr;

            if (l1 != nullptr) { l1 = l1->next; }
            if (l2 != nullptr) { l2 = l2->next; }
        }

        if (carry != 0) {
            ListNode* curr = new ListNode(carry);
            curr->next = sumListHead;
            sumListHead = curr;
        }
        return sumListHead;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* tail = nullptr;
        while (head != nullptr) {
            ListNode* oldNext = head->next;
            head->next = tail;
            tail = head;
            head = oldNext;
        }
        return tail;
    }
};
// @lc code=end
// n1 = first list length
// n2 = second list length
// Time: O(n1 + n2)
// Space: O(1)
