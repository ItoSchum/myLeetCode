/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 *
 * https://leetcode.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (37.28%)
 * Likes:    3410
 * Dislikes: 210
 * Total Accepted:    337.2K
 * Total Submissions: 889.5K
 * Testcase Example:  '"aba"'
 *
 * Given a string s, return true if the s can be palindrome after deleting at
 * most one character from it.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "aba"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "abca"
 * Output: true
 * Explanation: You could delete the character 'c'.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "abc"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s consists of lowercase English letters.
 * 
 * 
 */

// @lc code=start
#include <iostream>

class Solution {
public:
    bool validPalindrome(std::string s) {
        return stepValidPalindrome(s, 0, s.length() - 1);
    }
    
    bool stepValidPalindrome(const std::string& s, int startIdx, int endIdx) {
        while (startIdx <= endIdx) {
            // if no inconsistent char
            if (s[startIdx] == s[endIdx]) {
                startIdx += 1;
                endIdx -= 1;
                continue;
            }
            // othereise, check if already found different char
            if (foundOneNoiseChar == true) {
                return false; 
            } else {
                this->foundOneNoiseChar = true;
                return stepValidPalindrome(s, startIdx + 1, endIdx) || stepValidPalindrome(s, startIdx, endIdx - 1);
            }
        }
        return true;
    }

private:
    bool foundOneNoiseChar = false;
};
// @lc code=end

