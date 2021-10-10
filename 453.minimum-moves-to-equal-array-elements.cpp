/*
 * @lc app=leetcode id=453 lang=cpp
 *
 * [453] Minimum Moves to Equal Array Elements
 *
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/
 *
 * algorithms
 * Easy (51.52%)
 * Likes:    1097
 * Dislikes: 1403
 * Total Accepted:    105.9K
 * Total Submissions: 202K
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums of size n, return the minimum number of moves
 * required to make all array elements equal.
 * 
 * In one move, you can increment n - 1 elements of the array by 1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: 3
 * Explanation: Only three moves are needed (remember each move increments two
 * elements):
 * [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,1,1]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * The answer is guaranteed to fit in a 32-bit integer.
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>

class Solution {
public:
    int minMoves(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end() );
        int moveSteps = 0;
        for (unsigned int i = 0; i < nums.size(); ++i) {
            moveSteps += nums[i] - nums[0];
        }
        return moveSteps;
    }
};
// @lc code=end

// n = size of nums
// Time: O( nlog(n) )
// Space: O(1)

