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
        const int height = matrix.size();
        const int width = matrix[0].size();
        std::vector<int> resultSeq = { matrix[0][0] };
        matrix[0][0] = VISITED;
        
        int currRow = 0;
        int currCol = 0;
        int currDirection = 0;
        int nextRow;
        int nextCol;
        
        while (true) {
            nextRow = currRow + nextRowStep[currDirection];
            nextCol = currCol + nextColStep[currDirection];
            // printf("[%d, %d] ", nextRow, nextCol);
            
            // Need to change direction
            if (!isCoordValid(nextRow, nextCol, height, width) 
                || matrix[nextRow][nextCol] == VISITED) {
                currDirection = (currDirection + 1) % 4;
                nextRow = currRow + nextRowStep[currDirection];
                nextCol = currCol + nextColStep[currDirection];
                // printf("Change to [%d, %d]\n", nextRow, nextCol);
                
                // End of the spiral sequence
                if (!isCoordValid(nextRow, nextCol, height, width) 
                    || matrix[nextRow][nextCol] == VISITED) { 
                    // printf("Still invalid [%d, %d]\n", nextRow, nextCol);
                    break; 
                }
            }
            resultSeq.push_back(matrix[nextRow][nextCol]);
            matrix[nextRow][nextCol] = VISITED;
            currRow = nextRow;
            currCol = nextCol;
        }
        return resultSeq;
    }

private:
    const std::vector<int> nextRowStep = {0, 1,  0, -1};
    const std::vector<int> nextColStep = {1, 0, -1,  0};
    const int VISITED = 111;

    bool isCoordValid(int row, int col, const int height, const int width) {
        return (row >= 0 && col >= 0 && row < height && col < width);
    }
};
// @lc code=end

// n = row number, m = column number
// Time: O(n * m)
// Space: O(1)

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix.
// Memory Usage: 6.8 MB, less than 92.72% of C++ online submissions for Spiral Matrix.

