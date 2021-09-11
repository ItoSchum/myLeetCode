/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (48.11%)
 * Likes:    14301
 * Dislikes: 676
 * Total Accepted:    1.6M
 * Total Submissions: 3.4M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * A subarray is a contiguous part of an array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1]
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [5,4,-1,7,8]
 * Output: 23
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 3 * 10^4
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 * 
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution using the divide and conquer approach, which is more subtle.
 * 
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int localMax = 0;
        int globalMax = *std::max_element(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            localMax += nums[i];
            // Accumulate the nums only when the current localMax >= 0
            if (localMax >= 0) {
                globalMax = std::max(globalMax, localMax);
            // reset the localMax, for searching next positive localMax
            } else {
                localMax = 0;
            }
        }
        
        // ALTERNATIVE:
        // for (int i = 0; i < nums.size(); ++i) {
        //     localMax = std::max(nums[i], nums[i] + localMax);
        //     globalMax = std::max(localMax, globalMax);
        // }
        return globalMax;
    }
};
// @lc code=end

// n = number amount
// Time: O(n)
// Space: O(1)

// Accepted
// 203/203 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 11.68 % of cpp submissions (13.3 MB)
