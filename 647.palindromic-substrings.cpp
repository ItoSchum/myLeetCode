/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (62.92%)
 * Likes:    5190
 * Dislikes: 144
 * Total Accepted:    329.8K
 * Total Submissions: 519.1K
 * Testcase Example:  '"abc"'
 *
 * Given a string s, return the number of palindromic substrings in it.
 * 
 * A string is a palindrome when it reads the same backward as forward.
 * 
 * A substring is a contiguous sequence of characters within the string.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * s consists of lowercase English letters.
 * 
 * 
 */

// @lc code=start
#include <iostream>

class Solution {
public:
    int countSubstrings(std::string s) {
        int palindromeCount = 0;
        for (unsigned int i = 0; i < s.size(); ++i) {
            int left = i, right = i;
            while (left >= 0 && right < s.size() && s[left--] == s[right++]) {
                palindromeCount++;
            }

            left = i - 1, right = i;
            while (left >= 0 && right < s.size() && s[left--] == s[right++]) {
                palindromeCount++;
                }
            }
        }
        return palindromeCount;
    }
};
// @lc code=end

