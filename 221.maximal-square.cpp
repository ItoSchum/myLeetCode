/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (40.12%)
 * Likes:    5531
 * Dislikes: 123
 * Total Accepted:    400.3K
 * Total Submissions: 973.3K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given an m x n binary matrix filled with 0's and 1's, find the largest
 * square containing only 1's and return its area.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [["0","1"],["1","0"]]
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: matrix = [["0"]]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 300
 * matrix[i][j] is '0' or '1'.
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>

class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix) {
        int height = matrix.size();
        int width = matrix[0].size();
        std::vector<std::vector<int> > memo (height + 1, std::vector<int>(width + 1, 0) );

        int maxSqLen = 0;
        for (unsigned int i = 1; i <= height; ++i) {
            for (unsigned int j = 1; j <= width; ++j) {
                if (matrix[i - 1][j - 1] == '0') { 
                    continue; 
                }
                memo[i][j] = std::min( {memo[i - 1][j - 1], memo[i - 1][j], memo[i][j - 1]} ) + 1;
                maxSqLen = std::max(memo[i][j], maxSqLen);
            }
        }
        return maxSqLen * maxSqLen;
    }
};
// @lc code=end

// n = matrix length
// Time: O(n^2)
// Space: O(n^2)

