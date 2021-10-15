/*
 * @lc app=leetcode id=1169 lang=cpp
 *
 * [1169] Invalid Transactions
 *
 * https://leetcode.com/problems/invalid-transactions/description/
 *
 * algorithms
 * Medium (30.59%)
 * Likes:    220
 * Dislikes: 1232
 * Total Accepted:    32.9K
 * Total Submissions: 109.1K
 * Testcase Example:  '["alice,20,800,mtv","alice,50,100,beijing"]'
 *
 * A transaction is possibly invalid if:
 * 
 * 
 * the amount exceeds $1000, or;
 * if it occurs within (and including) 60 minutes of another transaction with
 * the same name in a different city.
 * 
 * 
 * You are given an array of strings transaction where transactions[i] consists
 * of comma-separated values representing the name, time (in minutes), amount,
 * and city of the transaction.
 * 
 * Return a list of transactions that are possibly invalid. You may return the
 * answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
 * Output: ["alice,20,800,mtv","alice,50,100,beijing"]
 * Explanation: The first transaction is invalid because the second transaction
 * occurs within a difference of 60 minutes, have the same name and is in a
 * different city. Similarly the second one is invalid too.
 * 
 * Example 2:
 * 
 * 
 * Input: transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
 * Output: ["alice,50,1200,mtv"]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
 * Output: ["bob,50,1200,mtv"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * transactions.length <= 1000
 * Each transactions[i] takes the form "{name},{time},{amount},{city}"
 * Each {name} and {city} consist of lowercase English letters, and have
 * lengths between 1 and 10.
 * Each {time} consist of digits, and represent an integer between 0 and
 * 1000.
 * Each {amount} consist of digits, and represent an integer between 0 and
 * 2000.
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <bits/stdc++.h>

class Solution {
public:
    struct hash_pair {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const
        {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
            return hash1 ^ hash2;
        }
    };
    
    typedef std::unordered_map<std::string, std::vector<int> > NameToTimeMap;
    typedef std::unordered_map<std::string, std::vector<std::string> > NameToCityMap;
    typedef std::unordered_map<std::pair<std::string, int>, int, hash_pair> IdxToTransIdxMap;
    typedef std::unordered_map<int, int> IdxToAmountMap;

    std::vector<std::string> invalidTransactions(std::vector<std::string>& transactions) {
        // Extract tarnsactions
        NameToTimeMap nameToTimes;
        NameToCityMap nameToCities;
        IdxToTransIdxMap idxToTransIdx;
        IdxToAmountMap idxToAmount;

        std::vector<std::string> parsedTrans;
        std::string name;
        for (unsigned int i = 0; i < transactions.size(); ++i) {
            parsedTrans = parseTransaction( transactions[i] );
            name = parsedTrans[0];
            nameToTimes[name].push_back( std::stoi(parsedTrans[1]) );
            nameToCities[name].push_back( parsedTrans[3] );
            idxToTransIdx[ {name, nameToTimes[name].size() - 1} ] = i;
            idxToAmount[i] = std::stoi(parsedTrans[2]);
        }

        // Find invalid transactions
        std::unordered_set<int> invalidTransIndex; 
        
        // Check time and city
        NameToTimeMap::iterator itr = nameToTimes.begin();
        for ( ; itr != nameToTimes.end(); ++itr) {
            std::string name = itr->first;
            for (unsigned int i = 0; i < itr->second.size(); ++i) {
                for (unsigned int j = 0; j < itr->second.size(); ++j) {
                    if (i != j && std::abs(itr->second[j] - itr->second[i]) <= 60 
                        && nameToCities[name][j].compare( nameToCities[name][i] ) != 0) {
                        invalidTransIndex.insert( idxToTransIdx[{name, i}] );
                        invalidTransIndex.insert( idxToTransIdx[{name, j}] );
                    }
                }
            }
        }
        // Check amount
        IdxToAmountMap::iterator amountItr = idxToAmount.begin();
        for ( ; amountItr != idxToAmount.end(); ++amountItr) {
            if (amountItr->second > 1000) {
                invalidTransIndex.insert(amountItr->first);
            }
        }
        
        // Output transactions
        std::vector<std::string> invalidTransStr;
        for (unsigned int idx : invalidTransIndex) {
            invalidTransStr.push_back(transactions[idx]);
        }
        return invalidTransStr;
    }
    
private:
    // Helper: parse the transaction
    std::vector<std::string> parseTransaction(const std::string& transaction) {
        std::stringstream ss(transaction);
        std::vector<std::string> parsedTransaction;
        while ( ss.good() ) {
            std::string substr;
            std::getline(ss, substr, ',');
            parsedTransaction.push_back(substr);
        }
        return parsedTransaction;
    }
};
// @lc code=end

// n = transaction number, m = max number of transactoins with same name
// Time: O(n^2)
// Space: O(n^2)
