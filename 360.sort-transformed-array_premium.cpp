#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> sortTransformedArray(std::vector<int>& nums, int a, int b, int c) {
        std::vector<int> results(nums.size(), 0);
        
        // If a equals ZERO
        if (a == 0) {
            for (unsigned i = 0; i < nums.size(); ++i) {
                results[i] = b * nums[i] + c;
            }
            if (b < 0) { std::reverse(results.begin(), results.end() ); }
            return results;
        }
        
        // If a isnot ZERO
        double axis_x = - (double)b / (2 * a);
        unsigned int start_index = 0;
        unsigned int end_index = nums.size() - 1;
        unsigned int count = 0;
        int next_num;
        
        while (start_index <= end_index) {
            if (std::abs(nums[start_index] - axis_x) > std::abs(nums[end_index] - axis_x) ) {
                next_num = nums[start_index++];
            } else {
                next_num = nums[end_index--];
            }
            results[count++] = a * next_num * next_num + b * next_num + c;
        }
        if (results.front() > results.back() ) {
            std::reverse(results.begin(), results.end() );
        }
        return results;
    }
};

// n = length of nums
// Time: O(n)
// Space: O(n)