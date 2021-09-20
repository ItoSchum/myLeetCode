/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 *
 * https://leetcode.com/problems/design-hashmap/description/
 *
 * algorithms
 * Easy (63.97%)
 * Likes:    1871
 * Dislikes: 206
 * Total Accepted:    216.4K
 * Total Submissions: 338.8K
 * Testcase Example:  '["MyHashMap","put","put","get","get","put","get","remove","get"]\n' +
  '[[],[1,1],[2,2],[1],[3],[2,1],[2],[2],[2]]'
 *
 * Design a HashMap without using any built-in hash table libraries.
 * 
 * Implement the MyHashMap class:
 * 
 * 
 * MyHashMap() initializes the object with an empty map.
 * void put(int key, int value) inserts a (key, value) pair into the HashMap.
 * If the key already exists in the map, update the corresponding value.
 * int get(int key) returns the value to which the specified key is mapped, or
 * -1 if this map contains no mapping for the key.
 * void remove(key) removes the key and its corresponding value if the map
 * contains the mapping for the key.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
 * [[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
 * Output
 * [null, null, null, 1, -1, null, 1, null, -1]
 * 
 * Explanation
 * MyHashMap myHashMap = new MyHashMap();
 * myHashMap.put(1, 1); // The map is now [[1,1]]
 * myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
 * myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
 * myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1],
 * [2,2]]
 * myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the
 * existing value)
 * myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
 * myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
 * myHashMap.get(2);    // return -1 (i.e., not found), The map is now
 * [[1,1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= key, value <= 10^6
 * At most 10^4 calls will be made to put, get, and remove.
 * 
 * 
 */

// @lc code=start
#include <list>
#include <vector>

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        keyToLists.resize(mapSize);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int pos = hash(key);
        std::list<std::pair<int, int> >::iterator itr = findItrInList(key);
        
        // If not exist such key
        if (itr == keyToLists[pos].end() ) {    
            keyToLists[pos].push_back({key, value});
        } 
        // If already exist, update value
        else {
            itr->second = value;
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int pos = hash(key);
        if (keyToLists[pos].size() == 0) {
            return -1;
        }
        std::list<std::pair<int, int> >::iterator itr = findItrInList(key);
        if (itr != keyToLists[pos].end() ) {
            return itr->second;
        } 
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int pos = hash(key);
        if (keyToLists[pos].size() == 0) {
            return;
        }
        std::list<std::pair<int, int> >::iterator itr = findItrInList(key);
        if (itr != keyToLists[pos].end() ) {
            keyToLists[pos].erase(itr);
            return;
        }
        
    }

private:
    std::vector<std::list<std::pair<int, int> > > keyToLists;
    int mapSize = 10000;

    int hash(int key) {
        return key % mapSize;
    }

    std::list<std::pair<int, int> >::iterator findItrInList(int key) {
        int position = hash(key);
        std::list<std::pair<int, int> >::iterator itr;
        for (itr = keyToLists[position].begin(); itr != keyToLists[position].end(); ++itr) {
            if (itr->first == key) { return itr; }
        }
        return keyToLists[position].end();
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

// n = map size, l = average length of the collision list
//        get  put  remove
// Time:  O(l) O(l) O(l)
// Space: O(n) O(n) O(n)

