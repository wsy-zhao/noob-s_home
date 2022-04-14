#include "../utils/utils.h"
#include <numeric>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = -1;
        for (vector<int> & account : accounts){
            ans = max(ans, accumulate(account.begin(), account.end(), 0));
        }
        // for_each(accounts.begin(), accounts.end(), [&ans](vector<int> &account){ ans = max(ans, accumulate(account.begin(), account.end(), 0)); });
        return ans;
    }
};