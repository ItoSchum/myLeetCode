#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> getFactors(int n) {
        std::vector<int> currCombination;
        stepGetFactors(n, currCombination) ;
        return allCombinations;
    }
    
    void stepGetFactors(int n, std::vector<int>& currCombination) { 
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0 && (currCombination.empty() || i >= currCombination.back() )) {
                currCombination.push_back(i);
                currCombination.push_back(n / i);
                allCombinations.push_back(currCombination);
                currCombination.pop_back(); // pop_back n/i
                stepGetFactors(n / i, currCombination);
                currCombination.pop_back(); // pop_back i
            }
        }
    }
    
private:
    std::vector<std::vector<int> > allCombinations = { };
};

// n = input num
// Time: O( nlog2(n) )
// Space: O( log2(n) )