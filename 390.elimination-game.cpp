/*
 * @lc app=leetcode id=390 lang=cpp
 *
 * [390] Elimination Game
 *
 * https://leetcode.com/problems/elimination-game/description/
 *
 * algorithms
 * Medium (45.55%)
 * Likes:    672
 * Dislikes: 462
 * Total Accepted:    41.9K
 * Total Submissions: 91.2K
 * Testcase Example:  '9'
 *
 * You have a list arr of all integers in the range [1, n] sorted in a strictly
 * increasing order. Apply the following algorithm on arr:
 * 
 * 
 * Starting from left to right, remove the first number and every other number
 * afterward until you reach the end of the list.
 * Repeat the previous step again, but this time from right to left, remove the
 * rightmost number and every other number from the remaining numbers.
 * Keep repeating the steps again, alternating left to right and right to left,
 * until a single number remains.
 * 
 * 
 * Given the integer n, return the last number that remains in arr.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 9
 * Output: 6
 * Explanation:
 * arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
 * arr = [2, 4, 6, 8]
 * arr = [2, 6]
 * arr = [6]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int lastRemaining(int n) {
        int head = 1;
        int step = 1;
        bool leftToRight = true;
        
        while (n > 1) {
            if (leftToRight == true)  {
                head += step;
                leftToRight = false;
            } else {
                // When odd number of numbers remains, the original head was removed
                if (n & 1 == 1) { head += step; }
                leftToRight = true;
            }
            // n divided by 2
            n >>= 1;
            // step doubled
            step <<= 1;
        }
        return head;
    }
};
// @lc code=end

// n = number of numbers
// Time: O( log(n) )
// Space: O(1)

