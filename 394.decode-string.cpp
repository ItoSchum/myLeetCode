/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (53.50%)
 * Likes:    6126
 * Dislikes: 269
 * Total Accepted:    385.9K
 * Total Submissions: 707.3K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 * 
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 * 
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 * 
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 * 
 * 
 * Example 1:
 * Input: s = "3[a]2[bc]"
 * Output: "aaabcbc"
 * Example 2:
 * Input: s = "3[a2[c]]"
 * Output: "accaccacc"
 * Example 3:
 * Input: s = "2[abc]3[cd]ef"
 * Output: "abcabccdcdcdef"
 * Example 4:
 * Input: s = "abc3[cd]xyz"
 * Output: "abccdcdcdxyz"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 30
 * s consists of lowercase English letters, digits, and square brackets
 * '[]'.
 * s is guaranteed to be a valid input.
 * All the integers in s are in the range [1, 300].
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string decodeString(std::string s) {
        int currIndex = 0;
        return decodeSubstring(s, currIndex);
    }

    std::string decodeSubstring(const std::string& inputStr, int& currIndex) {
        std::string decodedStr = "";

        while (currIndex < inputStr.size() && inputStr[currIndex] != ']' ) {
            // If normal letters
            if ( !std::isdigit(inputStr[currIndex]) ) {
                decodedStr.push_back(inputStr[currIndex]);
                currIndex++;
            }
            // If digits
            else {
                int dupCount = 0;
                while (currIndex < inputStr.size() && std::isdigit(inputStr[currIndex]) ) {
                    dupCount = dupCount * 10 + (inputStr[currIndex] - '0');
                    currIndex++;
                }
                // ignore the opening bracket
                currIndex++;
                // duplicate substring
                std::string decodedSubstr = decodeSubstring(inputStr, currIndex);
                // ignore the ending bracket
                currIndex++;
                while (dupCount > 0) {
                    decodedStr.append(decodedSubstr);
                    dupCount--;
                }
            }
        }
        return decodedStr;
    }
    
};
// @lc code=end

// n = string length
// K = duplicate number
// Time: O( max(K) * n )
// Space: O( n )
