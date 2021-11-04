/*
 * @lc app=leetcode id=1209 lang=cpp
 *
 * [1209] Remove All Adjacent Duplicates in String II
 *
 * https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/
 *
 * algorithms
 * Medium (57.16%)
 * Likes:    1638
 * Dislikes: 35
 * Total Accepted:    103K
 * Total Submissions: 180.3K
 * Testcase Example:  '"abcd"\n2'
 *
 * You are given a string s and an integer k, a k duplicate removal consists of
 * choosing k adjacent and equal letters from s and removing them, causing the
 * left and the right side of the deleted substring to concatenate together.
 * 
 * We repeatedly make k duplicate removals on s until we no longer can.
 * 
 * Return the final string after all such duplicate removals have been made. It
 * is guaranteed that the answer is unique.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abcd", k = 2
 * Output: "abcd"
 * Explanation: There's nothing to delete.
 * 
 * Example 2:
 * 
 * 
 * Input: s = "deeedbbcccbdaa", k = 3
 * Output: "aa"
 * Explanation: 
 * First delete "eee" and "ccc", get "ddbbbdaa"
 * Then delete "bbb", get "dddaa"
 * Finally delete "ddd", get "aa"
 * 
 * Example 3:
 * 
 * 
 * Input: s = "pbbcggttciiippooaais", k = 2
 * Output: "ps"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * 2 <= k <= 10^4
 * s only contains lower case English letters.
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>

class Solution {
public:
    std::string removeDuplicates(std::string s, int k) {
        std::vector<int> sameCount(s.size(), 1);
        for (unsigned int i = 1; i < s.size(); ++i) {
            // Not same adjacent
            if (i == 0 || s[i - 1] != s[i]) {
                sameCount[i] = 1;
            }  // Same adjacent
            else {
                sameCount[i] = sameCount[i - 1] + 1;
                // Check if reached the threshold
                if (sameCount[i] == k) {
                    s.erase(i - k + 1, k);
                    i -= k;
                }
            }
        }
        return s;
    }
};
// @lc code=end

// n = string length
// Time: O(n)
// Space: O(n)

