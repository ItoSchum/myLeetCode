// 2094. Finding 3-Digit Even Numbers
// User Accepted:3442
// User Tried:4171
// Total Accepted:3513
// Total Submissions:8443
// Difficulty:Easy
// You are given an integer array digits, where each element is a digit. The array may contain duplicates.

// You need to find all the unique integers that follow the given requirements:

// The integer consists of the concatenation of three elements from digits in any arbitrary order.
// The integer does not have leading zeros.
// The integer is even.
// For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.

// Return a sorted array of the unique integers.

 

// Example 1:

// Input: digits = [2,1,3,0]
// Output: [102,120,130,132,210,230,302,310,312,320]
// Explanation: 
// All the possible integers that follow the requirements are in the output array. 
// Notice that there are no odd integers or integers with leading zeros.
// Example 2:

// Input: digits = [2,2,8,8,2]
// Output: [222,228,282,288,822,828,882]
// Explanation: 
// The same digit can be used as many times as it appears in digits. 
// In this example, the digit 8 is used twice each time in 288, 828, and 882. 
// Example 3:

// Input: digits = [3,7,5]
// Output: []
// Explanation: 
// No even integers can be formed using the given digits.
// Example 4:

// Input: digits = [0,2,0,0]
// Output: [200]
// Explanation: 
// The only valid integer that can be formed with three digits and no leading zeros is 200.
// Example 5:

// Input: digits = [0,0,0]
// Output: []
// Explanation: 
// All the integers that can be formed have leading zeros. Thus, there are no valid integers.
 

// Constraints:

// 3 <= digits.length <= 100
// 0 <= digits[i] <= 9


class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        const int USED = -1;
        std::unordered_set<int> uniqueResults;
        
        for (int third = 0; third < digits.size(); ++third) {
            if (digits[third] & 1 || digits[third] == USED) {
                continue;
            }
            int originalThird = digits[third];
            digits[third] = USED;
            
            for (int first = 0; first < digits.size(); ++first) {
                if (digits[first] == 0 || digits[first] == USED) {
                    continue;
                }
                int originalFirst = digits[first];
                digits[first] = USED;
                
                int singleResult = originalThird + originalFirst * 100;
                
                for (int second = 0; second < digits.size(); ++second) {
                    if (digits[second] == USED) {
                        continue;
                    }
                    uniqueResults.insert(singleResult + digits[second] * 10);
                }
                digits[first] = originalFirst;
            }
            digits[third] = originalThird;
        }
        
        std::vector<int> results(uniqueResults.begin(), uniqueResults.end());
        std::sort(results.begin(), results.end());
        return results;
    }
};
