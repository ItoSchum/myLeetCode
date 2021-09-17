/*
 * @lc app=leetcode id=432 lang=cpp
 *
 * [432] All O`one Data Structure
 *
 * https://leetcode.com/problems/all-oone-data-structure/description/
 *
 * algorithms
 * Hard (33.60%)
 * Likes:    881
 * Dislikes: 114
 * Total Accepted:    44.9K
 * Total Submissions: 130.9K
 * Testcase Example:  '["AllOne","inc","inc","getMaxKey","getMinKey","inc","getMaxKey","getMinKey"]\n' +
  '[[],["hello"],["hello"],[],[],["leet"],[],[]]'
 *
 * Design a data structure to store the strings' count with the ability to
 * return the strings with minimum and maximum counts.
 * 
 * Implement the AllOne class:
 * 
 * 
 * AllOne() Initializes the object of the data structure.
 * inc(String key) Increments the count of the string key by 1. If key does not
 * exist in the data structure, insert it with count 1.
 * dec(String key) Decrements the count of the string key by 1. If the count of
 * key is 0 after the decrement, remove it from the data structure. It is
 * guaranteed that key exists in the data structure before the decrement.
 * getMaxKey() Returns one of the keys with the maximal count. If no element
 * exists, return an empty string "".
 * getMinKey() Returns one of the keys with the minimum count. If no element
 * exists, return an empty string "".
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey",
 * "getMinKey"]
 * [[], ["hello"], ["hello"], [], [], ["leet"], [], []]
 * Output
 * [null, null, null, "hello", "hello", null, "hello", "leet"]
 * 
 * Explanation
 * AllOne allOne = new AllOne();
 * allOne.inc("hello");
 * allOne.inc("hello");
 * allOne.getMaxKey(); // return "hello"
 * allOne.getMinKey(); // return "hello"
 * allOne.inc("leet");
 * allOne.getMaxKey(); // return "hello"
 * allOne.getMinKey(); // return "leet"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= key.length <= 10
 * key consists of lowercase English letters.
 * It is guaranteed that for each call to dec, key is existing in the data
 * structure.
 * At most 5 * 10^4 calls will be made to inc, dec, getMaxKey, and getMinKey.
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <map>
#include <unordered_map>
#include <list>

class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {

    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(std::string key) {
        if (strToFreq.find(key) == strToFreq.end()) {
            strToFreq[key] = 1;
        } else {
            removeStrFromFreqList(key);
            strToFreq[key] += 1;
        }
        addStrToFreqList(key);
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(std::string key) {
        if (strToFreq.find(key) == strToFreq.end()) {
            return;
        }
        if (strToFreq[key] == 1) {
            removeStrFromFreqList(key);
            strToFreq.erase(key);
            strToListItr.erase(key);
        } else {
            removeStrFromFreqList(key);
            strToFreq[key] -= 1;
            addStrToFreqList(key);
        }
    }
    
    /** Returns one of the keys with maximal value. */
    std::string getMaxKey() {
        if (freqToStrList.size() == 0) { return ""; }
        std::list<std::string>::iterator itr;
        itr = ( freqToStrList.rbegin()->second ).begin();
        return *itr;
    }
    
    /** Returns one of the keys with Minimal value. */
    std::string getMinKey() {
        if (freqToStrList.size() == 0) { return ""; }
        std::list<std::string>::iterator itr;
        itr = (freqToStrList.begin()->second).begin();
        return *itr;
    }

private:
    std::map<int, std::list<std::string> > freqToStrList;
    std::unordered_map<std::string, int> strToFreq;
    std::unordered_map<std::string, std::list<std::string>::iterator> strToListItr;

    void removeStrFromFreqList(std::string key) {
        int freq = strToFreq[key];
        freqToStrList[freq].erase(strToListItr[key]);
        if (freqToStrList[freq].size() == 0) {
            freqToStrList.erase(freq);
        }
    }

    void addStrToFreqList(std::string key) {
        int freq = strToFreq[key];
        freqToStrList[freq].push_front(key);
        strToListItr[key] = freqToStrList[freq].begin();
    }

    void printStatus() {
        std::cout << "a freq: " << strToFreq.count("a") << std::endl;
        std::cout << "b freq: " << strToFreq.count("b") << std::endl;
        std::map<int, std::list<std::string> >::iterator itr;
        std::list<std::string>::iterator list_itr;
        for (itr = freqToStrList.begin(); itr != freqToStrList.end(); ++itr) {
            std::cout << "Freq = " << itr->first << ": " ;
            for (list_itr = (itr->second).begin(); list_itr != (itr->second).end(); ++list_itr) {
                std::cout << *list_itr << " ";
            }
            std::cout << std::endl;
        }
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end

// n = string number
// Time: O( nlog2(n) )
// Space: O(n)

