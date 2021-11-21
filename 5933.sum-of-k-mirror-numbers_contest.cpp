#include <iostream>
#include <string>
#include <list>

class Solution {
public:
    long long kMirror(int k, int n) {
        int count = 0;
        long long sum = 0;
        int currNum = 1;
        std::string convertedStr;
        
        while (count < n) {
            if (checkPalindrome(std::to_string(currNum)) == false) {
                currNum += 1;
                continue;
            }
            convertedStr = convertToKBase(currNum, k);
            if (checkPalindrome(convertedStr) ) {
                // printf("%d %s, ", currNum, convertedStr.c_str());
                sum += currNum;
                count += 1;
            }
            currNum += 1;
        }
        return sum;
    }
    
    std::string convertToKBase(int tenBasedNum, int base) {
        std::list<int> remainList;
        int nextRemain = 0;
        while (tenBasedNum > 0) {
            nextRemain = tenBasedNum % base;
            tenBasedNum /= base;
            remainList.push_front(nextRemain);
        }
        std::string outputStr;
        while (remainList.size() > 0) {
            outputStr.append( std::to_string(remainList.front()) );
            remainList.pop_front();
        }
        return outputStr;
    }
    
    bool checkPalindrome(const std::string& str) {
        bool isPalindrome = true;
        int mid = str.size() / 2 + 1;
        for (int i = 0; i < mid; ++i) {
            if (str[i] != str[str.size() - 1 - i]) {
                isPalindrome = false;
            }
        }
        return isPalindrome;
    }
};

// Time limit exceeded
// Last executed input:
// 5
// 15