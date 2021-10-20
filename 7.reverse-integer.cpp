/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (26.04%)
 * Likes:    5822
 * Dislikes: 8687
 * Total Accepted:    1.8M
 * Total Submissions: 6.9M
 * Testcase Example:  '123'
 *
 * Given a signed 32-bit integer x, return x with its digits reversed. If
 * reversing x causes the value to go outside the signed 32-bit integer range
 * [-2^31, 2^31 - 1], then return 0.
 * 
 * Assume the environment does not allow you to store 64-bit integers (signed
 * or unsigned).
 * 
 * 
 * Example 1:
 * Input: x = 123
 * Output: 321
 * Example 2:
 * Input: x = -123
 * Output: -321
 * Example 3:
 * Input: x = 120
 * Output: 21
 * Example 4:
 * Input: x = 0
 * Output: 0
 * 
 * 
 * Constraints:
 * 
 * 
 * -2^31 <= x <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
#include <iostream>

class Solution {
public:
    int reverse(int x) {
        long reversed_x = 0;
        int negativeCheck = 1;
        
        while (x != 0) {
            reversed_x = reversed_x * 10 + x % 10;
            x /= 10;
        }
        reversed_x *= negativeCheck;
        if (reversed_x < INT32_MIN || reversed_x > INT32_MAX) {
            return 0;
        }
        return reversed_x;
    }
};

// @lc code=end
// n = input number
// Time: O( log10(n) )
// Space: O( 1 )
