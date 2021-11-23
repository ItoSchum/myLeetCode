/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (37.18%)
 * Likes:    5507
 * Dislikes: 745
 * Total Accepted:    616.2K
 * Total Submissions: 1.6M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 10
 * -100 <= matrix[i][j] <= 100
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        int currStep = 0;
        int stepCount = 0;
        
        int currRow = 0;
        int currCol = 0;
        std::vector<int> resultSeq;

        while (stepCount < matrix.size() * matrix[0].size() ) {
            if (matrix[currRow][currCol] == VISITED) {
                currStep = (currStep + 1) % 4;
                currRow += nextRowStep[currStep];
                currCol += nextColStep[currStep];
                
                stepCount++;
            }
            resultSeq.push_back(matrix[currRow][currCol]);
        }
    }

private:
    const std::vector<int> nextRowStep = {0, -1,  0, 1};
    const std::vector<int> nextColStep = {1,  0, -1, 0};
    const int VISITED = 111;
    
};
// @lc code=end

