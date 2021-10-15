/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (42.34%)
 * Likes:    1656
 * Dislikes: 208
 * Total Accepted:    304K
 * Total Submissions: 713.8K
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 * 
 * Follow up: Do not use any built-in library function such as sqrt.
 * 
 * 
 * Example 1:
 * Input: num = 16
 * Output: true
 * Example 2:
 * Input: num = 14
 * Output: false
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= num <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        unsigned int lo = 0;
        unsigned int hi = num;
        
        unsigned int mid;
        double currSqVal;
        double doubleNum = num;
        
        while (lo <= hi) {
            mid = (lo + hi) / 2;    
            currSqVal = (double) mid * mid; 
            // cout << "lo = " << lo << " ";
            // cout << "hi = " << hi << " ";
            // cout << "mid = " << mid << " ";
            // cout << "currSqVal = " << currSqVal << "\n";
            
            if (currSqVal == num) { 
                return true; 
            }
            if (currSqVal > num) {
                hi = mid - 1;
            }
            if (currSqVal < num) {
                lo = mid + 1;
            }
        }
        return false;
    }
};
// @lc code=end

