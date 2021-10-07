#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> sortTransformedArray(std::vector<int>& nums, int a, int b, int c) {
        std::vector<int> results;
        for (unsigned int i = 0; i < nums.size(); ++i) {
            int result = a * nums[i] * nums[i] + b * nums[i] + c;
            results.push_back(result);
        }
        sort(results.begin(), results.end() );
        return results;
    }
};