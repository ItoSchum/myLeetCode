/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 *
 * https://leetcode.com/problems/can-place-flowers/description/
 *
 * algorithms
 * Easy (31.62%)
 * Likes:    1760
 * Dislikes: 518
 * Total Accepted:    199.1K
 * Total Submissions: 628.1K
 * Testcase Example:  '[1,0,0,0,1]\n1'
 *
 * You have a long flowerbed in which some of the plots are planted, and some
 * are not. However, flowers cannot be planted in adjacent plots.
 * 
 * Given an integer array flowerbed containing 0's and 1's, where 0 means empty
 * and 1 means not empty, and an integer n, return if n new flowers can be
 * planted in the flowerbed without violating the no-adjacent-flowers rule.
 * 
 * 
 * Example 1:
 * Input: flowerbed = [1,0,0,0,1], n = 1
 * Output: true
 * Example 2:
 * Input: flowerbed = [1,0,0,0,1], n = 2
 * Output: false
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= flowerbed.length <= 2 * 10^4
 * flowerbed[i] is 0 or 1.
 * There are no two adjacent flowers in flowerbed.
 * 0 <= n <= flowerbed.length
 * 
 * 
 */

// @lc code=start
#include <vector>

class Solution {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        int availableCount = 0;
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (canPlaceFlowerAtPosition(flowerbed, i) ) {
                availableCount++;
                flowerbed[i] = 1;
            }
        }
        return (availableCount >= n);
    }

    bool canPlaceFlowerAtPosition(const std::vector<int>& flowerbed, int i) {
        return ( flowerbed[i] == 0
            && (i == 0 || flowerbed[i - 1] == 0) 
            && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0) );
    }
};
// @lc code=end

// n = flowerbed size
// Time: O(n);
// Space: O(1);

