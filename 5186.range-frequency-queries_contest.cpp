class RangeFreqQuery {
public:
    RangeFreqQuery(vector<int>& arr) {
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
        int rightIdx = upper_bound(begin(idxVec), end(idxVec), right) - begin(idxVec);
        int leftIdx = lower_bound(begin(idxVec), end(idxVec), left) - begin(idxVec);
        return rightIdx - leftIdx;
    }

private:
    std::unordered_map<int, std::vector<int> > _valueToIdx;
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */