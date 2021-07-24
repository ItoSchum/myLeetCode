/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (55.09%)
 * Likes:    5059
 * Dislikes: 187
 * Total Accepted:    379.8K
 * Total Submissions: 685.1K
 * Testcase Example:  '3'
 *
 * Given an integer n, return the number of structurally unique BST's (binary
 * search trees) which has exactly n nodes of unique values from 1 to n.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 19
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int** memo;
    
    int numTrees(int n) {
        memo = new int*[n + 1];
        for (int i = 0; i < n + 1; ++i) {
            memo[i] = new int[n + 1];
            for (int j = 0; j < n + 1; ++j) {
                memo[i][j] = 0;
            }
        }
        return count(1, n);
    }

    int count(int lower_bound, int upper_bound) {
        if (lower_bound >= upper_bound) {
            return 1;
        }
        if (memo[lower_bound][upper_bound] != 0) {
            return memo[lower_bound][upper_bound];
        }

        int res = 0;
        for (int i = lower_bound; i <= upper_bound; ++i) {
            int left = count(lower_bound, i - 1);
            int right = count(i + 1, upper_bound);
            res += left * right;
        }
        memo[lower_bound][upper_bound] = res;

        return res;
    }
};
// @lc code=end

// n = node number
// Time: O(2^log2(n) )
// Space: O(n^2)

