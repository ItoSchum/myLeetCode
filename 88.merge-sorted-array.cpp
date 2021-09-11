/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (41.12%)
 * Likes:    1182
 * Dislikes: 135
 * Total Accepted:    1M
 * Total Submissions: 2.4M
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * You are given two integer arrays nums1 and nums2, sorted in non-decreasing
 * order, and two integers m and n, representing the number of elements in
 * nums1 and nums2 respectively.
 * 
 * Merge nums1 and nums2 into a single array sorted in non-decreasing order.
 * 
 * The final sorted array should not be returned by the function, but instead
 * be stored inside the array nums1. To accommodate this, nums1 has a length of
 * m + n, where the first m elements denote the elements that should be merged,
 * and the last n elements are set to 0 and should be ignored. nums2 has a
 * length of n.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 * Output: [1,2,2,3,5,6]
 * Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
 * The result of the merge is [1,2,2,3,5,6] with the underlined elements coming
 * from nums1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [1], m = 1, nums2 = [], n = 0
 * Output: [1]
 * Explanation: The arrays we are merging are [1] and [].
 * The result of the merge is [1].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums1 = [0], m = 0, nums2 = [1], n = 1
 * Output: [1]
 * Explanation: The arrays we are merging are [] and [1].
 * The result of the merge is [1].
 * Note that because m = 0, there are no elements in nums1. The 0 is only there
 * to ensure the merge result can fit in nums1.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * nums1.length == m + n
 * nums2.length == n
 * 0 <= m, n <= 200
 * 1 <= m + n <= 200
 * -10^9 <= nums1[i], nums2[j] <= 10^9
 * 
 * 
 * 
 * Follow up: Can you come up with an algorithm that runs in O(m + n) time?
 * 
 */

// @lc code=start
#include <vector>

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // If either one is empty
        if (n == 0) {
            return;
        }
        if (m == 0) {
            for (int i = 0; i < n; ++i) { 
                nums1[i] = nums2[i]; 
            }
            return;
        }
        
        // Brute Force
        // // Merge all elements into nums1
        // std::vector<int>::iterator currPosInNums1Itr = nums1.begin();
        // nums1.resize(m);
        // for (int j = 0; j < n; ++j) {
        //     while (*currPosInNums1Itr < nums2[j] && currPosInNums1Itr != nums1.end()) {
        //         currPosInNums1Itr++;
        //     }
        //     currPosInNums1Itr = nums1.insert(currPosInNums1Itr, nums2[j]);
        // }

        // Not changing the vector size
        int currPosNums1 = m - 1;
        int currPosNums2 = n - 1;
        int tailPos = m + n - 1;
        // When there is still elemtns in nums2 haven't been set up
        while (currPosNums2 >= 0) {
            // set up the larger elements in nums1 into the tail
            while (currPosNums1 >= 0 && nums1[currPosNums1] >= nums2[currPosNums2]) {
                nums1[tailPos--] = nums1[currPosNums1--];
            }
            // set up the current nums2 element
            nums1[tailPos--] = nums2[currPosNums2--];
        }
    }
};
// @lc code=end

// n = length of max(nums1, nums2)
// Time: O(n)
// Space: O(n)

