// 2110. Number of Smooth Descent Periods of a Stock
// User Accepted:4477
// User Tried:5188
// Total Accepted:4603
// Total Submissions:9929
// Difficulty:Medium
// You are given an integer array prices representing the daily price history of a stock, where prices[i] is the stock price on the ith day.

// A smooth descent period of a stock consists of one or more contiguous days such that the price on each day is lower than the price on the preceding day by exactly 1. The first day of the period is exempted from this rule.

// Return the number of smooth descent periods.

 

// Example 1:

// Input: prices = [3,2,1,4]
// Output: 7
// Explanation: There are 7 smooth descent periods:
// [3], [2], [1], [4], [3,2], [2,1], and [3,2,1]
// Note that a period with one day is a smooth descent period by the definition.
// Example 2:

// Input: prices = [8,6,7,7]
// Output: 4
// Explanation: There are 4 smooth descent periods: [8], [6], [7], and [7]
// Note that [8,6] is not a smooth descent period as 8 - 6 ≠ 1.
// Example 3:

// Input: prices = [1]
// Output: 1
// Explanation: There is 1 smooth descent period: [1]
 

// Constraints:

// 1 <= prices.length <= 105
// 1 <= prices[i] <= 105

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        _prices = prices;
        // Init memo
        std::vector<std::vector<bool> > isDescentPeriods (prices.size() + 1, std::vector<bool> (prices.size(), false) );
        periodCount = _prices.size();
        
        // When window len = 2
        for (int i = 0; i < prices.size() - 1; ++i) {
            if (_prices[i] - _prices[i + 1] == 1) {
                isDescentPeriods[2][i] = true;
                periodCount++;
                _prevDescentPeriods.push_back(i);
            }
        }
        // Counting when window len >= 3
        std::vector<int> prevDescentPeriods;
        for (int len = 3; len <= prices.size(); ++len) {
            prevDescentPeriods = _prevDescentPeriods;
            _prevDescentPeriods = getDescentPeriodsByWindowLen(len, isDescentPeriods, prevDescentPeriods);
        }
        return periodCount;
    }
    
    std::vector<int> getDescentPeriodsByWindowLen(int windowLen, 
                                      std::vector<std::vector<bool> >& isDescentPeriods, 
                                      std::vector<int>& prevDescentPeriods) {
        
        std::vector<int> currDescentPeriods;
        for (int i = 0; i <= prevDescentPeriods.size(); ++i) {
            int start = prevDescentPeriods[i];
            if (start < _prices.size() - 1
                && isDescentPeriods[windowLen - 1][start] 
                && isDescentPeriods[windowLen - 1][start + 1]) {
                isDescentPeriods[windowLen][start] = true;
                periodCount++;
                currDescentPeriods.push_back(start);
            }
        }
        return currDescentPeriods;
    }
    
private:
    long long periodCount = 0;
    std::vector<int> _prices;
    std::vector<int> _prevDescentPeriods;
};