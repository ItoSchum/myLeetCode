/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (50.42%)
 * Likes:    3660
 * Dislikes: 81
 * Total Accepted:    503.2K
 * Total Submissions: 976.1K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers, nums, that might contain duplicates, return
 * all possible unique permutations in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,2]
 * Output:
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 8
 * -10 <= nums[i] <= 10
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int> > all_solutions;
        std::sort(nums.begin(), nums.end());
        subPermuteUnique(nums, 0, all_solutions);
        return all_solutions;
    }

private:
    void subPermuteUnique(std::vector<int>& nums, int begin_index,
                            std::vector<std::vector<int> >& all_solutions) {
        if (begin_index >= nums.size() ) {
            all_solutions.push_back(nums);
            return;
        }

        std::unordered_set<int> currentPosUsedNum;
        for (int i = begin_index; i < nums.size(); ++i) {
            // if (i > begin_index && (nums[i] == nums[begin_index] || nums[i] == nums[i - 1]) ) { 
            //     continue; 
            // }
            if (currentPosUsedNum.find(nums[i]) != currentPosUsedNum.end()) {
                continue;
            }
            currentPosUsedNum.insert(nums[i]);
            std::swap(nums[i], nums[begin_index]);
            subPermuteUnique(nums, begin_index + 1, all_solutions);
            std::swap(nums[i], nums[begin_index]);
        }
    }
};
// @lc code=end

