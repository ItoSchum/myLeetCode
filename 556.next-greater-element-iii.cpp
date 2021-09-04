/*
 * @lc app=leetcode id=556 lang=cpp
 *
 * [556] Next Greater Element III
 *
 * https://leetcode.com/problems/next-greater-element-iii/description/
 *
 * algorithms
 * Medium (33.41%)
 * Likes:    1502
 * Dislikes: 282
 * Total Accepted:    75.2K
 * Total Submissions: 225.2K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the smallest integer which has exactly the
 * same digits existing in the integer n and is greater in value than n. If no
 * such positive integer exists, return -1.
 * 
 * Note that the returned integer should fit in 32-bit integer, if there is a
 * valid answer but it does not fit in 32-bit integer, return -1.
 * 
 * 
 * Example 1:
 * Input: n = 12
 * Output: 21
 * Example 2:
 * Input: n = 21
 * Output: -1
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <string>

class Solution {
public:
    int nextGreaterElement(int n) {
        string str_n = std::to_string(n);
        if (!nextPermuation(str_n) ) {
            return -1;
        }
        long greater_num = std::stol(str_n);
        if (greater_num > (long)INT32_MAX) {
            return -1;
        } 
        return (int)greater_num;
    }

private:
    bool nextPermuation(string& str_num) {
        if (str_num.size() <= 1) { return false; }
        // std::cout << "String not empty" << std::endl;

        // find first num[i] > num[i - 1]
        int i = str_num.size() - 1;
        while (i >= 1 && str_num[i] <= str_num[i - 1]) {
            i--;
        }
        if (i == 0) { return false; }

        // find first num[j] > num[i - 1] (definitely can find one, when j == i)
        int j = str_num.size() - 1;
        while(j >= i && str_num[j] <= str_num[i - 1]) {
            j--;
        }
        
        // swap positon i - 1 and j
        std::swap(str_num[i - 1], str_num[j]);
        // reverse the increasing part
        std::reverse(str_num.begin() + i, str_num.end());
        return true;
    }
};
// @lc code=end

// n = length of the number as string 
// Time: O(n)
// Space: O(n)

