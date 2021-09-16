/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (67.85%)
 * Likes:    7433
 * Dislikes: 148
 * Total Accepted:    916K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an array nums of distinct integers, return all the possible
 * permutations. You can return the answer in any order.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * Example 2:
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 * Example 3:
 * Input: nums = [1]
 * Output: [[1]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * All the integers of nums are unique.
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int> > all_solutions;
        subPermute(nums, 0, all_solutions);
        return all_solutions;
    }

private:
    void subPermute(std::vector<int>& nums, int begin_index, 
            std::vector<std::vector<int> >& all_solutions) {
        
        if (begin_index >= nums.size()) {
            all_solutions.push_back(nums);
            printSolution(nums);
            return;
        }
        // Iterate all rest numbers
        for (int i = begin_index; i < nums.size(); ++i) {
            std::swap(nums[i], nums[begin_index]);
            subPermute(nums, begin_index + 1, all_solutions);
            std::swap(nums[i], nums[begin_index]);
        }
    }

    void printSolution(const std::vector<int>& solution) {
        std::vector<int>::const_iterator itr;
        printf("Current solutoin: ");
        for (itr = solution.begin(); itr != solution.end(); ++itr) {
            printf("%d ", *itr);
        }
        printf("\n");
    }
};
// @lc code=end

// n = number amount
// Time: O(n)
// Space: O(n)

