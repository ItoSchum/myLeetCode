#include <iostream>
#include <vector>
#include <unordered_map>

class RangeFreqQuery {
public:
    RangeFreqQuery(std::vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i) {
            _valueToIdx[ arr[i] ].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        std::vector<int>& idxVec = _valueToIdx[value];
        // No such value in list
        if (_valueToIdx.count(value) == 0) {
            return 0;
        }
        // int rightIdx = upper_bound(begin(idxVec), end(idxVec), right) - begin(idxVec);
        // int leftIdx = lower_bound(begin(idxVec), end(idxVec), left) - begin(idxVec);
        int rightIdx = find_upper_bound(idxVec, right);
        int leftIdx = find_lower_bound(idxVec, left);
        
        return rightIdx - leftIdx;
    }

private:
    std::unordered_map<int, std::vector<int> > _valueToIdx;

    int find_upper_bound(const std::vector<int>& idxVec, int right) {
        int mid;
        int low = 0;
        int high = idxVec.size();
        while (low < high) {
            mid = low + (high - low) / 2;
            if (right >= idxVec[mid]) { low = mid + 1; } 
            else { high = mid; }
        }
        return low;
    }
    
    int find_lower_bound(const std::vector<int>& idxVec, int left) {
        int mid;
        int low = 0;
        int high = idxVec.size();
        while (low < high) {
            mid = low + (high - low) / 2;
            if (left <= idxVec[mid]) { high = mid; } 
            else { low = mid + 1; }
        }
        return low;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */