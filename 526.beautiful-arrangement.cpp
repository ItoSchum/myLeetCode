/*
 * @lc app=leetcode id=526 lang=cpp
 *
 * [526] Beautiful Arrangement
 *
 * https://leetcode.com/problems/beautiful-arrangement/description/
 *
 * algorithms
 * Medium (62.33%)
 * Likes:    1649
 * Dislikes: 237
 * Total Accepted:    104.6K
 * Total Submissions: 165.9K
 * Testcase Example:  '2'
 *
 * Suppose you have n integers labeled 1 through n. A permutation of those n
 * integers perm (1-indexed) is considered a beautiful arrangement if for every
 * i (1 <= i <= n), either of the following is true:
 * 
 * 
 * perm[i] is divisible by i.
 * i is divisible by perm[i].
 * 
 * 
 * Given an integer n, return the number of the beautiful arrangements that you
 * can construct.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 2
 * Output: 2
 * Explanation: 
 * The first beautiful arrangement is [1,2]:
 * ⁠   - perm[1] = 1 is divisible by i = 1
 * ⁠   - perm[2] = 2 is divisible by i = 2
 * The second beautiful arrangement is [2,1]:
 * ⁠   - perm[1] = 2 is divisible by i = 1
 * ⁠   - i = 2 is divisible by perm[2] = 1
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
 * 1 <= n <= 15
 * 
 * 
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int countArrangement(int n) {        
        // Backtracking solution
        std::vector<bool> visitedMemo(n + 1, false);
        stepCountArrangement(n, 1, visitedMemo);
  
        return validCount;
    }

    // Backtracking solution
    void stepCountArrangement(int n, int currNum, std::vector<bool> visitedMemo) {
        if (currNum > n) {
            validCount++;
        }
        for (int i = 1; i <= n; ++i) {
            if (visitedMemo[i] == false && (currNum % i == 0 || i % currNum == 0) ) {
                visitedMemo[i] = true;
                stepCountArrangement(n, currNum + 1, visitedMemo);
                visitedMemo[i] = false;
            }
        }
    }
    
private:
    int validCount = 0;
};
// @lc code=end

// n = number amount
// Time: O(k), k = number of valid permutation
// Space: O(n)

