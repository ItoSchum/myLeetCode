/*
 * @lc app=leetcode id=1010 lang=cpp
 *
 * [1010] Pairs of Songs With Total Durations Divisible by 60
 *
 * https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/description/
 *
 * algorithms
 * Medium (51.09%)
 * Likes:    1855
 * Dislikes: 92
 * Total Accepted:    131.3K
 * Total Submissions: 252.4K
 * Testcase Example:  '[30,20,150,100,40]'
 *
 * You are given a list of songs where the i^th song has a duration of time[i]
 * seconds.
 * 
 * Return the number of pairs of songs for which their total duration in
 * seconds is divisible by 60. Formally, we want the number of indices i, j
 * such that i < j with (time[i] + time[j]) % 60 == 0.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: time = [30,20,150,100,40]
 * Output: 3
 * Explanation: Three pairs have a total duration divisible by 60:
 * (time[0] = 30, time[2] = 150): total duration 180
 * (time[1] = 20, time[3] = 100): total duration 120
 * (time[1] = 20, time[4] = 40): total duration 60
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: time = [60,60,60]
 * Output: 3
 * Explanation: All three pairs have a total duration of 120, which is
 * divisible by 60.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= time.length <= 6 * 10^4
 * 1 <= time[i] <= 500
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int numPairsDivisibleBy60(std::vector<int>& time) {
        int count = 0;
        for (int timestamp : time) {
            int remainder = timestamp % 60;
            if (remainder == 0) {
                count += remainderToFreq[0];
            } else {
                count += remainderToFreq[60 - remainder];
            }
            remainderToFreq[remainder]++;
        }
        return count;
    }

private:
    std::unordered_map<int, int> remainderToFreq;
};
// @lc code=end

