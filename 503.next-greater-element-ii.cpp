/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 *
 * https://leetcode.com/problems/next-greater-element-ii/description/
 *
 * algorithms
 * Medium (59.23%)
 * Likes:    3163
 * Dislikes: 108
 * Total Accepted:    161.2K
 * Total Submissions: 268.4K
 * Testcase Example:  '[1,2,1]'
 *
 * Given a circular integer array nums (i.e., the next element of
 * nums[nums.length - 1] is nums[0]), return the next greater number for every
 * element in nums.
 * 
 * The next greater number of a number x is the first greater number to its
 * traversing-order next in the array, which means you could search circularly
 * to find its next greater number. If it doesn't exist, return -1 for this
 * number.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,1]
 * Output: [2,-1,2]
 * Explanation: The first 1's next greater number is 2; 
 * The number 2 can't find next greater number. 
 * The second 1's next greater number needs to search circularly, which is also
 * 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3,4,3]
 * Output: [2,3,4,-1,4]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <stack>

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        std::vector<int> greaterNums(nums.size());
        std::stack<int> candidates;

        for (int i = nums.size() * 2 - 1; i >= 0; --i) {
            int actualIndex = i % nums.size();
            while (!candidates.empty() && candidates.top() <= nums[actualIndex]) {
                candidates.pop();
            }
            // printStack(candidates);
            // std::cout << "--------" << std::endl;
            greaterNums[actualIndex] = candidates.empty()? -1 : candidates.top();
            candidates.push(nums[actualIndex]);
        }
        return greaterNums;
    }

    // void printStack(std::stack<int> numStack) {
    //     while(!numStack.empty()) {
    //         int topNum = numStack.top();
    //         numStack.pop();
    //         printStack(numStack);
    //         std::cout << topNum << std::endl;
    //     }
    // }
};
// @lc code=end

// n = number amount
// Time: O(n)
// Space: O(n)