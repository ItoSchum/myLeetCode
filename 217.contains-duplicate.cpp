/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (57.43%)
 * Likes:    2276
 * Dislikes: 875
 * Total Accepted:    941.5K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,2,3,1]'
 *
 * Given an integer array nums, return true if any value appears at least twice
 * in the array, and return false if every element is distinct.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,3,1]
 * Output: true
 * Example 2:
 * Input: nums = [1,2,3,4]
 * Output: false
 * Example 3:
 * Input: nums = [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> existing_nums;
        for (int i = 0; i < nums.size(); ++i) {
            if (existing_nums.count(nums[i]) != 0) { 
                return true; 
            }
            existing_nums[nums[i]] = 1; 
        }
        return false;
    }
};
// @lc code=end

