/*
 * @lc app=leetcode id=696 lang=javascript
 *
 * [696] Count Binary Substrings
 *
 * https://leetcode.com/problems/count-binary-substrings/description/
 *
 * algorithms
 * Easy (61.45%)
 * Likes:    2243
 * Dislikes: 412
 * Total Accepted:    107.9K
 * Total Submissions: 171K
 * Testcase Example:  '"00110011"'
 *
 * Give a binary string s, return the number of non-empty substrings that have
 * the same number of 0's and 1's, and all the 0's and all the 1's in these
 * substrings are grouped consecutively.
 * 
 * Substrings that occur multiple times are counted the number of times they
 * occur.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "00110011"
 * Output: 6
 * Explanation: There are 6 substrings that have equal number of consecutive
 * 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
 * Notice that some of these substrings repeat and are counted the number of
 * times they occur.
 * Also, "00110011" is not a valid substring because all the 0's (and 1's) are
 * not grouped together.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "10101"
 * Output: 4
 * Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal
 * number of consecutive 1's and 0's.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s[i] is either '0' or '1'.
 * 
 * 
 */

// @lc code=start
/**
 * @param {string} s
 * @return {number}
 */
let countBinarySubstrings = function(s) {
    let count = 0
    let preLen = 0
    let currLen = 1
    
    for (let i = 1; i < s.length; ++i) {
        if (s[i - 1] != s[i]) {
            count += Math.min(preLen, currLen)
            preLen = currLen
            currLen = 1
        } else {
            currLen += 1
        }
    }
    return count + Math.min(preLen, currLen)
};
// @lc code=end

