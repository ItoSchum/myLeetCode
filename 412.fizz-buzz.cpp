/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 *
 * https://leetcode.com/problems/fizz-buzz/description/
 *
 * algorithms
 * Easy (64.20%)
 * Likes:    1597
 * Dislikes: 1759
 * Total Accepted:    528.2K
 * Total Submissions: 810.3K
 * Testcase Example:  '3'
 *
 * Given an integer n, return a string array answer (1-indexed) where:
 * 
 * 
 * answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
 * answer[i] == "Fizz" if i is divisible by 3.
 * answer[i] == "Buzz" if i is divisible by 5.
 * answer[i] == i if non of the above conditions are true.
 * 
 * 
 * 
 * Example 1:
 * Input: n = 3
 * Output: ["1","2","Fizz"]
 * Example 2:
 * Input: n = 5
 * Output: ["1","2","Fizz","4","Buzz"]
 * Example 3:
 * Input: n = 15
 * Output:
 * ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^4
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::string> fizzBuzz(int n) {

        // Using for/while loop
        // for (unsigned int i = 1; i <= n; ++i) {
        //     if (i % 15 == 0) {
        //         answer.push_back("FizzBuzz");
        //     } else if (i % 3 == 0) {
        //         answer.push_back("Fizz");
        //     } else if (i % 5 == 0) {
        //         answer.push_back("Buzz");
        //     } else {
        //         answer.push_back(std::to_string(i) );
        //     }
        // }

        // Using recursion
        stepFizzBuzz(n);
        std::reverse(answer.begin(), answer.end() );

        // Hardcode

        return answer;
    }

    void stepFizzBuzz(int n) {
        if (n <= 0) { return; }
        
        if (n % 15 == 0) {
            answer.push_back("FizzBuzz");
        } else if (n % 3 == 0) {
            answer.push_back("Fizz");
        } else if (n % 5 == 0) {
            answer.push_back("Buzz");
        } else {
            answer.push_back(std::to_string(n) );
        }
        stepFizzBuzz(n - 1);
    }

private:
    std::vector<std::string> answer;
};
// @lc code=end

