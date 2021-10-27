/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (38.98%)
 * Likes:    2557
 * Dislikes: 4442
 * Total Accepted:    1M
 * Total Submissions: 2.5M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string s, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "A man, a plan, a canal: Panama"
 * Output: true
 * Explanation: "amanaplanacanalpanama" is a palindrome.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "race a car"
 * Output: false
 * Explanation: "raceacar" is not a palindrome.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 2 * 10^5
 * s consists only of printable ASCII characters.
 * 
 * 
 */

// @lc code=start
#include <iostream>

class Solution {
public:
    bool isPalindrome(std::string s) {
        std::string filteredStr;
        for (char element : s) {
            if (std::isdigit(element) || std::isalpha(element) ) {
                filteredStr += std::tolower(element);
            }
        }
        int forwardIdx = 0;
        int backwardIdx = filteredStr.length() - 1;
        while (forwardIdx <= backwardIdx) {
            if (filteredStr[forwardIdx++] != filteredStr[backwardIdx--]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

