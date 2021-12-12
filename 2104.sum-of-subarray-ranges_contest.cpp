// 2104. Sum of Subarray Ranges
// User Accepted:3207
// User Tried:4182
// Total Accepted:3280
// Total Submissions:7137
// Difficulty:Medium
// You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

// Return the sum of all subarray ranges of nums.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: 4
// Explanation: The 6 subarrays of nums are the following:
// [1], range = largest - smallest = 1 - 1 = 0 
// [2], range = 2 - 2 = 0
// [3], range = 3 - 3 = 0
// [1,2], range = 2 - 1 = 1
// [2,3], range = 3 - 2 = 1
// [1,2,3], range = 3 - 1 = 2
// So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
// Example 2:

// Input: nums = [1,3,3]
// Output: 4
// Explanation: The 6 subarrays of nums are the following:
// [1], range = largest - smallest = 1 - 1 = 0
// [3], range = 3 - 3 = 0
// [3], range = 3 - 3 = 0
// [1,3], range = 3 - 1 = 2
// [3,3], range = 3 - 3 = 0
// [1,3,3], range = 3 - 1 = 2
// So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
// Example 3:

// Input: nums = [4,-2,-3,4,1]
// Output: 59
// Explanation: The sum of all subarray ranges of nums is 59.
 

// Constraints:

// 1 <= nums.length <= 1000
// -109 <= nums[i] <= 109

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long allRanges = 0;
        
        for (int windowLen = 2; windowLen <= nums.size(); ++windowLen) {
            std::set<int> subarray(nums.begin(), nums.begin() + windowLen);
            std::unordered_map<int, int> numToFreq;
            for (int i = 0; i < windowLen; ++i) {
                numToFreq[ nums[i] ] += 1;
            }
            int currMax = findSetMax(subarray);
            int currMin = findSetMin(subarray);
            allRanges += currMax - currMin;
            
            // printSubarray(subarray);
            // printf("max: %d, min: %d, range: %d\n", currMax, currMin, currMax - currMin);
            
            for (int start = 1; start <= nums.size() - windowLen; ++start) {
                // get the sub-array by window length
                numToFreq[ nums[start - 1] ] -= 1;
                if ( numToFreq[ nums[start - 1] ] == 0 ) { 
                    subarray.erase(nums[start - 1]);
                }
                numToFreq[ nums[start + windowLen - 1] ] += 1;
                subarray.insert(nums[start + windowLen - 1]);
                currMax = findSetMax(subarray);
                currMin = findSetMin(subarray);
                
                // Accumulate the range of the sub-array
                // printSubarray(subarray);
                // printf("max: %d, min: %d, range: %d\n", currMax, currMin, currMax - currMin);
                allRanges += currMax - currMin;
            }
        }
        return allRanges;
    }
    
    int findSetMax(set<int>& inputSet) {
        return *( inputSet.rbegin() );
    }
    
    int findSetMin(set<int>& inputSet) {
        return *( inputSet.begin() );
    }
    
    void printSubarray(const set<int>& subarray) {
        printf("Curr Subarray: ");
        for (int val : subarray) {
            printf("%d ", val);
        }
        printf("\n");
    }
};