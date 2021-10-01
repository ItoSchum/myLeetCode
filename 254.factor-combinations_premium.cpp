class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<int> currCombination;
        stepGetFactors(n, currCombination) ;
        return allCombinations;
    }
    
    void stepGetFactors(int n, vector<int>& currCombination) { 
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0 && (currCombination.empty() || i >= currCombination.back() )) {
                currCombination.push_back(i);
                currCombination.push_back(n / i);
                allCombinations.push_back(currCombination);
                currCombination.pop_back(); // pop_back n/i
                stepGetFactors(n / i, currCombination);
                currCombination.pop_back(); // pop_aback n/11
            }
        }
    }
    
private:
    vector<vector<int> > allCombinations = {};
};

// n = input num
// Time: O( nlog2(n) )
// Space: O( log2(n) )