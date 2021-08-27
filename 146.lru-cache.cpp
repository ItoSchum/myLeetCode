/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (36.93%)
 * Likes:    9739
 * Dislikes: 384
 * Total Accepted:    839.6K
 * Total Submissions: 2.2M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design a data structure that follows the constraints of a Least Recently
 * Used (LRU) cache.
 * 
 * Implement the LRUCache class:
 * 
 * 
 * LRUCache(int capacity) Initialize the LRU cache with positive size
 * capacity.
 * int get(int key) Return the value of the key if the key exists, otherwise
 * return -1.
 * void put(int key, int value) Update the value of the key if the key exists.
 * Otherwise, add the key-value pair to the cache. If the number of keys
 * exceeds the capacity from this operation, evict the least recently used
 * key.
 * 
 * 
 * The functions get and put must each run in O(1) average time complexity.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * Output
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 * 
 * Explanation
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // cache is {1=1}
 * lRUCache.put(2, 2); // cache is {1=1, 2=2}
 * lRUCache.get(1);    // return 1
 * lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
 * lRUCache.get(2);    // returns -1 (not found)
 * lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
 * lRUCache.get(1);    // return -1 (not found)
 * lRUCache.get(3);    // return 3
 * lRUCache.get(4);    // return 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= capacity <= 3000
 * 0 <= key <= 10^4
 * 0 <= value <= 10^5
 * At most 2 * 10^5 calls will be made to get and put.
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <list>
#include <unordered_map>


typedef std::unordered_map<int, std::list<std::pair<int, int> >::iterator > CacheMap;
typedef std::list<std::pair<int, int> > LRUList;

class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        CacheMap::iterator cache_itr = _cacheMap.find(key);
        if (cache_itr == _cacheMap.end() ) { 
            return -1; 
        }
        makeMostRecent(key, _cacheMap[key]->second);
        LRUList::iterator list_itr = _LRUList.end();
        --list_itr;
        return list_itr->second;
    }
    
    void put(int key, int value) {
        if (_cacheMap.find(key) != _cacheMap.end()) {
            makeMostRecent(key, value);
            return;
        }
        if (_LRUList.size() >= _capacity) {
            removeLeastRecentTask(key);
        }
        addMostRecentTask(key, value);
    }

private:
    void makeMostRecent(int key, int value) {
        _LRUList.erase(_cacheMap[key]);
        _LRUList.push_back(std::make_pair(key, value) );
        LRUList::iterator list_itr = _LRUList.end();
        _cacheMap[key] = --list_itr;
    }

    void removeLeastRecentTask(int key) {
        int keyToRemove = _LRUList.begin()->first;
        _LRUList.erase(_LRUList.begin());
        _cacheMap.erase(keyToRemove);
    }

    void addMostRecentTask(int key, int value) {
        _LRUList.push_back(std::make_pair(key, value) );
        LRUList::iterator list_itr = _LRUList.end();
        _cacheMap[key] = --list_itr;
    }

    int _capacity;
    LRUList _LRUList;
    CacheMap _cacheMap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

// n = task number of the LRU list
// Time: O(1)
// Space: O(n)

