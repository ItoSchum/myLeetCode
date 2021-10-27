/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (59.26%)
 * Likes:    3456
 * Dislikes: 188
 * Total Accepted:    975.7K
 * Total Submissions: 1.6M
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t, return true if t is an anagram of s, and false
 * otherwise.
 * 
 * 
 * Example 1:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length, t.length <= 5 * 10^4
 * s and t consist of lowercase English letters.
 * 
 * 
 * 
 * Follow up: What if the inputs contain Unicode characters? How would you
 * adapt your solution to such a case?
 * 
 */

// @lc code=start
#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        // if inconsistent string length
        if ( s.length() != t.length() ) {
            return false;
        }
        // otherwise, count frequency for all letters
        std::unordered_map<char, int> charToFreq;
        for (char letter : s) {
            charToFreq[letter] += 1;
        }
        for (char letter: t) {
            charToFreq[letter] -= 1;
            if (charToFreq[letter] < 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

