#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        // Empty board
        if (board.size() == 0 || board[0].size() == 0) {
            return board;
        }
        // Init
        height = board.size();
        width = board[0].size();
        
        // printBoard(board);
        while( crushCandy(board) ) {
            continue;
        }
        // printBoard(board);
        return board;
    }
    
    bool crushCandy(vector<vector<int>>& board) {
        bool crushedCandy = false;

        // Crush candies horizontally
        for (int row = 0; row < height; ++row) {
            for (int col = 0; col + 2 < width; ++col) {
                int prevVal = std::abs(board[row][col]);
                // If same adjacent value
                if (prevVal != 0
                    && std::abs(board[row][col]) == std::abs(board[row][col+1]) 
                    && std::abs(board[row][col+1]) == std::abs(board[row][col+2]) ) {
                    board[row][col] = board[row][col+1] = board[row][col+2] = -prevVal;
                    // DEBUG
                    // printf("[%d, %d]\n", row, col);
                    crushedCandy = true;
                }
            }
        }
        // Crush candies vertically
        for (int col = 0; col < width; ++col) {
            for (int row = 0; row + 2 < height; ++row) {
                int prevVal = std::abs(board[row][col]);
                // If same adjacent value
                if (prevVal != 0
                    && std::abs(board[row][col]) == std::abs(board[row+1][col]) 
                    && std::abs(board[row+1][col]) == std::abs(board[row+2][col]) ) {
                    board[row][col] = board[row+1][col] = board[row+2][col] = -prevVal;
                    printf("[%d, %d]\n", row, col);
                    crushedCandy = true;
                }
            }
        }
        // Drop candies
        for (int col = 0; col < width; ++col) {
            int nextNonEmptyRow = height - 1;
            for (int row = height - 1; row >= 0; --row) {
                if (board[row][col] > 0) {
                    board[nextNonEmptyRow--][col] = board[row][col];
                }
            }
            while(nextNonEmptyRow >= 0) {
                board[nextNonEmptyRow--][col] = 0;
            }
        }
        // return if crushed any candy
        return crushedCandy;
    }
    
private:
    unsigned int height;
    unsigned int width;
    
    // DEBUG
    void printBoard(const vector<vector<int>>& board) {
        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                printf("%5d ", board[row][col]);
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
};

// n = board width
// m = board height
// t = crush times
// Time: O(n * m * t)
// Space: O(1)