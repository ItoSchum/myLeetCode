#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

class Leaderboard {
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        playerIdToScore[playerId] += score;
    }
    
    int top(int K) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pqScore;
        std::unordered_map<int, int>::iterator itr = playerIdToScore.begin();
        // Push all number into priority queue, pop out the smaller (N - K) ones
        for (; itr != playerIdToScore.end(); ++itr) {
            pqScore.push( itr->second );
            if (pqScore.size() > K) {
                pqScore.pop();
            }
        }
        // Pop out the first K numbers
        int topKSum = 0;
        while (pqScore.size() > 0) {
            topKSum += pqScore.top();
            pqScore.pop();
        }
        return topKSum;
    }
    
    void reset(int playerId) {
        playerIdToScore.erase(playerId);
    }
    
private:
    std::unordered_map<int, int> playerIdToScore;
};

// N = player number, K = top K
// Time: addScore: O(1), top: O(N + NlogK), reset: O(1)
// Space: O(n)