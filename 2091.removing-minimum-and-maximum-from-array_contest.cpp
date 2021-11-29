// 2091. Removing Minimum and Maximum From Array My SubmissionsBack to Contest
// User Accepted: 3570
// User Tried: 3970
// Total Accepted: 3670
// Total Submissions: 6548
// Difficulty: Medium
// You are given a 0-indexed array of distinct integers nums.

// There is an element in nums that has the lowest value and an element that has the highest value. We call them the minimum and maximum respectively. Your goal is to remove both these elements from the array.

// A deletion is defined as either removing an element from the front of the array or removing an element from the back of the array.

// Return the minimum number of deletions it would take to remove both the minimum and maximum element from the array.

 

// Example 1:

// Input: nums = [2,10,7,5,4,1,8,6]
// Output: 5
// Explanation: 
// The minimum element in the array is nums[5], which is 1.
// The maximum element in the array is nums[1], which is 10.
// We can remove both the minimum and maximum by removing 2 elements from the front and 3 elements from the back.
// This results in 2 + 3 = 5 deletions, which is the minimum number possible.
// Example 2:

// Input: nums = [0,-4,19,1,8,-2,-3,5]
// Output: 3
// Explanation: 
// The minimum element in the array is nums[1], which is -4.
// The maximum element in the array is nums[2], which is 19.
// We can remove both the minimum and maximum by removing 3 elements from the front.
// This results in only 3 deletions, which is the minimum number possible.
// Example 3:

// Input: nums = [101]
// Output: 1
// Explanation:  
// There is only one element in the array, which makes it both the minimum and maximum element.
// We can remove it with 1 deletion.
 

// Constraints:

// 1 <= nums.length <= 105
// -105 <= nums[i] <= 105
// The integers in nums are distinct.

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxIdx = std::max_element(begin(nums), end(nums) ) - begin(nums);
        int minIdx = std::min_element(begin(nums), end(nums) ) - begin(nums);
        
        int frontDist = std::min(maxIdx, minIdx) + 1;
        int midDist = std::max(maxIdx, minIdx) - std::min(maxIdx, minIdx) + 1;
        int backDist = nums.size() - std::max(maxIdx, minIdx);
        
        int frontDel = frontDist + midDist - 1;
        int bothSideDel = frontDist + backDist;
        int backDel = backDist + midDist - 1;
        
        int minDelOp = std::min({frontDel, bothSideDel, backDel});
        return minDelOp;
    }
};