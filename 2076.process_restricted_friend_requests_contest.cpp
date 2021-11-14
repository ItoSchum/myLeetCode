#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<bool> friendRequests(int n, std::vector<std::vector<int>>& restrictions, std::vector<std::vector<int>>& requests) {
        for (int i = 0; i < restrictions.size(); ++i) {
            notAllowedMap[ restrictions[i][0] ].push_back(restrictions[i][1]);
            notAllowedMap[ restrictions[i][1] ].push_back(restrictions[i][0]);
        }
        
        std::vector<int> checkedList;
        std::vector<bool> results;
        for (int i = 0; i < requests.size(); ++i) {
            // If restriction exists
            if (checkIfNotAllowed(requests[i][0], requests[i][1]) == true) { 
                results.push_back(false);
                continue; 
            }
            // If no restriction
            relationMap[ requests[i][0] ].push_back(requests[i][1]);
            relationMap[ requests[i][1] ].push_back(requests[i][0]);
            results.push_back(true);
            
            printRelation();
        }
        return results;
    }
    
    bool checkIfNotAllowed(int source, int target) {
        // std::cout << "CHECK NOT ALLOWED" << std::endl;
        // If no restriction
        if (notAllowedMap.count(source) == 0) {
            return false;
        }
        // If restriction exists
        std::vector<int> restrictions = notAllowedMap[source];
        if (std::find(restrictions.begin(), restrictions.end(), target) != restrictions.end() ) {
            return true;
        }
        // Otherwise, iterate target person's friends
        std::vector<int> checkedList = { source };
        for (int personNotAllowed : notAllowedMap[source]) {
            if (checkFriendRelation(personNotAllowed, target, checkedList) == true) { return true; }
        }
        
        for (int oneFriend : relationMap[source]) {
            if (checkIfNotAllowed(oneFriend, target) == true) { return true; }
        }
        return false;
    }
    
    bool checkFriendRelation(int source, int target, std::vector<int>& checkedList) {
        // std::cout << "CHECK FRIENDSHIP" << std::endl;
        
        checkedList.push_back(source);
        for (int oneFriend : relationMap[source]) {
            // If already checked that person
            if (std::find(checkedList.begin(), checkedList.end(), oneFriend) != checkedList.end() ) {
                continue;
            }
            // If direct friends
            if (oneFriend == target) { return true; }
            // If indirect friends
            if (checkFriendRelation(oneFriend, target, checkedList) == true) { return true; }
        }
        checkedList.pop_back();
        return false;
    } 
    
    void printRelation() {
        for (const auto& record : relationMap) {
            std::cout << "Friends of " << record.first << ": ";
            for (auto person : record.second) { std::cout << person << " "; }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
        
private:
    std::unordered_map<int, std::vector<int> > notAllowedMap;
    std::unordered_map<int, std::vector<int> > relationMap;
};