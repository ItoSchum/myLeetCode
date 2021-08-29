/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 *
 * https://leetcode.com/problems/lfu-cache/description/
 *
 * algorithms
 * Hard (37.08%)
 * Likes:    2376
 * Dislikes: 165
 * Total Accepted:    121.5K
 * Total Submissions: 322.2K
 * Testcase Example:  '["LFUCache","put","put","get","put","get","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]'
 *
 * Design and implement a data structure for a Least Frequently Used (LFU)
 * cache.
 * 
 * Implement the LFUCache class:
 * 
 * 
 * LFUCache(int capacity) Initializes the object with the capacity of the data
 * structure.
 * int get(int key) Gets the value of the key if the key exists in the cache.
 * Otherwise, returns -1.
 * void put(int key, int value) Update the value of the key if present, or
 * inserts the key if not already present. When the cache reaches its capacity,
 * it should invalidate and remove the least frequently used key before
 * inserting a new item. For this problem, when there is a tie (i.e., two or
 * more keys with the same frequency), the least recently used key would be
 * invalidated.
 * 
 * 
 * To determine the least frequently used key, a use counter is maintained for
 * each key in the cache. The key with the smallest use counter is the least
 * frequently used key.
 * 
 * When a key is first inserted into the cache, its use counter is set to 1
 * (due to the put operation). The use counter for a key in the cache is
 * incremented either a get or put operation is called on it.
 * 
 * The functions get and put must each run in O(1) average time complexity.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get",
 * "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
 * Output
 * [null, null, null, 1, null, -1, 3, null, -1, 3, 4]
 * 
 * Explanation
 * // cnt(x) = the use counter for key x
 * // cache=[] will show the last used order for tiebreakers (leftmost element
 * is  most recent)
 * LFUCache lfu = new LFUCache(2);
 * lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
 * lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
 * lfu.get(1);      // return 1
 * ⁠                // cache=[1,2], cnt(2)=1, cnt(1)=2
 * lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest,
 * invalidate 2.
 * // cache=[3,1], cnt(3)=1, cnt(1)=2
 * lfu.get(2);      // return -1 (not found)
 * lfu.get(3);      // return 3
 * ⁠                // cache=[3,1], cnt(3)=2, cnt(1)=2
 * lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate
 * 1.
 * ⁠                // cache=[4,3], cnt(4)=1, cnt(3)=2
 * lfu.get(1);      // return -1 (not found)
 * lfu.get(3);      // return 3
 * ⁠                // cache=[3,4], cnt(4)=1, cnt(3)=3
 * lfu.get(4);      // return 4
 * ⁠                // cache=[3,4], cnt(4)=2, cnt(3)=3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= capacity <= 10^4
 * 0 <= key <= 10^5
 * 0 <= value <= 10^9
 * At most 2 * 10^5 calls will be made to get and put.
 * 
 * 
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <list>
#include <unordered_map>

class LFUCache {
public:
    LFUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        // If key doesn't exist
        if (_keyToValFreq.find(key) == _keyToValFreq.end() ) {
            return -1;
        }
        increaseFreq(key);
        return _keyToValFreq[key].first;
    }
    
    void put(int key, int value) {
        if (_capacity <= 0) { return; }
        // if key exists
        if (_keyToValFreq.find(key) != _keyToValFreq.end() ) {
            _keyToValFreq[key].first = value;
            increaseFreq(key);
            return;
        }
        // if key doesn't exist
        // if reached hashmap's max capacity
        if (_keyToValFreq.size() >= _capacity) {
            int keyToRmove = _freqToKeyList[_minFreq].back();
            _freqToKeyList[_minFreq].pop_back();
            _keyToKeyListItr.erase(keyToRmove);
            _keyToValFreq.erase(keyToRmove);
        }
        addNewTask(key, value);
    }

    void increaseFreq(int key) {
        // Update the freq in the pair
        int oldFreq = _keyToValFreq[key].second++;
        
        // Detele the old freq by itr
        _freqToKeyList[oldFreq].erase(_keyToKeyListItr[key]);
        // Add the new freq and re-assign the itr
        _freqToKeyList[oldFreq + 1].emplace_front(key);
        _keyToKeyListItr[key] = _freqToKeyList[oldFreq + 1].begin();

        // Update minFreq
        if (_freqToKeyList[_minFreq].empty() ) {
            _minFreq = oldFreq + 1;
        }
    }

    void addNewTask(int key, int value) {
        // Add new key-value/freq to all hashmaps
        _minFreq = 1;
        _keyToValFreq[key] = std::make_pair(value, _minFreq);
        _freqToKeyList[_minFreq].emplace_front(key);
        _keyToKeyListItr[key] = _freqToKeyList[_minFreq].begin();
    }

private:
    int _capacity;
    int _minFreq;
    std::unordered_map<int, std::pair<int, int> > _keyToValFreq;
    std::unordered_map<int, std::list<int> > _freqToKeyList;
    std::unordered_map<int, std::list<int>::iterator> _keyToKeyListItr;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

// n = task number
// Time: O(1)
// Space: O(n)
