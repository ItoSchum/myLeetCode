/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (50.26%)
 * Likes:    10640
 * Dislikes: 276
 * Total Accepted:    1.3M
 * Total Submissions: 2.4M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) and
 * '0's (water), return the number of islands.
 * 
 * An island is surrounded by water and is formed by connecting adjacent lands
 * horizontally or vertically. You may assume all four edges of the grid are
 * all surrounded by water.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 300
 * grid[i][j] is '0' or '1'.
 * 
 * 
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int numIslands(std::vector<std::vector<char> >& grid) {
        // Invalid input checking
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        // Normal input
        _grid = grid;
        int islandCount = 0;
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (_grid[row][col] == '1') {
                    islandCount++;
                    dfsMarkIsland(row, col);
                }
            }
        }
        return islandCount;
    }

    void dfsMarkIsland(int row, int col) {
        // marked cell or non-island cell
        if (_grid[row][col] == 'X' || _grid[row][col] == '0') {
            return;
        }
        // island cells
        int height = _grid.size();
        int width = _grid[0].size();
        if (_grid[row][col] == '1') {
            _grid[row][col] = 'X';
            if (row - 1 >= 0) { dfsMarkIsland(row - 1, col); }
            if (row + 1 < height) { dfsMarkIsland(row + 1, col); }
            if (col - 1 >= 0) { dfsMarkIsland(row, col - 1); }
            if (col + 1 < width) { dfsMarkIsland(row, col + 1); }
        }
    }

private:
    std::vector<std::vector<char> > _grid;
};
// @lc code=end

// m = matrix height
// n = matrix width
// Time: O(m * n)
// Space: O(m * n) (worst case scenario)
