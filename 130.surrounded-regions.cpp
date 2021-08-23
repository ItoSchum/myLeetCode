/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (30.31%)
 * Likes:    3297
 * Dislikes: 857
 * Total Accepted:    324.5K
 * Total Submissions: 1M
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given an m x n matrix board containing 'X' and 'O', capture all regions that
 * are 4-directionally surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board =
 * [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
 * Output:
 * [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
 * Explanation: Surrounded regions should not be on the border, which means
 * that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that
 * is not on the border and it is not connected to an 'O' on the border will be
 * flipped to 'X'. Two cells are connected if they are adjacent cells connected
 * horizontally or vertically.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: board = [["X"]]
 * Output: [["X"]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 200
 * board[i][j] is 'X' or 'O'.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int DIRECTIONS = 4;
    char EXPECTED_SIGN = 'O';
    char TEMP_SIGN = '#';
    char CROSSING_SIGN = 'X';
    int rowStep[4] = {0,  0, 1, -1};
    int colStep[4] = {1, -1, 0,  0};

    void dfsMarkUpInvalidPoint(vector<vector<char>>& board, int row, int col) {
        if (board[row][col] != EXPECTED_SIGN) { return; }
        board[row][col] = TEMP_SIGN;
        int matrix_height = board.size(); 
        int matrix_length = board[0].size();

        for (int i = 0; i < DIRECTIONS; ++i) {
            int nextRow = row + rowStep[i];
            int nextCol = col + colStep[i];
            if (nextRow >= 0 && nextRow < matrix_height 
                && nextCol >= 0 && nextCol < matrix_length 
                && board[nextRow][nextCol] == EXPECTED_SIGN) {
                dfsMarkUpInvalidPoint(board, nextRow, nextCol);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int matrix_height = board.size(); 
        int matrix_length = board[0].size();
        
        for(int row = 0; row < matrix_height; ++row) {
            if (row > 0 && row < matrix_height - 1) {
                if (board[row][0] == EXPECTED_SIGN) { 
                    dfsMarkUpInvalidPoint(board, row, 0);
                }
                if (board[row][matrix_length - 1] == EXPECTED_SIGN) { 
                    dfsMarkUpInvalidPoint(board, row, matrix_length - 1); 
                }
            }
            else {
                for (int col = 0; col < matrix_length; ++col) {
                    if (board[row][col] == EXPECTED_SIGN) {
                        dfsMarkUpInvalidPoint(board, row, col);
                    }
                }
            }
        }

        for (int row = 0; row < matrix_height; ++row) {
            for (int col = 0; col < matrix_length; ++col) {
                if (board[row][col] == EXPECTED_SIGN) {
                    board[row][col] = CROSSING_SIGN;
                }
                if (board[row][col] == TEMP_SIGN) {
                    board[row][col] = EXPECTED_SIGN;
                    
                }
            }
        }

    }
};
// @lc code=end

// m = matrix height (rows)
// n = matrix length (columns) 
// Time: O(mn)
// Space: O(mn)