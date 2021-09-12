/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (40.17%)
 * Likes:    8925
 * Dislikes: 351
 * Total Accepted:    1.6M
 * Total Submissions: 4M
 * Testcase Example:  '"()"'
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: s = "{[]}"
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^4
 * s consists of parentheses only '()[]{}'.
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <stack>
#include <unordered_map>

class Solution {
public:
    Solution() {
        bracketLtoR['('] = ')';
        bracketLtoR['['] = ']';
        bracketLtoR['{'] = '}';
    }
    
    bool isValid(string s) {
        
        // if string length == 0 -> valid
        if (s.size() == 0) { return true; }
        // If string length is odd -> invalid
        if ( (s.size() & 1) == 1) { return false; }
        
        // Using stack
        // std::stack<char> parenthesisStack;
        // for (int i = 0; i < s.size(); ++i) {
        //     if (!parenthesisStack.empty()
        //            && bracketLtoR.find(parenthesisStack.top()) != bracketLtoR.end()
        //            && bracketLtoR[parenthesisStack.top()] == s[i]) {
        //         parenthesisStack.pop();
        //     } else {
        //         parenthesisStack.push(s[i]);
        //     }
        // }
        // if (parenthesisStack.empty()) {
        //     return true;
        // }
        // return false;

        // Not using stack
        return check(s, s.size());

    }

    bool check(std::string substr, int substrLen) {
        
        // if string length == 0 -> valid
        if (substrLen == 0) { return true; }
        // If string length is odd -> invalid
        if ( (substrLen & 1) == 1) { return false; }
        // If ) or ] or } at the first position -> invalid
        if (bracketLtoR.find( substr[0] ) == bracketLtoR.end()) {
            return false;
        }

        int currPos = 1;
        int sameOpeningCount = 0;

        // Handle the same opening brackets e.g. ((( )))
        for (int currPos = 0; currPos < substrLen; ++currPos) {
            if (substr[currPos] == substr[0]) { sameOpeningCount++; }
            if (substr[currPos] == bracketLtoR[ substr[0] ]) {
                // Found the closing bracket for substr[0] 
                if (sameOpeningCount == 0) { break; }
                // Found the closing bracket for some inner bracket
                else { sameOpeningCount--; }
            }
        }
        // If reahced out of the range (consider it should have did the 'break' OP)
        // -> closing bracket not found
        if (currPos == substrLen) { return false; }
        
        // If no gap between substr[currPos] and substr[0]
        // keep checking
        if (currPos == 1) {
            return check(&substr[2], substrLen - 2);
        } else {
            return check(&substr[currPos - 1], currPos - 1) 
                && check(&substr[currPos + 1], substrLen - currPos - 1);
        }

    }

private:
    std::unordered_map<char, char> bracketLtoR;

    void printStack(std::stack<char> stackToPrint) {
        while (!stackToPrint.empty()) {
            std::cout << stackToPrint.top() << std::endl;
            stackToPrint.pop();
        }
    }
};
// @lc code=end
// n = parenthesis number
// Time: O(n)
// Space: O(n/2)

