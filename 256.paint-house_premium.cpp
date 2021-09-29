class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int houseNum = costs.size();
        int colorNum = 3;
        
        for (int i = 1; i < houseNum; ++i) {
            for (int j = 0; j < colorNum; ++j) {
                costs[i][j] += findMin(costs[i - 1], j);
            }
        }
        return *min_element(costs[houseNum-1].begin(), costs[houseNum-1].end() );
    }

private:
    int findMin(const vector<int>& singleMemoCost, const int colorIndex) {
        int minCost = INT_MAX;
        for (int i = 0; i < singleMemoCost.size(); ++i) {
            if (minCost > singleMemoCost[i] && i != colorIndex) { 
                minCost = singleMemoCost[i]; 
            }
        }
        return minCost;
    }
    
};

// n = house number
// Time: O(n)
// Space: O(1)