/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 *
 * https://leetcode.com/problems/next-greater-element-i/description/
 *
 * algorithms
 * Easy (66.35%)
 * Likes:    532
 * Dislikes: 36
 * Total Accepted:    246.1K
 * Total Submissions: 366.5K
 * Testcase Example:  '[4,1,2]\n[1,3,4,2]'
 *
 * The next greater element of some element x in an array is the first greater
 * element that is to the right of x in the same array.
 * 
 * You are given two distinct 0-indexed integer arrays nums1 and nums2, where
 * nums1 is a subset of nums2.
 * 
 * For each 0 <= i < nums1.length, find the index j such that nums1[i] ==
 * nums2[j] and determine the next greater element of nums2[j] in nums2. If
 * there is no next greater element, then the answer for this query is -1.
 * 
 * Return an array ans of length nums1.length such that ans[i] is the next
 * greater element as described above.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
 * Output: [-1,3,-1]
 * Explanation: The next greater element for each value of nums1 is as follows:
 * - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so
 * the answer is -1.
 * - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
 * - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so
 * the answer is -1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [2,4], nums2 = [1,2,3,4]
 * Output: [3,-1]
 * Explanation: The next greater element for each value of nums1 is as follows:
 * - 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
 * - 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so
 * the answer is -1.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums1.length <= nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 10^4
 * All integers in nums1 and nums2 are unique.
 * All the integers of nums1 also appear in nums2.
 * 
 * 
 * 
 * Follow up: Could you find an O(nums1.length + nums2.length) solution?
 */

// @lc code=start
#include <stack>
#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        // std::stack<int> currNumStack;
        // std::unordered_map<int, int> valToGreaterVal;

        // for (int i = 0; i < nums2.size(); ++i) {
        //     while (!currNumStack.empty() && currNumStack.top() < nums2[i]) {
        //         valToGreaterVal[currNumStack.top()] = nums2[i];
        //         currNumStack.pop();
        //     }
        //     currNumStack.push(nums2[i]);
        // }
        // while (!currNumStack.empty()) {
        //     valToGreaterVal[currNumStack.top()] = -1;
        //     currNumStack.pop();
        // }

        // std::vector<int> selectedGreaterNums;
        // for (int i = 0; i < nums1.size(); ++i) {
        //     // selectedGreaterNums.push_back(valToGreaterVal.count(nums1[i])? valToGreaterVal[nums1[i]] : -1);
        //     selectedGreaterNums.push_back(valToGreaterVal[nums1[i]]);
        // }
        // return selectedGreaterNums;

        std::vector<int> greaterNums(nums2.size());
        std::stack<int> candidates;
        std::unordered_map<int, int> valToGreaterVal;
        for (int i = nums2.size() - 1; i >= 0; --i) {
            while (!candidates.empty() && candidates.top() <= nums2[i]) {
                candidates.pop();
            }
            greaterNums[i] = !candidates.empty()? candidates.top() : -1;
            valToGreaterVal[nums2[i]] = greaterNums[i];
            candidates.push(nums2[i]);
        }

        std::vector<int> selectedGreaterNums;
        for (int i = 0; i < nums1.size(); ++i) {
            selectedGreaterNums.push_back(valToGreaterVal[nums1[i]]);
        }
        return selectedGreaterNums;
    }
};
// @lc code=end
// n = number amount
// Time: O(n)
// Space: O(n)

