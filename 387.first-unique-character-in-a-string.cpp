/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (54.41%)
 * Likes:    3788
 * Dislikes: 168
 * Total Accepted:    864.6K
 * Total Submissions: 1.6M
 * Testcase Example:  '"leetcode"'
 *
 * Given a string s, find the first non-repeating character in it and return
 * its index. If it does not exist, return -1.
 * 
 * 
 * Example 1:
 * Input: s = "leetcode"
 * Output: 0
 * Example 2:
 * Input: s = "loveleetcode"
 * Output: 2
 * Example 3:
 * Input: s = "aabb"
 * Output: -1
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s consists of only lowercase English letters.
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <unordered_map>

class Solution {
public:
    int firstUniqChar(std::string s) {
        std::unordered_map<char, int> charToFreq;
        // count frequency of each letter
        for (unsigned int i = 0; i < s.size(); ++i) {
            charToFreq[ s[i] ] += 1;
        }
        // iterate the string by index
        for (unsigned int i = 0; i < s.size(); ++i) {
            char letter = s[i];
            if (charToFreq[letter] == 1) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

