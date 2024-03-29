/*
 * @lc app=leetcode id=1029 lang=cpp
 *
 * [1029] Two City Scheduling
 *
 * https://leetcode.com/problems/two-city-scheduling/description/
 *
 * algorithms
 * Medium (58.50%)
 * Likes:    2151
 * Dislikes: 214
 * Total Accepted:    124K
 * Total Submissions: 209.6K
 * Testcase Example:  '[[10,20],[30,200],[400,50],[30,20]]'
 *
 * A company is planning to interview 2n people. Given the array costs where
 * costs[i] = [aCosti, bCosti], the cost of flying the i^th person to city a is
 * aCosti, and the cost of flying the i^th person to city b is bCosti.
 * 
 * Return the minimum cost to fly every person to a city such that exactly n
 * people arrive in each city.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: costs = [[10,20],[30,200],[400,50],[30,20]]
 * Output: 110
 * Explanation: 
 * The first person goes to city A for a cost of 10.
 * The second person goes to city A for a cost of 30.
 * The third person goes to city B for a cost of 50.
 * The fourth person goes to city B for a cost of 20.
 * 
 * The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people
 * interviewing in each city.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
 * Output: 1859
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: costs =
 * [[515,563],[451,713],[537,709],[343,819],[855,779],[457,60],[650,359],[631,42]]
 * Output: 3086
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 * n == costs.length
 * 2 <= costs.length <= 100
 * costs.length is even.
 * 1 <= aCosti, bCosti <= 1000
 * 
 * 
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int twoCitySchedCost(std::vector<std::vector<int>>& costs) {
        // sort the costs by cost diff
        std::sort(costs.begin(), costs.end(), compareCostDiff);

        // accumulate
        int minCost = 0;
        int n = costs.size() / 2;
        for (unsigned int i = 0; i < n; ++i) {
            minCost += costs[i][0] + costs[n + i][1];
        }
        return minCost;
    }

private:
    static bool compareCostDiff(const std::vector<int>& left, const std::vector<int>& right) {
        return (left[0] - left[1] <= right[0] - right[1]);
    }
};
// @lc code=end

// n = length of costs
// Time: O(nlog(n) )
// Space: O(1)