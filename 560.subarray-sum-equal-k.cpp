#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> sumOccurrenceTimes = { {0, 1} };
        
        int validCount = 0; 
        int currSum = 0;
        for (int i = 0; i < nums.size(); ++i) { 
            currSum += nums[i];
            // cout << "i = " << i << ", ";
            if (sumOccurrenceTimes.count(currSum - k) > 0)  {
                validCount += sumOccurrenceTimes[currSum - k];
                // cout << "Valid += " << sumOccurrenceTimes[currSum - k] << ", ";
            }
            if (sumOccurrenceTimes.count(currSum) > 0) {
                sumOccurrenceTimes[currSum]++;
            } else {
                sumOccurrenceTimes[currSum] = 1;
            }
            // cout << currSum << ": " << sumOccurrenceTimes[currSum] << endl;
        }

        // Accumulative sum solution
        // std::vector<int> sumUpTo(nums.size() + 1, 0);
        // for (int i = 1; i < nums.size() + 1; ++i) {
        //     sumUpTo[i] = sumUpTo[i - 1] + nums[i - 1];
        // }
        
        // for (int start = 0; start < nums.size(); ++start) {
        //     for (int end = start + 1; end < nums.size() + 1; ++end) {
        //         if (sumUpTo[end] - sumUpTo[start] == k) {
        //             validCount++;
        //         }
        //     }
        // }
        return validCount;
    }
};