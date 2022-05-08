#include "../utils/utils.h"
using namespace std;

/* Simulation
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i = 1; i <= n; ++i){
            q.emplace(i);
        }
        while (q.size() > 1){
            for(int i = 1; i < k; ++i){
                q.emplace(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};
*/

/* 
class Solution {
public:
    int findTheWinner(int n, int k){
        if (n == 1){
            return 1;
        }
        return (k + findTheWinner(n - 1, k) - 1) % n + 1;
    }
};
*/

class Solution{
public:
    int findTheWinner(int n, int k){
        int winner = 1;
        for(int i = 2; i <= n; ++i){
            winner = (k + winner - 1) % i + 1;
        }
        return winner;
    }
};