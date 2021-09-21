/*
 * @lc app=leetcode id=611 lang=cpp
 *
 * [611] Valid Triangle Number
 *
 * https://leetcode.com/problems/valid-triangle-number/description/
 *
 * algorithms
 * Medium (49.72%)
 * Likes:    2057
 * Dislikes: 134
 * Total Accepted:    119.1K
 * Total Submissions: 242.4K
 * Testcase Example:  '[2,2,3,4]'
 *
 * Given an integer array nums, return the number of triplets chosen from the
 * array that can make triangles if we take them as side lengths of a
 * triangle.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,2,3,4]
 * Output: 3
 * Explanation: Valid combinations are: 
 * 2,3,4 (using the first 2)
 * 2,3,4 (using the second 2)
 * 2,2,3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,2,3,4]
 * Output: 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] <= 1000
 * 
 * 
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // If not enough nums
        if (nums.size() < 3) {
            return 0;
        }
        // Sort the nums for selecting
        std::sort(nums.begin(), nums.end());
        // Scan the nums
        int validCount = 0;
        for (int i = 0; i < nums.size() - 2; ++i) {
            int k = i + 2;
            for (int j = i + 1; nums[i] > 0 && j < nums.size() - 1; ++j) {
                while (k < nums.size() && nums[i] + nums[j] > nums[k]) { 
                    k++;
                }
                validCount += k - j - 1;
            }
        }
        return validCount;
    }
};
// @lc code=end

// n = size of nums
// Time: O(n^2)
// Space: O(log2(n)) // for sorting
