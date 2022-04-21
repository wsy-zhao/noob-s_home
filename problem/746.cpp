#include "../utils/utils.h"
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        long first = 0, second = 0;
        int size = cost.size();
        for(int i = 2; i < size; ++i){
            int tmp = second;
            second = min(cost[i - 1] + second, cost[i - 2] + first);
            first = tmp;
        }
        return min(cost[size - 1] + second, cost[size - 2] + first);
    }
};