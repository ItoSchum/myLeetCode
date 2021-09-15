/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (31.27%)
 * Likes:    3003
 * Dislikes: 4256
 * Total Accepted:    705.6K
 * Total Submissions: 2.2M
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (i.e.,
 * x^n).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: x = 2.00000, n = 10
 * Output: 1024.00000
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: x = 2.10000, n = 3
 * Output: 9.26100
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: x = 2.00000, n = -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -100.0 < x < 100.0
 * -2^31 <= n <= 2^31-1
 * -10^4 <= x^n <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        
        int n_copy = n;
        double result = 1.0;

        while (n != 0) {
            // if has remainder when devided by 2
            if (n & 1 == 1) {
                result *= x;
            } 
            x *= x;
            n /= 2;
        }
        if (n_copy < 0) {
            result = 1 / result;
        }
        return result;
    }
};
// @lc code=end

// n = given n (in x^n)
// Time: O( log2(n) )
// Space: O(1)