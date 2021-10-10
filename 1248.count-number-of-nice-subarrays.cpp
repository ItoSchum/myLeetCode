/*
 * @lc app=leetcode id=1248 lang=cpp
 *
 * [1248] Count Number of Nice Subarrays
 *
 * https://leetcode.com/problems/count-number-of-nice-subarrays/description/
 *
 * algorithms
 * Medium (56.50%)
 * Likes:    1248
 * Dislikes: 29
 * Total Accepted:    39.6K
 * Total Submissions: 68.9K
 * Testcase Example:  '[1,1,2,1,1]\n3'
 *
 * Given an array of integers nums and an integer k. A continuous subarray is
 * called nice if there are k odd numbers on it.
 * 
 * Return the number of nice sub-arrays.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,2,1,1], k = 3
 * Output: 2
 * Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and
 * [1,2,1,1].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,4,6], k = 1
 * Output: 0
 * Explanation: There is no odd numbers in the array.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
 * Output: 16
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 50000
 * 1 <= nums[i] <= 10^5
 * 1 <= k <= nums.length
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>

class Solution {
public:
    int atMostKOdd(std::vector<int>& nums, int k) {
        int left = 0, right = 0;
        int currOddCount = 0;
        int validSubstrCount = 0;
        
        for (right = 0; right < nums.size(); ++right) {
            if (nums[right] & 1 == 1) { 
                currOddCount++; 
            }
            while (currOddCount > k && left <= right) {
                if (nums[left] & 1 == 1) { currOddCount--; }
                left++;
            }
            if (currOddCount <= k) {
                validSubstrCount += right - left + 1;
            }
        }
        return validSubstrCount;
    }
    
    int numberOfSubarrays(std::vector<int>& nums, int k) {
        return atMostKOdd(nums, k) - atMostKOdd(nums, k - 1);
    }
};
// @lc code=end

// exactly(K) = atMost(K) - atMost(K-1)
// n = size of nums
// Time: O()
// Space: O()


